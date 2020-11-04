
#ifndef QUEUE_H
#define QUEUE_H
#include "../Headers/Header.hpp"

template <class T>
struct maillonq
{
	maillonq					*next;	
	T							ptr;		
};

namespace ft
{
	template <typename T, class Container = std::deque<T> >
	class queue
	{

		public:

			typedef T 											value_type;
			typedef	Container									container_type;
			typedef size_t										size_type;

			/**************************************************
			****************** Forme Coplien*******************
			**************************************************/

			explicit 							queue (const container_type& ctnr = container_type()){
				this->_begin = NULL;
				this->_size = 0;
				this = ctnr.assign(ctnr.begin(), ctnr.end());
			}

												queue(const queue& x){
				this->_begin = NULL;
				this->_size = 0;
				operator=(x);
			}


			virtual 							~queue(void){
				while (!this->empty())
					this->pop();
				
			}

		
			queue &								operator=( queue const &src){
				unsigned int cpt = src.size() - 1;
				while (!this->empty())
					this->pop();
				this->_size = src._size;
				
				for (unsigned int i = 0; i < src.size(); i++)
				{
					maillonq<T> *cpy = src._begin;
					for (unsigned int j = 0; j < cpt; j++)
						cpy = cpy->next;
					this->push(cpy->ptr);
					cpt--;
				}
				return (*this);
			}

			/**************************************************
			******************* empty size ********************
			**************************************************/

			bool								empty() const{
				if (this->_size == 0)
					return  (true);
				return (false);
			}
			size_type							size() const{
				size_t	cpt = 0;
				maillonq<T> *cpy = this->_begin;
				if (cpy)
				{
					while (cpy)
					{
						cpy = cpy->next;
						cpt++;
					}
				}
				return (cpt);
			}

			/**************************************************
			******************** front back *******************
			**************************************************/

			value_type& 						front(){
				maillonq<T> *last = this->_begin;
				
				while (last->next)
					last = last->next;
				return (last->ptr);
			}
			const value_type& 					front() const{
				maillonq<T> *last = this->_begin;
				
				while (last->next)
					last = last->next;
				return (last->ptr);
			}
			value_type&							back(){
				return (this->_begin->ptr);
			}
			const value_type&					back() const{
				return (this->_begin->ptr);
			}

			/**************************************************
			******************** push pop *********************
			**************************************************/

			void								push(const value_type& val){
				maillonq<T> *new_start =  new maillonq<T>;

				new_start->ptr = val;
				new_start->next = this->_begin;
				this->_begin = new_start;
				this->_size++;

			}

			
			void 								pop(void){
				maillonq<T> *last = this->_begin;
				
				if (last && last->next)
				{
					while (last->next->next)
						last = last->next;
					delete last->next;
					last->next = NULL;
					this->_size--;
				}
				else if (last)
				{
					delete last;
					last = NULL;
					this->_size = 0;
				}
			}

		private :
			maillonq<T>							*_begin;
			size_t								_size;
	}; 
}


template <class T, class Container>
	bool operator== (const ft::queue<T,Container>& lhs, const ft::queue<T,Container>& rhs){

		if (lhs.size() != rhs.size())
			return false;		
		ft::queue<T, Container> lhsCpy = lhs;
		ft::queue<T, Container> rhsCpy = rhs;
		for (unsigned int i = 0; i < lhs.size(); i++)
		{
			if (lhsCpy.front() != rhsCpy.front())
				return (false);
			lhsCpy.pop();
			rhsCpy.pop();
		}
		return true;
	}


template <class T, class Container>
	bool operator!= (const ft::queue<T,Container>& lhs, const ft::queue<T,Container>& rhs){
		if (!operator==(lhs, rhs))
			return true;
		return false;
	}


template <class T, class Container>
	bool operator<  (const ft::queue<T,Container>& lhs, const ft::queue<T,Container>& rhs){

		if (lhs.size() < rhs.size())
			return true;		
		ft::queue<T, Container> lhsCpy = lhs;
		ft::queue<T, Container> rhsCpy = rhs;
		for (unsigned int i = 0; i < lhs.size(); i++)
		{
			if (lhsCpy.front() < rhsCpy.front())
				return (true);
			lhsCpy.pop();
			rhsCpy.pop();
		}
		return false;
	}


template <class T, class Container>
	bool operator<= (const ft::queue<T,Container>& lhs, const ft::queue<T,Container>& rhs){
		if (operator<(lhs, rhs) || operator==(lhs, rhs))
			return (true);
		return (false);
	}


template <class T, class Container>
	bool operator>  (const ft::queue<T,Container>& lhs, const ft::queue<T,Container>& rhs){

		if (lhs.size() > rhs.size())
			return true;		
		ft::queue<T, Container> lhsCpy = lhs;
		ft::queue<T, Container> rhsCpy = rhs;
		for (unsigned int i = 0; i < lhs.size(); i++)
		{
			if (lhsCpy.front() > rhsCpy.front())
				return (true);
			lhsCpy.pop();
			rhsCpy.pop();
		}
		return false;
	}


template <class T, class Container>
	bool operator>= (const ft::queue<T,Container>& lhs, const ft::queue<T,Container>& rhs){
		if (operator>(lhs, rhs) || operator==(lhs, rhs))
			return (true);
		return (false);
	}

#endif
