
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

			struct maillon
			{
				maillon					*prev;
				maillon					*next;	
				T						*ptr;		
			};

			typedef T 							value_type;
			typedef BidirectionalIterator<T>	Iterator;
			typedef T &							reference;
			typedef const T&					const_reference;
			typedef T*							pointer;
			typedef const T*					const_pointer;
			typedef const Iterator 				const_iterator;
			typedef size_t						size_type;
			// typedef ReverseIterator<iterator> 	reverse_iterator;
			// typedef ReverseIterator<const_iterator> const_reverse_iterator;
			typedef std::ptrdiff_t 				difference_type;


			/**************************************************
			****************** Form Coplien *******************
			**************************************************/
			list(void){
				this->_size = 0;
				this->_unit = NULL;
			}

			list(size_t n, T val){
				if (n > 0){
					this->_unit = new maillon;
					this->_unit->ptr = this->_al->allocate(1);
					this->_al->construct(this->_unit->ptr, val);
					this->_unit->prev = NULL;
					this->_unit->next = NULL;
					this->_begin = this->_unit;
					this->_end = this->_unit;
					this->_size = 1;
					for (size_t i = 1; i < n; i++)
						push_back(val);
				}
			}

			// list(InputIterator first, InputIterator last){
			// 	size_t				i = 0;

			// 	while (first + i != last)
			// 		i++;

			// 	//Initialisation de la structure du container
			// 	this->_begin = first;
			// 	this->_end = last;
			// 	this->_size = i;

			// 	//Initialisation du premier maillon
			// 	this->_unit = new maillon;
			// 	this->_unit->prev = NULL;
			// 	this->_unit->next = NULL;
			// 	this->_unit->ptr = first;
			// }

			list(list const &src){
				operator=(src);
			}
			list &	operator=( list const &src){             // DEEP COPY A FAIRE
				if (this != &src){
					
				}
				return (*this);
			}
			virtual ~list(void){
				
			}

			void	aff(void){
				maillon *cpy = this->_unit;

				while (cpy)
				{
					std::cout << *(cpy->ptr) << std::endl;
					cpy = cpy->next;
				}
			}
			
			/**************************************************
			************** begin end rbegin rend **************
			**************************************************/

			Iterator						begin(){
				return (this->_begin);
			}
			const_iterator					begin() const{
				return (this->_begin);
			}
			Iterator						end(){
				return (this->_end);
			}
			const_iterator					end() const{
				return (this->_end);
			}
			// reverse_iterator 				rbegin(){
			// 	return (this->_cont->size + this->_n);
			// }
			// const_reverse_iterator 		rbegin() const;
			// reverse_iterator 			rend(){}
			// const_reverse_iterator 		rend() const;

			/**************************************************
			*************** empty size max_size ***************
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
				return (this->_begin());
			}
			const_reference 			front() const{
				return (this->_begin());
			}
			reference					back(){
				return (this->_end());
			}
			const_reference				back() const{
				return (this->_end());
			}

			/**************************************************
			* assign push_front pop_front push_back pop_back  *
			********* insert erase swap resize clear **********
			**************************************************/
			// template <class InputIterator>
			// void 						assign (InputIterator first, InputIterator last){}
		
			void						assign (size_type n, const value_type& val){
				clear();
				this = ft::list(n, val);
			}
			void						push_front (const value_type& val){
				maillon *start =  new maillon;

				//Initialisation du nouveau premier maillon
				start->ptr = this->_al->allocate(1);
				this->_al->construct(start->ptr, val);
				start->prev = NULL;
				start->next = this->_begin;
				start->size = 1;

				//Modification des variables
				this->_unit->prev = start;
				this->_begin = start;
				this->_size += 1;
				this->_unit = start;
			}
			void						pop_front(void){
				this->_begin = this->_unit->next;
				this->_al->deallocate(this->_unit->ptr, 1);
				delete this->_unit;
				this->_unit = this->_begin;
				this->_size -= 1;
			}
			void 						push_back (const value_type& val){
				maillon *end =  new maillon;

				//Initialisation du nouveau dernier maillon
				end->ptr = this->_al->allocate(1);
				this->_al->construct(end->ptr, val);
				end->prev = this->_end;;
				end->next = NULL;
				end->size = 1;

				//Modification des variables
				this->_end->next = end;
				this->_end = end;
				this->_size += 1;
			}
			void 						pop_back(void){
				if (this->_unit->size == 1)
				{
					maillon *p;

					p = this->_end->prev;
					this->_al->deallocate(this->_end->ptr, 1);
					delete this->_end;
					this->_end = p;
					p->next = NULL;
					this->_size -= 1;
				}
				else{
					this->_al->destroy(this->_end->ptr + this->_end->size);
					this->_end->size -= 1;
					this->_size -= 1;
				}
			}

			// Iterator					insert (Iterator position, const value_type& val){
			// }	
			// void						insert (iterator position, size_type n, const value_type& val){

			// }

			// template <class InputIterator>
			// void						insert (iterator position, InputIterator first, InputIterator last){}

			// iterator					erase (iterator position){}
			// iterator					erase (iterator first, iterator last){}
			void						swap (list& x){
				maillon				*cpy_unit;
				maillon				*cpy_begin;
				maillon				*cpy_end;
				size_t				cpy_size;	

				cpy_unit = x->_unit;
				cpy_begin = x->_begin;
				cpy_end = x->_end;
				cpy_size = x->_size;
				x->_unit = this->_unit;
				x->_begin = this->_begin;
				x->_end = this->_end;
				x->_size = this->_size;
				this->_unit = cpy_unit;
				this->_begin = cpy_begin;
				this->_end = cpy_end;
				this->_size = cpy_size;
			}
			void						resize (size_type n, value_type val = value_type()){
				size_t 				ind = 0;
				maillon				*cpy;
				maillon				*tmp;

				cpy = this->_unit;
				if (n < this->_size){
					ind += cpy->size;
					while (ind < n && cpy->next){
						cpy = cpy->next;
						ind += cpy->size;
					}
					ind -= n;
					for (size_t i = 0; i < ind; i++){
						this->_al->destroy(cpy->ptr + (cpy->size - i));
					}
					cpy->size -= ind;
					tmp = cpy;
					cpy = cpy->next;
					tmp->next = 0;
					while (cpy){

						tmp = cpy;
						cpy = cpy->next;
						this->_al->deallocate(cpy->ptr, cpy->size);
						delete tmp;
					}
				}
				// si plus grand, faire avec le insert;
					
			}
			void						clear(void){
				maillon *cpy;

				while (this->_unit)
				{
					cpy = this->_unit;
					this->_unit = this->_unit->next;
					this->_al->deallocate(cpy->ptr, cpy->size);
					delete cpy;
				}
				this->_begin = NULL;
				this->_end = NULL;
				this->_size = 0;
			}

			/**************************************************
			**** splice remove remove_if unique merge sort ****
			********************* reverse *********************
			**************************************************/

			private :
				std::allocator<T>				*_al;
				maillon							*_unit;
				maillon							*_begin;
				maillon							*_end;
				size_t							_size;	







	};
}



#endif
