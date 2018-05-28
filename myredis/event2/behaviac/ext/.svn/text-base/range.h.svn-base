#ifndef _CORE_RANGE_H_
#define _CORE_RANGE_H_

#include "behaviac/base/dynamictype.h"

/*!
		Class TRange, can represent anything that is range between two values, mostly used for time ranges.
 */
template <class T>
class TRange
{
public:
    BEHAVIAC_DECLARE_MEMORY_OPERATORS(TRange)
    T start;
    T end;

    TRange()
    {
        start = 0;
        end = 0;
    };
    TRange(const TRange& r)
    {
        start = r.start;
        end = r.end;
    };
    TRange(T s, T e)
    {
        start = s;
        end = e;
    };

    void Set(T s, T e)
    {
        start = s;
        end = e;
    };
    void Clear()
    {
        start = 0;
        end = 0;
    };

    //! Get length of range.
    T	Length() const
    {
        return end - start;
    };
    //! Check if range is empty.
    bool IsEmpty()	const
    {
        return (start == 0 && end == 0);
    }

    //! Check if value is inside range.
    bool IsInside(T val)
    {
        return val >= start && val <= end;
    };

    //! Returns true if the two ranges overlap.
    bool Overlap(const TRange& r) const
    {
        TRange intersect(*this & r);
        return intersect.end >= intersect.start;
    }

    void ClipValue(T& val)
    {
        if (val < start)
        {
            val = start;
        }

        if (val > end)
        {
            val = end;
        }
    }

    //! Compare two ranges.
    bool	operator == (const TRange& r) const
    {
        return start == r.start && end == r.end;
    }
    //! Assign operator.
    TRange&	operator =(const TRange& r)
    {
        start = r.start;
        end = r.end;
        return *this;
    }
    //! Interect two ranges.
    TRange	operator & (const TRange& r) const
    {
        return TRange(TagMax(start, r.start), TagMin(end, r.end));
    }
    TRange&	operator &= (const TRange& r)
    {
        return (*this = (*this & r));
    }
    //! Concatent two ranges.
    TRange	operator | (const TRange& r) const
    {
        return TRange(TagMin(start, r.start), TagMax(end, r.end));
    }
    TRange&	operator |= (const TRange& r)
    {
        return (*this = (*this | r));
    }
    //! Add new value to range.
    TRange	operator + (T v) const
    {
        T s = start, e = end;

        if (v < start)
        {
            s = v;
        }

        if (v > end)
        {
            e = v;
        }

        return TRange(s, e);
    }
    //! Add new value to range.
    TRange&	operator += (T v)
    {
        if (v < start)
        {
            start = v;
        }

        if (v > end)
        {
            end = v;
        }

        return *this;
    }
};

//! CRange if just TRange for floats..
typedef TRange<float> Range;

BEHAVIAC_OVERRIDE_TYPE_NAME(Range);


#endif // #ifndef _CORE_RANGE_H_
