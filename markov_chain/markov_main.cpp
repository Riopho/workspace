#include <iostream>
#include <map>
#include <utility>
#include <string>
#include <list>
#include <vector>
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
                return new Mar_Chain();
            }
        }
        
        void Init(char *szBuffer, size_t buff_len);
    private:
        StateMap _stateMap;

        static Mar_Chain *_instance;

        vector<string> _strAry;

        void _addToMap(string pre1, string pre2, const string suffix);

        void _parser(char *szBuffer, size_t buff_len);
};

void Mar_Chain::_addToMap(string pre1, string pre2, const string suffix)
{
    StateMap::iterator iter1, iter2; 
    make_pair(iter1, iter2) = _stateMap.equal_range(pre1);

    //map中没有此prefix1
    if (iter1 == iter2)
    {
        State *newOne = new State(pre1, pre2); 
        newOne->_list.push_back(suffix);
        _stateMap.insert(make_pair(pre1, *newOne));
    }
    else
    {
        for(; iter1 != iter2; ++iter1)
        {
            if (pre2 == iter1->second._prefix2)
            {
                iter1->second._list.push_back(suffix);
                break;
            }
        }

        //prefix2不存在
        if (iter1 == iter2)
        {
            //在prefix1中，无prefix2
            State *newOne = new State(pre1, pre2); 
            newOne->_list.push_back(suffix);
            _stateMap.insert(make_pair(pre1, *newOne));
        }
    }
}

void Mar_Chain::_parser(char *szBuffer, size_t buff_len)
{
    size_t i = 0;
    while (' '!= *(szBuffer + i) && i < buff_len)
    {
       ++i; 
    }

    if (i == buff_len)
    {
        return;
    } 

    _strAry.push_back(string(szBuffer, szBuffer + i -1)); 
    _parser(szBuffer + i + 1, buff_len - i - 1);
}

void Mar_Chain::Init(char *szBuffer, size_t buff_len)
{
    _parser(szBuffer, buff_len);      
}

int main()
{
   char szInput[2048] = {"Vim is the best text editor in the word."}; 
   Mar_Chain::Instance()->Init(szInput, sizeof(szInput));
   return 0;
}
