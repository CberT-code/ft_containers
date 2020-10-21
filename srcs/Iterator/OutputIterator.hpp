
#ifndef OUTPUTITERATOR_H
#define OUTPUTITERATOR_H

#include "./Iterator.hpp"

template <typename T>
class OutputIterator
{
	public:

		/**************************************************
		****************** Form Coplien *******************
		**************************************************/

		OutputIterator(void){
			this->it == NULL;
		}
		OutputIterator(T elem){
			iterator_struct<T> *iter = new iterator_struct<T>;
			if (this->it != NULL){}
				this->it->next = iter;
			iter->element == elem;
			iter->prev == NULL;
			iter->next == NULL;
			this->it = iter;
		}
		OutputIterator(OutputIterator const &src){
			operator=(src);
		}
		OutputIterator &	operator=( OutputIterator const &src){
			if (this != &src){
				this->it = src.it;
			}
			return (this);
		}
		virtual ~OutputIterator(void){
			iterator_struct<T>	*cpy;
			while (this->it != NULL)
			{
				cpy = this->it;
				this->it = this->it->next;
				delete cpy;
			}
		}

		/**************************************************
		************* operator '*a' 'a->m' ****************
		**************************************************/
		T							&operator*(void){
			if (this->it != NULL)
				return (this->it->element);
			return (NULL);
		}

		/**************************************************
		********* operator '++a' 'a++' '*a++' *************
		**************************************************/
		OutputIterator				operator++(int) const{
			if (this->it != NULL){
				this->it = this->it->next;
				return(this->it);
			}
			return (NULL);
		}
		OutputIterator				&operator++(void) const{
			if (this->it != NULL){
				void *ptr = this->it;
				this->it = this->it->next;
				return(ptr);
			}
			return (NULL);
		}
		T							*operator++(void){
			if (this->it != NULL){
				this->it->element += 1;
				return (this->it->element);
			}
			return (NULL);
		}

	private:
		iterator_struct<T>				*it;
};

#endif
