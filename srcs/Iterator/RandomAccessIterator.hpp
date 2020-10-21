
#ifndef BIDIRECTIONALITERATOR_H
#define BIDIRECTIONALITERATOR_H

#include "./Iterator.hpp"

template <typename T>
class RandomAccessIterator
{
	public:

		/**************************************************
		****************** Form Coplien *******************
		**************************************************/

		BidirectionalIterator(void){
			this->it == NULL;
		}
		
		BidirectionalIterator(BidirectionalIterator const &src){
			operator=(src);
		}
		BidirectionalIterator &	operator=( BidirectionalIterator const &src){
			if (this != &src){
				this->it = src.it;
			}
			return (this);
		}
		virtual ~BidirectionalIterator(void){
			void	*cpy;
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
			if (this->it != NULL)
				return (this->it->element);
			return (NULL);
		}
		T							*operator->(void){
			if (this->it != NULL)
				return (this->it);
			return (NULL);
		}

		/**************************************************
		********* operator '++a' 'a++' '*a++' *************
		**************************************************/
		BidirectionalIterator				operator++(int n) const{
			if (this->it != NULL){
				this->it = this->it->next;
				return(this->it);
			}
			return (NULL);
		}
		BidirectionalIterator				&operator++(int n) const{
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
		BidirectionalIterator				operator--(int n) const{
			if (this->it != NULL){
				this->it = this->it->prev;
				return(this->it);
			}
			return (NULL);
		}
		BidirectionalIterator				&operator--(int n) const{
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

		/**************************************************
		*** operator 'a + n' 'n + a' 'a - b'  'a - b **** 
		**************************************************/
		BidirectionalIterator				operator+(int n) const{
			int i = -1;

			void *ptr = this->it;
			if (ptr != NULL){
				while (++i < n && ptr != NULL)
					ptr = ptr->next;
				return(ptr);
			}
			return (NULL);
		}
		BidirectionalIterator				operator-(int n) const{
			int i = -1;

			void *ptr = this->it;
			if (ptr != NULL){
				while (++i < n && ptr != NULL)
					ptr = ptr->prev;
				return(this->it);
			}
			return (NULL);
		}

		/**************************************************
		*** operator 'a < b' 'a > b' 'a <= b'  'a >= b **** 
		**************************************************/
		bool								operator<(const BidirectionalIterator &src){
			if (this->it->inc < src.it->inc)
				return (true);
			return (false);
		}
		bool								operator>(const BidirectionalIterator &src){
			if (this->it->inc > src.it->inc)
				return (true);
			return (false);
		}
		bool								operator<=(const BidirectionalIterator &src){
			if (this->it->inc <= src.it->inc)
				return (true);
			return (false);
		}
		bool								operator>=(const BidirectionalIterator &src){
			if (this->it->inc >= src.it->inc)
				return (true);
			return (false);
		}

		/**************************************************
		************ operator 'a += n' 'a-= n' ************ 
		**************************************************/
		BidirectionalIterator				operator+=(int n) const{
			int i = -1;

			void *ptr = this->it;
			if (ptr != NULL){
				while (++i < n && ptr != NULL)
					ptr = ptr->next;
				this->it = ptr;
				return (ptr);
			}
			return(this->it);
		}
		BidirectionalIterator				operator-=(int n) const{
			int i = -1;

			void *ptr = this->it;
			if (ptr != NULL){
				while (++i < n && ptr != NULL)
					ptr = ptr->next;
				this->it = prev;
				return(ptr);
			}
			return (this->it);
		}

		/**************************************************
		******************* operator [] ******************* 
		**************************************************/
		BidirectionalIterator				operator[](int n) const{
			int i = -1;

			void *ptr = this->it;
			if (ptr != NULL){
				while (++i < n && ptr != NULL)
					ptr = ptr->next;
				return (ptr);
			}
			return(this->it);
		}

	protected :
		BidirectionalIterator(T elem){
				void *iter = new iterator_struct<T>;
				iter->inc = 0;
				if (this->it != NULL){
					this->it->next = iter;
					iter->inc = this->it->inc + 1;
				}
				iter->element == elem;
				iter->prev == this->it;
				iter->next == NULL;
				this->it = iter;
			}
			
	private:
		iterator_struct<T>				*it;
};

#endif
