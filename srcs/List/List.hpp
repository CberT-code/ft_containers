
#ifndef LIST_H
#define LIST_H


#include "../Headers/Header.hpp"

namespace ft
{
	template<typename T, class Alloc = std::allocator<T> >
	class list
	{
		
		public:

			typedef T 											value_type;
			typedef Alloc 										allocator_type;
			typedef BidirectionalIterator<T>					Iterator;
			typedef T &											reference;
			typedef const T&									const_reference;
			typedef T*											pointer;
			typedef const T*									const_pointer;
			typedef const Iterator 								const_Iterator;
			typedef size_t										size_type;
			typedef ReverseBidirectionalIterator<T> 			reverse_Iterator;
			typedef ReverseBidirectionalIterator< const T>		const_reverse_Iterator;
			typedef std::ptrdiff_t 								difference_type;


			/**************************************************
			****************** Form Coplien *******************
			**************************************************/
			explicit list (const allocator_type& alloc = allocator_type()){
				this->_al = alloc;
				this->_begin = NULL;
				this->_endsize = NULL;
				this->_size = 0;
			}

			explicit list (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()){
				this->_al = alloc;
				this->_begin = NULL;
				this->_endsize = NULL;
				this->_size = 0;
				assign(n, val);
			}

			explicit list (int n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()){
				this->_al = alloc;
				this->_begin = NULL;
				this->_endsize = NULL;
				this->_size = 0;
				assign(n, val);
			}
			template <class InputIterator>
			list (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type()){
				this->_al = alloc;
				this->_begin = NULL;
				this->_endsize = NULL;
				this->_size = 0;
				assign(first,last);
			}

			list(const list& x){
				this->_begin = NULL;
				this->_endsize = NULL;
				this->_size = 0;
				operator=(x);
			}
			virtual ~list(void){
				clear();
			}
			list &	operator=( list const &src){             // DEEP COPY A FAIRE
				if (this != &src){
					
				}
				return (*this);
			}

			// void	aff(void){
			// 	maillon<T> *cpy = this->_begin;

			// 	while (cpy != this->_endsize && cpy)
			// 	{
			// 		std::cout << *(cpy->ptr) << std::endl;
			// 		cpy = cpy->next;
			// 	}
			// }
			
			/**************************************************
			************** begin end rbegin rend **************
			**************************************************/

			Iterator						begin(){
				return (this->_begin);
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
			reverse_Iterator 				rbegin(){
				return (this->_endsize->prev);
			}
			const_reverse_Iterator 		rbegin() const{
				return (this->_endsize->prev);
			}
			reverse_Iterator 				rend(){
				return (this->_endsize);
			}
			const_reverse_Iterator 		rend() const{
				return (this->_endsize);
			}

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
				return (std::numeric_limits<std::size_t>::max() / sizeof(value_type));
			}

			/**************************************************
			******************** front back *******************
			**************************************************/
			reference 					front(){
				return (*this->_begin->ptr);
			}
			const_reference 			front() const{
				return (*this->_begin->ptr);
			}
			reference					back(){
				return (*this->_endsize->prev->ptr);
			}
			const_reference				back() const{
				return (*this->_endsize->prev->ptr);
			}

			/**************************************************
			* assign push_front pop_front push_back pop_back  *
			********* insert erase swap resize clear **********
			**************************************************/

		
			void						assign(size_type n, const value_type& val){
				if (this->_begin != NULL)
					this->clear();
				for (size_t i = 1; i < n; i++)
					push_back(val);
			}

