#include <iostream>
#include <map>
#include <utility>
#include <string>
#include <list>
#include <vector>
#include <cstdlib>
#include <cassert>
#include <cstdio>
#include <fstream>

using namespace std;

typedef list<string> KeyList;

struct State
{
    State(string &pre1, string &pre2):_prefix1(pre1), _prefix2(pre2)
    {
        ;
    }
    string _prefix1;
    string _prefix2;
    KeyList _list;
};

//prefx1 -> state* 的一对多multimap
typedef multimap<string ,State> StateMap;

class Mar_Chain
{
    public:
        Mar_Chain()
        {

        }

        ~Mar_Chain()
        {
            delete _instance;
        }

        static Mar_Chain* Instance()
        {
            if (_instance)
            {
                return _instance;  
            }
            else
            {
                _instance = new Mar_Chain();
                return _instance;
            }
        }
        
        void Init(char *szBuffer, int buff_len);

        vector<string> _strAry;

        void GenRandomArticle(int &work_count);

        void GenKeyWordMap();

        vector<string> randomAry;
		string GetRandomWord(KeyList &list);
        void TestWordMap();
    private:
        StateMap _stateMap;

        static Mar_Chain *_instance;


        void _addToMap(string &pre1, string &pre2, string &suffix);

        void _parser(char *szBuffer, int buff_len);

};

Mar_Chain* Mar_Chain::_instance = NULL;

void Mar_Chain::_addToMap(string &pre1, string &pre2, string &suffix)
{
    pair<StateMap::iterator, StateMap::iterator> equal_pair= _stateMap.equal_range(pre1);
    //cout << "pre1:" << pre1 << " " << "pre2:" << pre2 << " " << "suffix:" << suffix<< endl;
    //map中没有此prefix1
    if (equal_pair.first == equal_pair.second)
    {
        State *newOne = new State(pre1, pre2); 
        newOne->_list.push_back(suffix);
        _stateMap.insert(make_pair(pre1, *newOne));
    }
    else
    {
        for(; equal_pair.first != equal_pair.second; ++equal_pair.first)
        {
            if (pre2 == equal_pair.first->second._prefix2)
            {
                equal_pair.first->second._list.push_back(suffix);
                break;
            }
        }

        //prefix2不存在
        if (equal_pair.first == equal_pair.second)
        {
            //在prefix1中，无prefix2
            State *newOne = new State(pre1, pre2); 
            newOne->_list.push_back(suffix);
            _stateMap.insert(make_pair(pre1, *newOne));
        }
    }
}

inline void StringFilter(string &raw)
{
	size_t n = raw.find_last_not_of(" \r\n\t");
	if(n != string::npos)
	{
		raw.erase(n + 1 , raw.size() - n);
	}
	  
	n = raw.find_first_not_of (" \r\n\t");
	if(n != string::npos)
	{
		raw.erase( 0 , n );
	} 
}

void Mar_Chain::TestWordMap()
{
    StateMap::iterator iter = _stateMap.begin();     
    for (;iter != _stateMap.end(); ++iter)
    {
        cout <<"------------------------------------------"<<endl;
        cout <<"key word: " << iter->first << endl;
        cout <<"first word: "<< iter->second._prefix1 << endl;
        cout <<"second word: "<< iter->second._prefix2 << endl;

        for (KeyList::iterator iter2 = iter->second._list.begin(); iter2 != iter->second._list.end(); ++iter2)
        {
            cout <<"list_word: " <<*iter2 << endl;
        }
        cout <<"------------------------------------------"<<endl;
    }
}

void Mar_Chain::_parser(char *szBuffer, int buff_len)
{
    int i = 0;
    while ((' '!= *(szBuffer + i)) && (i < buff_len))
    {
       ++i; 
    }

    if (i == buff_len)
    {
        string tmp(szBuffer, szBuffer + i);
        StringFilter(tmp);
        _strAry.push_back(tmp);
        return;
    } 
	string tmp(szBuffer, szBuffer + i);
	StringFilter(tmp);
    _strAry.push_back(tmp); 
    _parser(szBuffer + i + 1, buff_len - i - 1);
}

