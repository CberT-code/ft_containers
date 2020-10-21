
#ifndef FORWARDITERATOR_H
#define FORWARDITERATOR_H

#include "./Iterator.hpp"

template <typename T>
struct ForwardIterator
{
	public:

	/**************************************************
	****************** Form Coplien *******************
	**************************************************/

	ForwardIterator(void){}

	ForwardIterator(ForwardIterator const &src){
		operator=(src);
	}
	ForwardIterator &	operator=( ForwardIterator const &src){
		if (this != &src)
			*this = src;
		return (this);
	}
	virtual ~ForwardIterator(void){}
	
	/**************************************************
	*************** operator '==' '!=' ****************
	**************************************************/
	bool					operator==(const ForwardIterator &src) const{
		if (*src == *this)
			return (true);
		return (false);
	}
	bool					operator!=(const ForwardIterator &src) const{
		return (!operator=(src));
	}

	/**************************************************
	************* operator '*a' 'a->m' ****************
	**************************************************/
	T							&operator*(void){
		return (*this);
	}
	T							*operator->(void){
		return (*this);
	}

	/**************************************************
	********* operator '++a' 'a++' '*a++' *************
	**************************************************/
	ForwardIterator				operator++(int) const{
		ForwardIterator I = this;
		this++;
		return (I);
	}
	ForwardIterator				operator++(void) const{
		return (this++);
	}
	T							*operator++(void){
		T I = *this;
		*this += 1;
		return (I);
	}


};

#endif
