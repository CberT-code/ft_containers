
#ifndef REVERSEINPUTITERATOR_H
#define REVERSEINPUTITERATOR_H

#include "../Headers/Header.hpp"
template <typename T>
class ReverseInputIterator
{
	/**************************************************
	****************** Form Coplien *******************
	**************************************************/
	
	public :

		ReverseInputIterator(){}
		ReverseInputIterator(ReverseInputIterator const &src){
			operator=(src);
		}
		ReverseInputIterator &	operator=( ReverseInputIterator const &src){
			if (this != &src)
				this->it = src.it;
			return (*this);
		}
		virtual ~ReverseInputIterator(void){}
		
		/**************************************************
		*************** operator '==' '!=' ****************
		**************************************************/
		bool					operator==(const ReverseInputIterator &src) const{
			// std::cout << "it = " << this->it << std::endl;
			// std::cout << "tata.end() = " << src.it << std::endl;
			if (src.it == this->it)
				return (true);
			return (false);
		}
		bool					operator!=(const ReverseInputIterator &src) const{
			return (!operator==(src));
		}

		/**************************************************
		************* operator '*a' 'a->m' ****************
		**************************************************/
		T							&operator*(void){
			return (*this->it->ptr);
		}
		T							*operator->(void){
			return (this->it->ptr);
		}

		/**************************************************
		********* operator '++a' 'a++' '*a++' *************
		**************************************************/
		ReverseInputIterator				operator++(int){
			ReverseInputIterator I = *this;
			if (this->it && this->it->prev)
				this->it = this->it->prev;
			return (I);
		}
		ReverseInputIterator				operator++(void){
			if (this->it && this->it->prev)
				this->it = this->it->prev;
			return (*this);
		}
		maillon<T>						*get_it(void) const{
			return (this->it);
		}
	protected :
		maillon<T>				*it;
};

#include "./Iterator.hpp"

#endif
