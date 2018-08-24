#pragma once
#if 0
template <class _TypeT>
inline bool operator!= (const _TypeT& __x, const _TypeT& __y)
{
	return !(__x == __y);
}

template <class _TypeT>
inline bool operator> (const _TypeT& __x, const _TypeT& __y)
{
	return __y < __x;
}

template <class _TypeT>
inline bool operator<= (const _TypeT& __x, const _TypeT& __y)
{
	return !(__y < __x);
}

template <class _TypeT>
inline bool operator>= (const _TypeT& __x, const _TypeT& __y)
{
	return !(__x < __y);
}

#endif

					   // 20.2.2
template <class _TypeT, class _TypeU>
struct pair
{
	typedef _TypeT first_type;
	typedef _TypeU second_type;

	first_type  first;
	second_type second;

	pair(const first_type &__x, const second_type &__y)
		: first(__x), second(__y) { }

	pair()
		: first(/* lwg issue 265 */), second() { }

	pair(const pair &__rhs) : first(__rhs.first), second(__rhs.second) { }

	template <class _TypeX, class _TypeY>
	pair(const pair <_TypeX, _TypeY> &__rhs)
		: first(__rhs.first), second(__rhs.second) { }

};


template <class _TypeT, class _TypeU>
inline bool
operator== (const pair<_TypeT, _TypeU>& __x, const pair<_TypeT, _TypeU>& __y)
{
	return __x.first == __y.first && __x.second == __y.second;
}


template <class _TypeT, class _TypeU>
inline bool
operator!= (const pair<_TypeT, _TypeU>& __x, const pair<_TypeT, _TypeU>& __y)
{
	return !(__x == __y);
}


template <class _TypeT, class _TypeU>
inline bool
operator< (const pair<_TypeT, _TypeU>& __x, const pair<_TypeT, _TypeU>& __y)
{
	return    __x.first < __y.first
		|| (!(__y.first < __x.first) && __x.second < __y.second);
}


template <class _TypeT, class _TypeU>
inline bool
operator> (const pair<_TypeT, _TypeU>& __x, const pair<_TypeT, _TypeU>& __y)
{
	return __y < __x;
}


template <class _TypeT, class _TypeU>
inline bool
operator>= (const pair<_TypeT, _TypeU>& __x, const pair<_TypeT, _TypeU>& __y)
{
	return !(__x < __y);
}


template <class _TypeT, class _TypeU>
inline bool
operator<= (const pair<_TypeT, _TypeU>& __x, const pair<_TypeT, _TypeU>& __y)
{
	return !(__y < __x);
}


template <class _TypeT, class _TypeU>
inline pair<_TypeT, _TypeU>
make_pair(const _TypeT &__x, const _TypeU &__y)
{
	return pair<_TypeT, _TypeU>(__x, __y);
}


