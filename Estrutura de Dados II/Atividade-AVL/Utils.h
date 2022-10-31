// Utils.h
#ifndef __UTILS_H__
#define __UTILS_H__

namespace Utils
{
	template <typename T>
	static T Max(T l, T r)
	{
		return (l > r) ? l : r;
	}
}

#endif