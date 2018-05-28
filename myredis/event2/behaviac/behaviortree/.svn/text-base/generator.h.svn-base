#ifndef __GENERATOR_H__
#define __GENERATOR_H__

//http://www.codeproject.com/Articles/29524/Generators-in-C

// generator/continuation for C++
// author: Andrew Fedoniouk @ terrainformatica.com
// idea borrowed from: "coroutines in C" Simon Tatham,
//   http://www.chiark.greenend.org.uk/~sgtatham/coroutines.html

/*
void generator_test()
{
	$generator(descent)
	{
		// place for all variables used in the generator
		int i; // our counter

		// place the constructor of our generator, e.g. 
		// descent(int minv, int maxv) {...}

		// from $emit to $stop is a body of our generator:

		$emit(int) // will emit int values. Start of body of the generator.
			for (i = 10; i > 0; --i)
			{
				CHECK_EQUAL(1, 1);
				$yield(i); // a.k.a. yield in Python,
			}
			// returns next number in [1..10], reversed.
		$stop; // stop, end of sequence. End of body of the generator.
	};

	descent gen;
	for(int n; gen(n);) // "get next" generator invocation
	{
	}
}
*/

struct _generator
{
  int _line;
  _generator():_line(0) {}
};

#define $generator(NAME) struct NAME : public _generator

#define $emit(T) bool operator()(T& _rv) { \
                    switch(_line) { case 0:;

#define $stop  } _line = 0; return false; }

#define $yield(V)     \
        do {\
            _line=__LINE__;\
            _rv = (V); return true; case __LINE__:;\
        } while (0)

#endif//__GENERATOR_H__
