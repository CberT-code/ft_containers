
#ifndef VECTOR_H
#define VECTOR_H
#include "../Headers/Header.hpp"

namespace ft
{
	template<typename T, class Alloc = std::allocator<T> >
	class vector
	{

		public:

			typedef T 											value_type;
			typedef Alloc 										allocator_type;
			typedef RandomAccessIterator<T>						Iterator;
			typedef T &											reference;
			typedef const T&									const_reference;
			typedef T*											pointer;
			typedef const T*									const_pointer;
			typedef const Iterator 								const_Iterator;
			typedef size_t										size_type;
			typedef ReverseRandomAccessIterator<T> 				reverse_Iterator;
			typedef ReverseRandomAccessIterator< const T>		const_reverse_Iterator;
			typedef std::ptrdiff_t 								difference_type;

			/**************************************************
			****************** Form Coplien *******************
			**************************************************/

			explicit 							vector (const allocator_type& alloc = allocator_type()){
				this->_al = alloc;
				this->_array = NULL;
				this->_size = 0;
				this->_capacity = 0;
			}
			explicit 							vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()){
				this->_al = alloc;
				this->_array = new T[1];
				this->_capacity = 1;
				this->_size = 0;
				assign(n, val);
			}
			explicit 							vector (int n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()){
				this->_al = alloc;
				this->_array = new T[1];
				this->_capacity = 1;
				this->_size = 0;
				assign(n, val);
			}
			template <class InputIterator>
												vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type()){
				this->_al = alloc;
				this->_array = new value_type[1];
				this->_size = 0;
				this->assign(first, last);
			}
			vector(const vector& x){
				this->_array = NULL;
				this->_size = 0;
				this->_capacity = 0;
				operator=(x);
			}
			virtual 							~vector(void){
				this->clear();
			}
			vector &							operator=( vector const &src){
				this->clear();
				if (this != &src){
					this->_array = new T[src._capacity];
					this->_capacity = src._capacity;
					this->_size = src._size;
				}
				return (*this);
			}
			void								aff(void){
				maillon<T> *cpy = this->_begin;

				while (cpy != this->_endsize && cpy)
				{
					std::cout << *(cpy->ptr) << std::endl;
					cpy = cpy->next;
				}
			}

			/**************************************************
			******************** Iterators ********************
			**************************************************/

			Iterator							begin(){
				return (this->_array);
			}
			const_Iterator						begin() const{
				return (this->_array);
			}
			Iterator							end(){
				return (&this->_array[this->_size]);
			}
			const_Iterator						end() const{
				return (&this->_array[this->_size]);
			}
			reverse_Iterator 					rbegin(){
				return (&this->_array[this->_size - 1]);
			}
			const_reverse_Iterator 				rbegin() const{
				return (&this->_array[this->_size - 1]);
			}
			reverse_Iterator 					rend(){
				return (this->_array - 1);
			}
			const_reverse_Iterator 				rend() const{
				return (this->_array - 1);
			}

			/**************************************************
			********************* Capacity ********************
			**************************************************/

			size_type							size() const{
				return (this->_size);
			}
			size_type							max_size() const{
				return (std::numeric_limits<size_type>::max()/sizeof(value_type));
			}
			// // void								resize (size_type n, value_type val = value_type()){
			// // }
			size_type 							capacity() const{
				return (this->_capacity);
			}
			bool								empty() const{
				return (!this->_size);
			}
			void								reserve (size_type n){
				if (n > this->_capacity){
					pointer tmp = new value_type[n];
					for (size_type i = 0; i < this->_size; i++) 
						tmp[i] = this->_array[i];
					delete[] this->_array;
					this->_array = tmp;
					this->_capacity = n;
				}
			}

			/**************************************************
			****************** Element Access *****************
			**************************************************/

			// reference 							operator[](size_type n){
			// 	return (this->_array[n]);
			// }
			// const_reference 					operator[](size_type n) const{
			// 	return (this->_array[n]);
			// }
			// reference 							at(size_type n){
			// }
			// const_reference 					at(size_type n) const{
			// }
			reference 							front(){
				return (this->_array[0]);
			}
			const_reference 					front() const{
				return (this->_array[0]);
			}
			reference							back(){
				return (this->_array[this->_size - 1]);
			}
			const_reference						back() const{
				return (this->_array[this->_size - 1]);
			}

			/**************************************************
			******************** Modifiers ********************
			**************************************************/

			template <class InputIterator>
			void 								assign(InputIterator first, InputIterator last){
				if (this->_size)
					this->clear();
				while (first != last){
					this->push_back(*first);
					first++;
				}
			}
			void								assign(size_type n, const value_type& val){
				if (this->_size)
					this->clear();
				for (size_t i = 0; i < n; i++)
					push_back(val);
			}
			void								assign(int n, const value_type& val){
				if (this->_size)
					this->clear();
				for (int i = 0; i < n; i++)
					push_back(val);
			}
			void 								push_back (const value_type& val){
				if (this->_size == this->_capacity){
					if (this->_size == 0)
						reserve(1);
					else
						reserve(this->_capacity * 2);
				}
				this->_array[this->_size] = val;
				this->_size++;
			}
			void 								pop_back(void){
				this->_size--;
			}
			Iterator							insert (Iterator position, const value_type& val){
				
				size_t count = 0;
				value_type val2;

				while (position-- != this->begin())
					count++;

				if (this->_size + 1 > this->_capacity)
					reserve(this->_size + 1);
				
				this->_size += 1;
				std::swap(val2, this->_array[count]);		
				while (&this->_array[count] != &this->_array[this->_size]){
					std::swap(val2, this->_array[count++]);		
				}
				this->_array[count] = val;
				return (Iterator(this->_array));
			}	
			void								insert (Iterator position, size_type n, const value_type& val){
				while (n--)
					insert(position, val);
			}
			void								insert (Iterator position, int n, const value_type& val){
				while (n--)
					insert(position, val);
			}
			template <class InputIterator>
			void								insert (Iterator position, InputIterator first, InputIterator last){
				for (;first != last; first++){
					std::cout << *first << std::endl;
					position = insert(position, *first);
				}
			}
			// Iterator							erase (Iterator position){
			// }
			// Iterator							erase (Iterator first, Iterator last){
			// }
			// void								swap (vector& x){
			// }
			void								clear(void){
				if (this->_array != NULL)
					delete[] this->_array;
			}
		
		private :
			pointer								_array;
			size_type							_size;
			size_type							_capacity;
			allocator_type						_al;

	};
}
#endif

/**************************************************
*********  Non-member function overloads  *********
**************************************************/

// template <class T, class Alloc>
//   bool operator== (const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs){
//   }
// template <class T, class Alloc>
//   bool operator!= (const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs){
//   }
// template <class T, class Alloc>
//   bool operator<  (const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs){
//   }
// template <class T, class Alloc>
//   bool operator<= (const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs){
//   }
// template <class T, class Alloc>
//   bool operator>  (const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs){
//   }
// template <class T, class Alloc>
//   bool operator>= (const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs){
//   }
// template <class T, class Alloc>
//   void swap (vector<T,Alloc>& x, vector<T,Alloc>& y){
//   }
