
#ifndef VECTOR_BOOL_H
#define VECTOR_BOOL_H
#include "../Headers/Header.hpp"

namespace ft
{
	template<>
	class vector <bool>
	{

		public:

			typedef bool 											value_type;
			typedef std::allocator<bool>							allocator_type;
			typedef RandomAccessIterator<bool>						Iterator;
			typedef bool &											reference;
			typedef const bool&										const_reference;
			typedef bool*											pointer;
			typedef const bool*										const_pointer;
			typedef const Iterator 									const_Iterator;
			typedef size_t											size_type;
			typedef ReverseRandomAccessIterator<bool> 				reverse_Iterator;
			typedef ReverseRandomAccessIterator< const bool>		const_reverse_Iterator;
			typedef std::ptrdiff_t 									difference_type;

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
				this->_array = new bool[1];
				this->_capacity = 1;
				this->_size = 0;
				assign(n, val);
			}
			explicit 							vector (int n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()){
				this->_al = alloc;
				this->_array = new bool[1];
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
					this->_array = new bool[src._capacity];
					this->_capacity = src._capacity;
					this->_size = src._size;
				}
				return (*this);
			}
			void								aff(void){
				size_t i = 0;
				while (i < this->_size)
					std::cout << GREEN << this->_array[i++] << RESET << std::endl;
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
				return (1073741823);
			}
			void								resize (size_type n, value_type val = value_type()){
				if (n <= this->_size)
					this->_size = n;
				while (n > this->_size)
					push_back(val);
			}
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

			reference 							operator[](size_type n){
				return (this->_array[n]);
			}
			const_reference 					operator[](size_type n) const{
				return (this->_array[n]);
			}
			reference 							at(size_type n){
				return (this->_array[n]);
			}
			const_reference 					at(size_type n) const{
				return (this->_array[n]);
			}
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
				
				size_t i = this->_size - 1;
				size_t j = 0;
				bool	tmp[this->_size];

				for (Iterator it = this->end(); position != it; it--)
					tmp[j++] = this->_array[i--];

				if (this->_size + 1 > this->_capacity)
					reserve(this->_size + 1);

				this->_size += 1;
				i = 0;
				for (size_t size = this->_size ; i < j; i++)
					this->_array[--size] = tmp[i];

				this->_array[this->_size - 1 - i] = val;

				return (Iterator(&this->_array[this->_size - i - 1]));
			}	
			void								insert (Iterator position, size_type n, const value_type& val){
				while (n--){
					position = insert(position, val);
					position++;
				}
			}
			void								insert (Iterator position, int n, const value_type& val){
				while (n--){
					position = insert(position, val);
					position++;
				}
			}
			template <class InputIterator>
			void								insert (Iterator position, InputIterator first, InputIterator last){
				for (;first != last; first++){
					position = insert(position, *first);
					position++;
				}
			}
			Iterator							erase (Iterator position){
				return (erase(position, position));
			}
			Iterator							erase (Iterator first, Iterator last){
				bool	*tmp = new bool[this->_size];
				size_t i = 0;

				for (Iterator it = this->begin(); it != first; it++, i++)
					tmp[i] = this->_array[i];

				size_t j = i;
				while (first++ != last)
					j++;

				j = j == i ? j + 1 : j;
				while (j < this->_size)
					tmp[i++] = this->_array[j++];

				delete [] this->_array;
				this->_array = tmp;
				this->_size -= (j - i);

				return (Iterator(&this->_array[j - i]));
				
			}
			void								swap (vector& x){
				std::swap(this->_array, x._array);
				std::swap(this->_size, x._size);
				std::swap(this->_capacity, x._capacity);
			}
			void								clear(void){
				if (this->_array != NULL)
					delete[] this->_array;
				this->_array = NULL;
				this->_size = 0;
				this->_capacity = 0;
			}

			void 								flip(){
				for (size_t i = 0; i < this->_size; i++){
					this->_array[i] = this->_array[i] == 1 ? 0 : 1;
				}
			}
			static void 						swap (reference ref1, reference ref2){
				std::swap(ref1, ref2);
			}
		private :
			pointer								_array;
			size_type							_size;
			size_type							_capacity;
			allocator_type						_al;

	};
}

/**************************************************
*********  Non-member function overloads  *********
**************************************************/

template <bool, class Alloc>
	bool operator== (const ft::vector<bool,Alloc>& lhs, const ft::vector<bool,Alloc>& rhs){
	  	if (lhs.size() != rhs.size())
			return false;
		RandomAccessIterator<bool>	itr = rhs.begin();
		RandomAccessIterator<bool>	itl = lhs.begin();

		while (itr != rhs.end())
		{
			if (*itr != *itl)
				return (false);
			itr++;
			itl++;
		}
		return true;
	}
template <bool, class Alloc>
  	bool operator!= (const ft::vector<bool,Alloc>& lhs, const ft::vector<bool,Alloc>& rhs){
		return (!operator==(lhs, rhs));
  	}
template <bool, class Alloc>
 	bool operator<  (const ft::vector<bool,Alloc>& lhs, const ft::vector<bool,Alloc>& rhs){
		if (lhs.size() < rhs.size())
			return true;
		else if (rhs.size() > lhs.size())
			return false;
		RandomAccessIterator<bool>	itr = rhs.begin();
		RandomAccessIterator<bool>	itl = lhs.begin();

		while (itr != rhs.end())
		{
			if (*itl < *itr)
				return (true);
			itr++;
			itl++;
		}
		return false;
  	}
template <bool, class Alloc>
  	bool operator<= (const ft::vector<bool,Alloc>& lhs, const ft::vector<bool,Alloc>& rhs){
		if (operator<(lhs, rhs) || operator==(lhs, rhs))
			return (true);
		return (false);
  	}
template <bool, class Alloc>
  	bool operator>  (const ft::vector<bool,Alloc>& lhs, const ft::vector<bool,Alloc>& rhs){
		return (!operator<=(lhs,rhs));
  	}
template <bool, class Alloc>
  	bool operator>= (const ft::vector<bool,Alloc>& lhs, const ft::vector<bool,Alloc>& rhs){
		return (!operator<(lhs, rhs));
  	}
template <bool, class Alloc>
  	void swap(ft::vector<bool,Alloc>& x, ft::vector<bool,Alloc>& y){
		x->swap(y);
  	}

#endif