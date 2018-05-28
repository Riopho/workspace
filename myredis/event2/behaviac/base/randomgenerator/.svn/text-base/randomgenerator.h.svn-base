#ifndef _BEHAVIAC_BASE_RANDOMGENERATOR_H_
#define _BEHAVIAC_BASE_RANDOMGENERATOR_H_
#include "behaviac/base/base.h"

//#define _SYS_RANDOM_	1

#if _SYS_RANDOM_
#include <stdlib.h>
#endif//#if _SYS_RANDOM_

namespace behaviac
{
	class RandomGenerator
	{
	public:
		static RandomGenerator* GetInstance()
		{
			RandomGenerator* pRandomGenerator = RandomGenerator::_GetInstance();

			return pRandomGenerator;
		}

		//[0, 1)
		float operator()()
		{
			return this->random();
		}

		//[low, high)
		template <typename T>
		float InRange(T low, T high)
		{
			float r = (*this)();
			float ret = r * (high - low) + low;
			return ret;
		}

		void setSeed(unsigned int seed)
		{
			this->m_seed = seed;
#if _SYS_RANDOM_
			srand(seed);
#endif//#if _SYS_RANDOM_
		}
	protected:
		RandomGenerator(unsigned int seed = 0) : m_seed(seed) 
		{
			RandomGenerator::_SetInstance(this);
		}

		virtual ~RandomGenerator()
		{}

	private:
		static RandomGenerator* ms_pInstance;
		static void _SetInstance(RandomGenerator* pInstance);
		static RandomGenerator* _GetInstance();

		//[0, 1)
		virtual float random()
		{
#if _SYS_RANDOM_
			int v = rand();
			float r = v / (float)RAND_MAX;
#else
			m_seed = 214013 * m_seed + 2531011;
			float r = (m_seed * (1.0f / 4294967296.0f));
#endif//_SYS_RANDOM_

			BEHAVIAC_ASSERT(behaviac::InRange(r, 0.0f, 1.0f));
			return r;
		}

		unsigned int m_seed;
	};
}//namespace behaviac

#endif//_BEHAVIAC_BASE_RANDOMGENERATOR_H_