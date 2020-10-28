
#ifndef LIST_H
#define LIST_H
#include <memory>
#include <limits>

#include "../Headers/Header.hpp"

namespace ft
{
	template<typename T>
	class list
	{
		
		public:

			typedef T 									value_type;
			typedef BidirectionalIterator<T>			Iterator;
			typedef T &									reference;
			typedef const T&							const_reference;
			typedef T*									pointer;
			typedef const T*							const_pointer;
			typedef const Iterator 						const_Iterator;
			// typedef InputIterator<T>					InputIterator;
			typedef size_t								size_type;
			typedef BidirectionalIterator<T> 			reverse_Iterator;
			typedef BidirectionalIterator< const T>		const_reverse_Iterator;
			typedef std::ptrdiff_t 						difference_type;


			/**************************************************
			****************** Form Coplien *******************
			**************************************************/
			explicit list(void){
				*this->_endsize->ptr = 0;
				this->_size = 0;
				this->_begin = NULL;
			}

			explicit list(size_type n,  const value_type& val = value_type()){
				this->_begin = NULL;
				assign(n, val);
			}

			template <class InputIterator>
			list(InputIterator first, InputIterator last){
				this->_begin = NULL;
				assign(first,last);
			}

			list(const list& x){
				this->_begin = NULL;
				operator=(x);
			}
			list &	operator=( list const &src){             // DEEP COPY A FAIRE
				if (this != &src){
					
				}
				return (*this);
			}
			virtual ~list(void){
				// clear();
			}

			void	aff(void){
				maillon<T> *cpy = this->_begin;

				while (cpy != this->_endsize && cpy)
				{
					std::cout << *(cpy->ptr) << std::endl;
					cpy = cpy->next;
				}
			}
			
			/**************************************************
			************** begin end rbegin rend **************
			**************************************************/

			Iterator						begin(){
				return (Iterator(this->_begin));
			}
			const_Iterator					begin() const{
				return (this->_begin);
			}
			Iterator						end(){	
				return (this->_endsize);
			}
			const_Iterator					end() const{
				return (this->_endsize);
			}
			// reverse_Iterator 				rbegin(){
			// 	return (this->_cont->size + this->_n);
			// }
			// const_reverse_Iterator 		rbegin() const;
			// reverse_Iterator 			rend(){}
			// const_reverse_Iterator 		rend() const;

			/**************************************************
			*************** empty size max_endsize->ptr ***************
			**************************************************/
			
			bool							empty() const{
				if (this->_size == 0)
					return  (true);
				return (false);
			}
			size_type						size() const{
				return (this->_size);
			}
			size_type						max_size() const{
				return (std::numeric_limits<difference_type>::max() / sizeof(T));
			}

			/**************************************************
			******************** front back *******************
			**************************************************/
			reference 					front(){
				return (this->begin());
			}
			const_reference 			front() const{
				return (this->begin());
			}
			reference					back(){
				return (this->end());
			}
			const_reference				back() const{
				return (this->end());
			}

			/**************************************************
			* assign push_front pop_front push_back pop_back  *
			********* insert erase swap resize clear **********
			**************************************************/

		
			void						assign(size_type n, const value_type& val){
				if (this->_begin != NULL)
					this->clear();
				if (n > 0){
					this->_begin = new maillon<T>;
					this->_begin->ptr = this->_al->allocate(1);
					this->_al->construct(this->_begin->ptr, val);
					this->_endsize = new maillon<T>;
					this->_begin->prev = this->_endsize;
					this->_begin->next = this->_endsize;
					this->_endsize->prev = this->_begin;
					this->_endsize->next = this->_begin;
					this->_endsize->ptr = this->_al->allocate(1);
					this->_al->construct(this->_endsize->ptr, 1);
					this->_size = 1;
					for (size_t i = 1; i < n; i++)
						push_back(val);
				}
			}

			template <class InputIterator>
			void 						assign(InputIterator first, InputIterator last){
				this->clear();
				while (first != last){
					this->push_back(*first);
					first++;
				}

			}
			
			void						push_front (const value_type& val){
				maillon<T> *new_start =  new maillon<T>;

				//Initialisation du nouveau premier maillon<T>
				new_start->ptr = this->_al->allocate(1);
				this->_al->construct(new_start->ptr, val);
				new_start->prev = this->_endsize;
				new_start->next = this->_begin;
				this->_begin->prev = new_start;

				//Modification des variables
				this->_begin = new_start;
				*this->_endsize->ptr += 1;
				this->_size += 1;
			}
			void						pop_front(void){
				maillon<T>	*cpy = this->_begin;

				this->_al->deallocate(cpy->ptr, 1);
				this->_begin = cpy->next;
				delete cpy;
				this->_begin->prev = this->_endsize;
				*this->_endsize->ptr -= 1;
				this->_size -= 1;
			}
			void 						push_back (const value_type& val){
				if (this->_begin == NULL){
					std::cout << "1st" << std::endl;
					list(static_cast<size_t>(1), val);
				}
				else
				{
					maillon<T> *new_end =  new maillon<T>;
					maillon<T> *old_end =  this->_endsize->prev;

					old_end->next = new_end;

					//Initialisation du nouveau dernier maillon<T>
					new_end->ptr = this->_al->allocate(1);
					this->_al->construct(new_end->ptr, val);
					new_end->prev = old_end;
					new_end->next = this->_endsize;

					//Modification des variables
					this->_endsize->prev = new_end;
					*this->_endsize->ptr += 1;
					this->_size += 1;
				}
				

			}
			void 						pop_back(void){
					maillon<T> *replaced = this->_endsize->prev;
					maillon<T> *new_end = this->_endsize->prev->prev;
					
					this->_al->destroy(replaced->ptr);
					std::cout << "toto" << std::endl;
					this->_endsize->prev = new_end;
					new_end->next = this->_endsize;
					delete (replaced);
					*this->_endsize->ptr -= 1;
					this->_size -= 1;
			}

			// Iterator					insert (Iterator position, const value_type& val){
			// }	
			// void						insert (Iterator position, size_type n, const value_type& val){

			// }

			// template <class InputIterator>
			// void						insert (Iterator position, InputIterator first, InputIterator last){}

			Iterator					erase (Iterator position){
				position.it->prev->next = position.it->next;
				position.it->next->prev = position.it->prev;
				this->_al->destroy(position.ptr);
				delete (position);
			}
			// Iterator					erase (Iterator first, Iterator last){}
			void						swap (list& x){
				maillon<T>				*cpy_begin;
				maillon<T>				*cpy_end;

				cpy_begin = x._begin;
				cpy_end = x._endsize;
				x._begin = this->_begin;
				x._endsize = this->_endsize;
				this->_begin = cpy_begin;
				this->_endsize = cpy_end;
			}
			void						resize (size_type n, value_type val = value_type()){
			while (this->_size > n)
				this->pop_back();
			while (this->_size < n)
				this->push_back(val);
			}
			void						clear(void){
				maillon<T> *cpy = NULL;

				if (this->_begin != NULL){
					while (cpy != this->_endsize)
					{
						cpy = this->_begin;
						this->_begin = cpy->next;
						this->_al->deallocate(cpy->ptr, 1);
						delete cpy;
					}
					this->_begin = NULL;
					this->_endsize = NULL;
				}

			}
			/**************************************************
			**** splice remove remove_if unique merge sort ****
			********************* reverse *********************
			**************************************************/

			private :
				std::allocator<T>				*_al;
				maillon<T>						*_begin;
				maillon<T>						*_endsize;
				size_t							_size;




	};
}



#endif
