#ifndef FORWARDITERATOR_H
#define FORWARDITERATOR_H

#include "./Iterator.hpp"

template <typename T>
struct ForwardIterator : public InputIterator<T>
{
	public :
		/**************************************************
		****************** Form Coplien *******************
		**************************************************/
		ForwardIterator(void){}

};

#endif
