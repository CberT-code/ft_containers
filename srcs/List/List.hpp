
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
				size_t					size;		
				T					*ptr;		
			};

			struct gbl_conteneur
			{
				maillon					*begin;
				maillon					*end;
				size_t					size;			
			};

			typedef T 							value_type;
			typedef BidirectionalIterator<T>			Iterator;
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
				this->_cont.size = 0;
				this->_unit = NULL;
			}

			list(size_t n, T val){
				//Initialisation du premier maillon
				this->_unit = new maillon;
				this->_unit->ptr = this->_al->allocate(n);
				for (size_t i = 0; i < n; i++)
					this->_al->construct(this->_unit->ptr + i, val);
				this->_unit->prev = NULL;
				this->_unit->next = NULL;
				this->_unit->size = n;

				//Initialisation de la structure du container
				this->_cont.begin  = this->_unit;
				this->_cont.end = this->_unit;
				this->_cont.size = n;
			}

			// list(InputIterator first, InputIterator last){
			// 	size_t				i = 0;

			// 	while (first + i != last)
			// 		i++;

			// 	//Initialisation de la structure du container
			// 	this->_cont.begin = first;
			// 	this->_cont.end = last;
			// 	this->_cont.size = i;

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
				maillon *cpy;
				while (this->_unit)
				{
					cpy = this->_unit;
					this->_unit = this->_unit->next;
					delete cpy;
				}
			}

			void	aff(void){
				maillon *cpy = this->_unit;
				while (cpy)
				{
					for (size_t i = 0; i < cpy->size; i++)
					{
						std::cout << *(cpy->ptr + i) << std::endl;
					}
					cpy = cpy->next;
				}
				
			}
			
			/**************************************************
			************** begin end rbegin rend **************
			**************************************************/

			Iterator						begin(){
				return (this->_cont.begin);
			}
			const_iterator					begin() const{
				return (this->_cont.begin);
			}
			Iterator						end(){
				return (this->_cont.end);
			}
			const_iterator					end() const{
				return (this->_cont.end);
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
				if (this->_cont.size == 0)
					return  (true);
				return (false);
			}
			size_type						size() const{
				return (this->_cont.size);
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
		
			// void						assign (size_type n, const value_type& val){}
			void						push_front (const value_type& val){
				maillon *start =  new maillon;

				//Initialisation du nouveau premier maillon
				start->ptr = this->_al->allocate(1);
				this->_al->construct(start->ptr, val);
				start->prev = NULL;
				start->next = this->_cont.begin;
				start->size = 1;

				//Modification des variables
				this->_unit->prev = start;
				this->_cont.begin = start;
				this->_cont.size += 1;
				this->_unit = start;
			}
			void						pop_front(void){
				if (this->_unit->size == 1)
				{
					this->_cont.begin = this->_unit->next;
					this->_al->deallocate(this->_unit->ptr, 1);
					delete this->_unit;
					this->_unit = this->_cont.begin;
					this->_cont.size -= 1;
				}
				else{
					this->_al->destroy(this->_unit->ptr);
					this->_unit->size -= 1;
					this->_cont.size -= 1;
					this->_unit->ptr = this->_unit->ptr + 1;
				}
			}
			void 						push_back (const value_type& val){
				maillon *end =  new maillon;

				//Initialisation du nouveau dernier maillon
				end->ptr = this->_al->allocate(1);
				this->_al->construct(end->ptr, val);
				end->prev = this->_cont.end;;
				end->next = NULL;
				end->size = 1;

				//Modification des variables
				this->_cont.end->next = end;
				this->_cont.end = end;
				this->_cont.size += 1;
			}
			void 						pop_back(void){
				if (this->_unit->size == 1)
				{
					maillon *p;

					p = this->_cont.end->prev;
					this->_al->deallocate(this->_cont.end->ptr, 1);
					delete this->_cont.end;
					this->_cont.end = p;
					p->next = NULL;
					this->_cont.size -= 1;
				}
				else{
					this->_al->destroy(this->_cont.end->ptr + this->_cont.end->size);
					this->_cont.end->size -= 1;
					this->_cont.size -= 1;
				}
			}

			// Iterator					insert (Iterator position, const value_type& val){
			// }	
			// void						insert (iterator position, size_type n, const value_type& val){}

			// template <class InputIterator>
			// void						insert (iterator position, InputIterator first, InputIterator last){}

			// iterator					erase (iterator position){}
			// iterator					erase (iterator first, iterator last){}
			// void						swap (list& x){}
			// void						resize (size_type n, value_type val = value_type()){}
			// void						clear(){}

			/**************************************************
			**** splice remove remove_if unique merge sort ****
			********************* reverse *********************
			**************************************************/

			private :
				std::allocator<T>				*_al;
				maillon							*_unit;
				gbl_conteneur						_cont;







	};
}



#endif
