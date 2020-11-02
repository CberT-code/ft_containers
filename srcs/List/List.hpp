
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
				this->clear();
				if (this != &src){
					this->_size = src._size;
					assign(src.begin(), src.end());
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
			const_reverse_Iterator 			rbegin() const{
				return (this->_endsize->prev);
			}
			reverse_Iterator 				rend(){
				return (this->_endsize);
			}
			const_reverse_Iterator 			rend() const{
				return (this->_endsize);
			}

			/**************************************************
			*************** empty size max_endsize->ptr *******
			**************************************************/
			
			bool							empty() const{
				if (this->_size == 0)
					return  (true);
				return (false);
			}
			size_type						size() const{
				return (this->_size < 2 ? 0 : this->_size - 1);
			}
			size_type						max_size() const{
				return (std::numeric_limits<std::size_t>::max() / sizeof(value_type));
			}

			/**************************************************
			******************** front back *******************
			**************************************************/

			reference 						front(){
				return (*this->_begin->ptr);
			}
			const_reference 				front() const{
				return (*this->_begin->ptr);
			}
			reference						back(){
				return (*this->_endsize->prev->ptr);
			}
			const_reference					back() const{
				return (*this->_endsize->prev->ptr);
			}

			/**************************************************
			* assign push_front pop_front push_back pop_back  *
			********* insert erase swap resize clear **********
			**************************************************/

		
			void							assign(size_type n, const value_type& val){
				if (this->_begin != NULL)
					this->clear();
				for (size_t i = 0; i < n; i++)
					push_back(val);
			}
			void							assign(int n, const value_type& val){
				if (this->_begin != NULL)
					this->clear();
				for (int i = 0; i < n; i++)
					push_back(val);
			}
			template <class InputIterator>
			void 							assign(InputIterator first, InputIterator last){
				if (this->_begin != NULL)
					this->clear();
				while (first != last){
					this->push_back(*first);
					first++;
				}
			}
			void							push_front (const value_type& val){
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
			void							pop_front(void){
				if (this->_size == 2){
					this->_al.deallocate(this->_begin->ptr, 1);
					this->_al.destroy(this->_begin->ptr);
					delete (this->_begin);
					this->_al.deallocate(this->_endsize->ptr, 1);
					this->_al.destroy(this->_endsize->ptr);
					delete (this->_endsize);
					this->_begin = NULL;
					this->_endsize = NULL;
					this->_size = 0;
				}
				else{
					maillon<T>	*cpy = this->_begin;

					this->_al.deallocate(cpy->ptr, 1);
					this->_begin = cpy->next;
					delete cpy;
					this->_begin->prev = this->_endsize;
					*this->_endsize->ptr -= 1;
					this->_size -= 1;
				}
			}
			void 							push_back (const value_type& val){
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
					this->_size = 2;
					printf("We are here\n");
					*this->_endsize->ptr = static_cast<std::string>(this->_size);
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
			void 							pop_back(void){
				if (this->_size == 2)
				{
					if (this->_begin->ptr) {
						this->_al.deallocate(this->_begin->ptr, 1);
						this->_al.destroy(this->_begin->ptr);
					}
					delete (this->_begin);
					this->_al.deallocate(this->_endsize->ptr, 1);
					this->_al.destroy(this->_endsize->ptr);
					delete (this->_endsize);
					this->_begin = NULL;
					this->_endsize = NULL;
					this->_size = 0;
				}
				else
				{
					maillon<T> *replaced = this->_endsize->prev;
					maillon<T> *new_end = this->_endsize->prev->prev;
					
					if (replaced->ptr) {
						this->_al.deallocate(replaced->ptr, 1);
						this->_al.destroy(replaced->ptr);
					}
					this->_endsize->prev = new_end;
					new_end->next = this->_endsize;
					delete (replaced);
					this->_size -= 1;
					*this->_endsize->ptr = static_cast<int>(this->_size);
				}
				
			}
			Iterator						insert (Iterator position, const value_type& val){
				maillon<T> *new_maillon = new maillon<T>;

				new_maillon->ptr = this->_al.allocate(1);
				this->_al.construct(new_maillon->ptr, val);

				new_maillon->next = position.get_it();
				new_maillon->prev = position.get_it()->prev;
			
				if (position.get_it() == this->_begin)
				this->_begin = new_maillon;

				new_maillon->next->prev = new_maillon;
				new_maillon->prev->next = new_maillon;

				this->_size += 1;
				*this->_endsize->ptr = static_cast<int>(this->_size);
				return (position);
			}	
			void							insert (Iterator position, size_type n, const value_type& val){
				while (n--){
					insert(position, val);
				}
			}
			void							insert (Iterator position, int n, const value_type& val){
				while (n--){
					insert(position, val);
				}
			}
			template <class InputIterator>
			void							insert (Iterator position, InputIterator first, InputIterator last){
				while (first != last){
					insert(position, first);
					first++;
				}
			}
			Iterator						erase (Iterator position){
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
			Iterator						erase (Iterator first, Iterator last){
				while (first != last)
					first = erase(first);
				return (last);
			}
			void							swap (list& x){
				std::swap(x._begin, this->_begin);
				std::swap(x._endsize, this->_endsize);
				std::swap(x._size, this->_size);
			}
			void							resize (size_type n, value_type val = value_type()){
			while (this->_size > n)
				this->pop_back();
			while (this->_size < n)
				this->push_back(val);
			}
			void							clear(void){
				while (this->_size)
					this->pop_back();

			}
			/**************************************************
			**** splice remove remove_if unique merge sort ****
			********************* reverse *********************
			**************************************************/


			void splice (Iterator position, list& x){
				Iterator	first = x.begin();
				Iterator 	last  = x.end();

				for (int i = 0; i < x._size; i++) {
					while (first != last) {
						maillon<T>	*stock = new maillon<T>;
						stock->ptr = first.get_it()->ptr;
						first.get_it()->ptr = NULL;
						stock->prev = position.get_it()->prev;
						stock->next = position.get_it();
						position.get_it()->prev->next = stock;
						position.get_it()->prev = stock;
						this->_size += 1;
						first++;
					}
				}
			}

			void splice (Iterator position, list& x, Iterator i){
				Iterator	first = x.begin();
				Iterator 	last  = x.end();


				if (position.get_it() == NULL){
					this->_begin = new maillon<T>;
					this->_begin->ptr = i.get_it()->ptr;
					i.get_it()->ptr = NULL;
					this->_endsize = new maillon<T>;
					this->_begin->prev = this->_endsize;
					this->_begin->next = this->_endsize;
					this->_endsize->prev = this->_begin;
					this->_endsize->next = this->_begin;
					this->_size = 2;
				}
				else{
					//creation du maillon
					maillon<T>	*stock = new maillon<T>;
					stock->ptr = i.get_it()->ptr;
					if (this->_begin == position.get_it())
						this->_begin = stock;
					i.get_it()->ptr = NULL;
					stock->prev = position.get_it()->prev;
					stock->next = position.get_it();

					//ajout du maillon a la nouvelle position
					position.get_it()->prev->next = stock;
					position.get_it()->prev = stock;
					this->_size += 1;
				}


				//suppression du maillon dans la list initiale
				if (i.get_it() == x._begin && x._begin == x._endsize->prev){
					x.clear();
				}
				else{
					i.get_it()->prev->next = i.get_it()->next;
					i.get_it()->next->prev = i.get_it()->prev;
					//rectification des size
					x._size -= 1;
					if (i.get_it() == x._begin){
						x._begin = x._begin->next;
						x._endsize->next = x._begin;
					}
					delete i.get_it();
				}
				
			}


			void splice (Iterator position, list& x, Iterator first, Iterator last){
				while (first != last){
					splice(position, x, first);
					first++;
				}
			}


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
			template <class Compare>
			void sort (Compare comp){
				maillon<T> 		*start = this->_begin;
				maillon<T> 		*end = this->_endsize->prev;

				while (start != end){
					while (start != end){
						if (comp)
							std::swap(start->ptr, end->ptr);
						end = end->prev;
					}
					end = this->_endsize->prev;
					start = start->next;
				}
			}

			void remove(const value_type& val) {
				maillon<T>		*tmp = this->_begin;

				if (tmp != NULL){
					while (tmp != this->_endsize){
						if (*tmp->ptr == val){
							tmp->prev->next = tmp->next;
							tmp->next->prev = tmp->prev;
							_al.deallocate(tmp->ptr, 1);
							if (tmp == this->_begin)
								this->_begin = tmp->next;
							delete tmp;
							tmp = NULL;
							this->_size -= 1;
							return ;
						}
						tmp = tmp->next;
					}
				}
			}

			template <class Predicate>
			void remove_if(Predicate pred) {
				maillon<T>		*tmp = this->_begin;
				maillon<T>		*cpy = tmp;
			
				if (tmp != NULL) {
					while (tmp != this->_endsize)
					{
						if (pred(*tmp->ptr)) {
							cpy = tmp;
							if (tmp == this->_begin)
								this->_begin = tmp->next;
							tmp = tmp->next;
							cpy->prev->next = cpy->next;
							cpy->next->prev = cpy->prev;
							this->_al.deallocate(cpy->ptr, 1);
							delete cpy;
							this->_size -= 1;
						} else
							tmp = tmp->next;
					}
				}
			}

			void unique() {
				maillon<T>		*tmp = this->_begin;
				int				i = 0;

				if (tmp) {
					while (tmp != this->_endsize && tmp){
						i = 0;
						for (maillon<T> *j = tmp; j != this->_endsize; j = j->next){
							if (*j->ptr == *tmp->ptr)
								i += 1;
							if (i > 1){
								j->prev->next = j->next;
								j->next->prev = j->prev;
								_al.deallocate(j->ptr, 1);
								this->_size -= 1;
								delete j;
								j = NULL;
								break;
							}
						}
						tmp = tmp->next;
					}
				}
			}

			template <class BinaryPredicate>
			void					unique(BinaryPredicate binary_pred)
			{
				maillon<T>		*tmp = this->_begin;
				int				i = 0;

				if (tmp) {
					while (tmp != this->_endsize && tmp) {
						i = 0;
						for (maillon<T> *j = tmp; j != this->_endsize; j = j->next) {
							if (*j->ptr == *tmp->ptr)
								i += 1;
							if (binary_pred(*j->ptr, *tmp->ptr)){
								j->prev->next = j->next;
								j->next->prev = j->prev;
								_al.deallocate(j->ptr, 1);
								this->_size -= 1;
								delete j;
								j = NULL;
								break;
							}
						}
						tmp = tmp->next;
					}
				}
			}

			void							merge(list &x) {
				Iterator	first = x.begin();
				Iterator 	last  = x.end();

				for (int i = 0; i < x._size; i++) {
					while (first != last) {
						maillon<T>	*stock = new maillon<T>;
						stock->ptr = first.get_it()->ptr;
						first.get_it()->ptr = NULL;
						stock->prev = this->_endsize->prev;
						stock->next = this->_endsize;
						this->_endsize->prev->next = stock;
						this->_endsize->prev = stock;
						this->_size += 1;
						first++;
					}
				}
				this->sort();
			}

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
