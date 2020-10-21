
#ifndef INPUTITERATOR_H
#define INPUTITERATOR_H



template <typename T>
struct InputIterator
{

	/**************************************************
	****************** Form Coplien *******************
	**************************************************/

	InputIterator(){}
	InputIterator(InputIterator const &src){
		operator=(src);
	}
	InputIterator &	operator=( InputIterator const &src){
		if (this != &src)
			*this = src;
		return (this);
	}
	virtual ~InputIterator(void){}
	
	/**************************************************
	*************** operator '==' '!=' ****************
	**************************************************/
	bool					operator==(const InputIterator &src) const{
		if (*src == *this)
			return (true);
		return (false);
	}
	bool					operator!=(const InputIterator &src) const{
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
	InputIterator				operator++(int) const{
		InputIterator I = this;
		this++;
		return (I);
	}
	InputIterator				operator++(void) const{
		return (this++);
	}
	T							*operator++(void){
		T I = *this;
		*this += 1;
		return (I);
	}
};

#include "./Iterator.hpp"

#endif
