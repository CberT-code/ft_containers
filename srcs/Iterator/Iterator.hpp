#ifndef ITERATOR_H
#define ITERATOR_H

template <class T>

struct iterator_struct
{
	iterator_struct<T>		*prev;
	iterator_struct<T>		*next;
	T						element;
	int						inc;
};

#include "../Headers/Header.hpp"

#endif
