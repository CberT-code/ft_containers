
#ifndef REVERSEBidirectionalIterator_H
#define REVERSEBidirectionalIterator_H

#include "./Iterator.hpp"

template <typename T>
class ReverseBidirectionalIterator : public ReverseForwardIterator<T>
{
	public:

		/**************************************************
		****************** Form Coplien *******************
		**************************************************/

		ReverseBidirectionalIterator(void){}
		
		ReverseBidirectionalIterator(ReverseBidirectionalIterator const &src){
			operator=(src);
		}
		ReverseBidirectionalIterator &	operator=( ReverseBidirectionalIterator const &src){
			if (this != &src){
				this->it = src.it;
			}
			return (*this);
		}
		virtual ~ReverseBidirectionalIterator(void){}

		ReverseBidirectionalIterator(maillon<T> *src){
			this->it = src;
		}


		/**************************************************
		********* operator '--a' 'a--' '*a--' *************
		**************************************************/
		ReverseBidirectionalIterator				operator--(int){
			ReverseBidirectionalIterator I = *this;
			if (this->it && this->it->next)
				this->it = this->it->next;
			return (I);
		}
		ReverseBidirectionalIterator				&operator--(void){
			if (this->it && this->it->next)
				this->it = this->it->next;
			return (*this);
		}
		// T							*operator--(void){
		// 	if (this->it != NULL){
		// 		this->it->ptr -= 1;
		// 		return (this->it->ptr);
		// 	}
		// 	return (NULL);
		// }

};

#endif
