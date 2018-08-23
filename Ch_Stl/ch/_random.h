#pragma once
#ifndef _KO_RANDOM_H_INCLUDED
#define _KO_RANDOM_H_INCLUDED
#endif // 

#include <assert.h>

template <unsigned _SIZE>
class  __ch_random_generator
{
	enum gen{ _C_SIZE = _SIZE };

	unsigned long    _C_table[_C_SIZE];
	unsigned int _C_index1;
	unsigned int _C_index2;

public:

	__ch_random_generator(unsigned long __seed = 161803398) {
		seed(__seed);
	}

	void seed(unsigned long __seed);

	unsigned long operator() (unsigned long __limit);

	static unsigned long generate(unsigned long __limit);
};


template <unsigned _SIZE>
inline unsigned long
__ch_random_generator<_SIZE>::operator() (unsigned long __limit)
{
	assert(0 != __limit);

	_C_table[++_C_index1 %= _C_SIZE] -= _C_table[++_C_index2 %= _C_SIZE];

	return _C_table[_C_index1] % __limit;
}


template <unsigned _SIZE>
inline unsigned long
__ch_random_generator<_SIZE>::generate(unsigned long __limit)
{
	//_RWSTD_MT_STATIC_GUARD(__guard);

	static __ch_random_generator __gen;

	return __gen(__limit);
}


template <class _Distance>
inline _Distance __ch_random(_Distance __limit)
{
	return __ch_random_generator<55>::generate(__limit);
}

template <unsigned _SIZE>
void __ch_random_generator<_SIZE>::seed(unsigned long __seed)
{
	unsigned long __k = 1;

	_C_table[_C_SIZE - 1] = __seed;

	int __i;

	for (__i = 0; __i != _C_SIZE - 1; ++__i) {
		int __ii = 21 * __i % _C_SIZE;
		_C_table[__ii] = __k;
		__k = __seed - __k;
		__seed = _C_table[__ii];
	}

	for (__i = 0; __i != 4; ++__i) {
		for (int __ii = 0; __ii != _C_SIZE; ++__ii)
			_C_table[__i] =
			_C_table[__i] - _C_table[(__i + 31) % _C_SIZE];
	}

	_C_index1 = 0U;
	_C_index2 = _C_SIZE * 2UL / 3UL - 1UL;
}