void Mar_Chain::GenKeyWordMap()
{
   if (2 >= _strAry.size())
   {
        return;
   } 

   vector<string>::iterator pre1_iter = _strAry.begin();
   vector<string>::iterator pre2_iter = pre1_iter + 1;
   vector<string>::iterator pre3_iter = pre2_iter + 1;

   while (pre3_iter != _strAry.end())
   {
       _addToMap(*pre1_iter, *pre2_iter, *pre3_iter); 
       ++pre1_iter;
       ++pre2_iter;
       ++pre3_iter;
   } 
}

void Mar_Chain::Init(char *szBuffer, int buff_len)
{
    _parser(szBuffer, buff_len);      
    GenKeyWordMap();
}

inline int randomX(unsigned int x)
{
  return rand() % x;  
}

string Mar_Chain::GetRandomWord(KeyList &list)
{
	KeyList::iterator iter = list.begin();
    int size = list.size();
    int bound = randomX(size); 
	for(int i = 0; i < bound; ++i)
	{
		++iter;
	}
	return *iter;
	
}

void Mar_Chain::GenRandomArticle(int &word_count)
{
   //找到第一个词
   string first_word = _strAry[0];
   string second_word;
   int  i = 0;
   while (i < word_count)
   {
       pair<StateMap::iterator, StateMap::iterator> resultPair;

       resultPair = _stateMap.equal_range(first_word);
       if (resultPair.first != resultPair.second)
       {
           //第一次把前面A1 A2插入 之后循环只需插入一个词
           if (0 == i)
           {
                randomAry.push_back(resultPair.first->second._prefix1);
                randomAry.push_back(resultPair.first->second._prefix2);

				string tmp = GetRandomWord(resultPair.first->second._list);
                randomAry.push_back(tmp); 
				first_word = resultPair.first->second._prefix2;
                second_word = tmp;
           }
           else
           {
               
               StateMap::iterator iter = resultPair.first;
               while(iter != resultPair.second)
               {
                    if (iter->second._prefix2 == second_word)
                    {
                        string tmp2 = GetRandomWord(iter->second._list); 
                        randomAry.push_back(tmp2);
                        first_word = second_word;
                        second_word = tmp2;
                        break;
                    }
                    ++iter;
               }

               //if (iter == resultPair.second)
               //{
                   //cout << "first_word: " << first_word << endl;
                   //cout << "second_word: " << second_word << endl; 
                   //cout << "key word: "<< iter->first << endl;
               //}
           }
       }
       //first_word = resultPair.first->second._prefix2;
       ++i;
   } 
}

int main()
{
	ifstream t;  
	int length;  
	t.open("warden.txt");      // open input file  

	t.seekg(0, std::ios::end);    // go to the end  
	length = t.tellg();           // report location (this is the length)  
	t.seekg(0, std::ios::beg);    // go back to the beginning  

	char *buffer = new char[length];    // allocate memory for a buffer of appropriate dimension  
	t.read(buffer, length);       // read the whole file into the buffer  
	t.close();   

	Mar_Chain::Instance()->Init(buffer, length);

    for (size_t i = 0; i < Mar_Chain::Instance()->_strAry.size(); ++i)
    {
        //cout << Mar_Chain::Instance()->_strAry[i] << endl;
    }

    int count = 100;
	Mar_Chain::Instance()->GenRandomArticle(count);

    //Mar_Chain::Instance()->TestWordMap();

	for (size_t i = 0; i < Mar_Chain::Instance()->randomAry.size(); ++i)
	{
        cout << Mar_Chain::Instance()->randomAry[i] << " ";
	}

	return 0;
}
