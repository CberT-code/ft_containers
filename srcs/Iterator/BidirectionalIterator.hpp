
#ifndef BIDIRECTIONALITERATOR_H
#define BIDIRECTIONALITERATOR_H

#include "./Iterator.hpp"

template <typename T>
class BidirectionalIterator
{
	public:

		/**************************************************
		****************** Form Coplien *******************
		**************************************************/

		BidirectionalIterator(void){}
		
		BidirectionalIterator(BidirectionalIterator const &src){
			operator=(src);
		}
		BidirectionalIterator &	operator=( BidirectionalIterator const &src){
			if (this != &src){
				this->it = src.it;
			}
			return (*this);
		}
		virtual ~BidirectionalIterator(void){
			iterator_struct<T>	*cpy;
			while (this->it != NULL)
			{
				cpy = this->it;
				this->it = this->it->next;
				delete cpy;
			}			
		}
		
		/**************************************************
		*************** operator '==' '!=' ****************
		**************************************************/
		bool					operator==(const BidirectionalIterator &src) const{
			if (this->it == &src.it)
				return (true);
			return (false);
		}
		bool					operator!=(const BidirectionalIterator &src) const{
			if (this->it != &src.it)
				return (true);
			return (false);
		}

		/**************************************************
		************* operator '*a' 'a->m' ****************
		**************************************************/
		T							&operator*(void){
				return (this->it->element);
		}
		T							*operator->(void){
			if (this->it != NULL)
				return (this->it);
			return (NULL);
		}

		/**************************************************
		********* operator '++a' 'a++' '*a++' *************
		**************************************************/
		BidirectionalIterator				operator++(int) const{
			if (this->it != NULL){
				this->it = this->it->next;
				return(this->it);
			}
			return (NULL);
		}
		BidirectionalIterator				&operator++(void) const{
			if (this->it != NULL){
				void *ptr = this->it;
				this->it = this->it->next;
				return(ptr);
			}
			return (NULL);
		}
		T							*operator++(void){
			if (this->it != NULL){
				this->it->element =+ 1;
				return (this->it->element);
			}
			return (NULL);
		}

		/**************************************************
		********* operator '--a' 'a--' '*a--' *************
		**************************************************/
		BidirectionalIterator				operator--(int) const{
			if (this->it != NULL){
				this->it = this->it->prev;
				return(this->it);
			}
			return (NULL);
		}
		BidirectionalIterator				&operator--(void) const{
			if (this->it != NULL){
				void *ptr = this->it;
				this->it = this->it->prev;
				return(ptr);
			}
			return (NULL);
		}
		T							*operator--(void){
			if (this->it != NULL){
				this->it->element -= 1;
				return (this->it->element);
			}
			return (NULL);
		}
			
	private:
		iterator_struct<T>				*it;
};

#endif
