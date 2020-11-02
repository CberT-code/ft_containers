
#ifndef INPUTITERATOR_H
#define INPUTITERATOR_H

#include "../Headers/Header.hpp"
template <typename T>
class InputIterator
{
	/**************************************************
	****************** Form Coplien *******************
	**************************************************/
	
	public :

		InputIterator(){
			this->it = NULL;
		}
		InputIterator(InputIterator const &src){
			operator=(src);
		}
		InputIterator &	operator=( InputIterator const &src){
			if (this != &src)
				this->it = src.it;
			return (*this);
		}
		
		virtual ~InputIterator(void){}
		
		/**************************************************
		*************** operator '==' '!=' ****************
		**************************************************/
		bool					operator==(const InputIterator &src) const{
			// std::cout << "it = " << this->it << std::endl;
			// std::cout << "tata.end() = " << src.it << std::endl;
			if (src.it == this->it)
				return (true);
			return (false);
		}
		bool					operator!=(const InputIterator &src) const{
			return (!operator==(src));
		}
		

		/**************************************************
		************* operator '*a' 'a->m' ****************
		**************************************************/
		T							&operator*(void){
			return (*this->it->ptr);
		}
		T							*operator->(void){
			return (*this->it);
		}

		/**************************************************
		********* operator '++a' 'a++' '*a++' *************
		**************************************************/
		InputIterator				operator++(int){
			InputIterator I = *this;
			if (this->it && this->it->next)
				this->it = this->it->next;
			return (I);
		}
		InputIterator				operator++(void){
			if (this->it && this->it->next)
				this->it = this->it->next;
			return (*this);
		}
		maillon<T>						*get_it(void) const{
			return (this->it);
		}
		// T							*operator++(void){

		// 	std::cout << this->it->ptr << std::endl;
		// 	;
		// 	return (this->it->ptr += 1);
		// }

	protected :
		maillon<T>					*it;
};

#include "./Iterator.hpp"

#endif
