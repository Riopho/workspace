#ifndef _CORE_TIMEUTILS_H_
#define _CORE_TIMEUTILS_H_

#include <time.h>

namespace TimeUtils
{
	inline time_t TimeZoneOffset()
	{
		time_t dummy_time = 0;
		return mktime(localtime(&dummy_time)) - mktime(gmtime(&dummy_time));
	}

	inline time_t GMTToLocal(time_t gmt_time)
	{
		return gmt_time + TimeZoneOffset();
	}

	inline time_t LocalToGMT(time_t gmt_time)
	{
		return gmt_time - TimeZoneOffset();
	}

	inline tm GMTToLocal(const tm& gmt_tm)
	{
		tm tmp_tm = gmt_tm;
		time_t tmp_time = GMTToLocal(mktime(&tmp_tm));
		return *localtime(&tmp_time);
	}

	inline tm LocalToGMT(const tm& local_tm)
	{
		tm tmp_tm = local_tm;
		time_t tmp_time = LocalToGMT(mktime(&tmp_tm));
		return *localtime(&tmp_time);
	}

	inline void GetLocalTime(tm& local_tm)
	{
		time_t tmp = time(NULL);
		local_tm = *localtime(&tmp);
	}

	inline void GetGMTTime(tm& gmt_tm)
	{
		time_t tmp = time(NULL);
		gmt_tm = *gmtime(&tmp);
	}
}

#endif //_CORE_TIMEUTILS_H_