			void						assign(int n, const value_type& val){
				if (this->_begin != NULL)
					this->clear();
				for (int i = 1; i < n; i++)
					push_back(val);
			}
			template <class InputIterator>
			void 						assign(InputIterator first, InputIterator last){
				if (this->_begin != NULL)
					this->clear();
				while (first != last){
					this->push_back(*first);
					first++;
				}
			}
			void						push_front (const value_type& val){
				maillon<T> *new_start =  new maillon<T>;

				//Initialisation du nouveau premier maillon<T>
				new_start->ptr = this->_al.allocate(1);
				this->_al.construct(new_start->ptr, val);
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

				this->_al.deallocate(cpy->ptr, 1);
				this->_begin = cpy->next;
				delete cpy;
				this->_begin->prev = this->_endsize;
				*this->_endsize->ptr -= 1;
				this->_size -= 1;
			}
			void 						push_back (const value_type& val){
				if (this->_begin == NULL){
					this->_begin = new maillon<T>;
					this->_begin->ptr = this->_al.allocate(1);
					this->_al.construct(this->_begin->ptr, val);
					this->_endsize = new maillon<T>;
					this->_begin->prev = this->_endsize;
					this->_begin->next = this->_endsize;
					this->_endsize->prev = this->_begin;
					this->_endsize->next = this->_begin;
					this->_endsize->ptr = this->_al.allocate(1);
					this->_al.construct(this->_endsize->ptr, 1);
					this->_size = 2;
				}
				else
				{
					
					maillon<T> *new_end =  new maillon<T>;
					maillon<T> *old_end =  this->_endsize->prev;

					old_end->next = new_end;

					//Initialisation du nouveau dernier maillon<T>
					new_end->ptr = this->_al.allocate(1);
					this->_al.construct(new_end->ptr, val);
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
					
					this->_al.deallocate(replaced->ptr, 1);
					this->_al.destroy(replaced->ptr);
					this->_endsize->prev = new_end;
					new_end->next = this->_endsize;
					delete (replaced);
					this->_size -= 1;
					*this->_endsize->ptr = static_cast<int>(this->_size);
			}
			Iterator					insert (Iterator position, const value_type& val){
				maillon<T> *new_maillon = new maillon<T>;

				new_maillon->ptr = this->_al.allocate(1);
				this->_al.construct(new_maillon->ptr, val);
				new_maillon->next = position.get_it();
				new_maillon->prev = position.get_it()->prev;
				new_maillon->next->prev = new_maillon;
				new_maillon->prev->next = new_maillon;
				this->_size += 1;
				*this->_endsize->ptr = static_cast<int>(this->_size);
				return (position);
			}	
			void						insert (Iterator position, size_type n, const value_type& val){
				while (n--){
					insert(position, val);
				}
			}
			void						insert (Iterator position, int n, const value_type& val){
				while (n--){
					insert(position, val);
				}
			}
			template <class InputIterator>
			void						insert (Iterator position, InputIterator first, InputIterator last){
				while (first != last){
					insert(position, first);
					first++;
				}
			}
			Iterator					erase (Iterator position){
				maillon<T> *pos = position.get_it();
				pos->prev->next = pos->next;
				pos->next->prev = pos->prev;
				this->_al.deallocate(pos->ptr, 1);
				this->_al.destroy(pos->ptr);
				delete (pos);
				position++;
				this->_size -= 1;
				*this->_endsize->ptr = static_cast<int>(this->_size);
				return (position);
			}
			Iterator					erase (Iterator first, Iterator last){
				while (first != last)
					first = erase(first);
				return (last);
			}
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
				while (this->_size)
					this->pop_back();
			}
			/**************************************************
			**** splice remove remove_if unique merge sort ****
			********************* reverse *********************
			**************************************************/
			void sort(void){
				maillon<T> 		*start = this->_begin;
				maillon<T> 		*end = this->_endsize->prev;

				while (start != end){
					while (start != end){
						if (std::min(*start->ptr, *end->ptr) != *start->ptr)
							std::swap(start->ptr, end->ptr);
						end = end->prev;
					}
					end = this->_endsize->prev;
					start = start->next;
				}
			}
			// template <class Compare>
			// void sort (Compare comp){

			// }
			void 							reverse(void){
				maillon<T> 		*start = this->_begin;
				maillon<T> 		*end = this->_endsize->prev;

				while (start != end && start != end->next){
					std::swap(start->ptr, end->ptr);
					start = start->next;
					end = end->prev;
				}
			}
			private :
				allocator_type					_al;
				maillon<T>						*_begin;
				maillon<T>						*_endsize;
				size_t							_size;
	};
}



#endif
