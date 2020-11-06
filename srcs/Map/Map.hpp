
#ifndef MAP_H
#define MAP_H
#include "../Headers/Header.hpp"

namespace ft
{
	template < typename Key,                                     // map::key_type
           typename T,                                       // map::mapped_type
           class Compare = std::less<Key>,                     // map::key_compare
           class Alloc = std::allocator<std::pair<const Key,T> > >
	class map
	{

		public:
			
			typedef Key											key_type;
			typedef T 											mapped_type;
			typedef std::pair<const Key, mapped_type>			value_type;
			typedef Compare										key_compare;
			typedef Alloc 										allocator_type;
			typedef T &											reference;
			typedef const T&									const_reference;
			typedef T*											pointer;
			typedef const T*									const_pointer;
			typedef BidirectionalIterator<T>					Iterator;
			typedef const Iterator 								const_Iterator;
			typedef ReverseBidirectionalIterator<T> 			reverse_Iterator;
			typedef ReverseBidirectionalIterator< const T>		const_reverse_Iterator;
			typedef std::ptrdiff_t 								difference_type;
			typedef size_t										size_type;

			/**************************************************
			****************** Form Coplien *******************
			**************************************************/

			explicit map (const key_compare& comp = key_compare(),
            const allocator_type& alloc = allocator_type()){
				this->_al = alloc;
				this->_key = comp;
				this->_begin = NULL;
				this->_endsize = NULL;
				this->_size = 0;
			}

			template <class InputIterator>
			map (InputIterator first, InputIterator last,
			const key_compare& comp = key_compare(),
			const allocator_type& alloc = allocator_type()){
				this->_al = alloc;
				this->_key = comp;
				this->_begin = NULL;
				this->_endsize = NULL;
				this->_size = 0;
				assign(first, last);

			}
			
			map(const map& x){
				this->_begin = NULL;
				this->_endsize = NULL;
				this->_size = 0;
				operator=(x);
			}
			virtual 							~map(void){
				clear();
			}
			map &								operator=( map const &src){
				this->clear();
				if (this != &src){
					this->_size = src._size;
					assign(src.begin(), src.end());
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
			************** begin end rbegin rend **************
			**************************************************/

			Iterator							begin(){
				return (this->_begin);
			}
			const_Iterator						begin() const{
				return (this->_begin);
			}
			Iterator							end(){	
				return (this->_endsize);
			}
			const_Iterator						end() const{
				return (this->_endsize);
			}
			reverse_Iterator 					rbegin(){
				return (this->_endsize->prev);
			}
			const_reverse_Iterator 				rbegin() const{
				return (this->_endsize->prev);
			}
			reverse_Iterator 					rend(){
				return (this->_endsize);
			}
			const_reverse_Iterator 				rend() const{
				return (this->_endsize);
			}

			/**************************************************
			*************** empty size max_endsize->ptr *******
			**************************************************/

			bool								empty() const{
				if (this->_size == 0)
					return  (true);
				return (false);
			}
			size_type							size() const{
				return (this->_size < 2 ? 0 : this->_size - 1);
			}
			size_type							max_size() const{
				return (std::numeric_limits<std::size_t>::max() / sizeof(value_type));
			}

			/**************************************************
			******************** operator[] *******************
			**************************************************/
				
			mapped_type& operator[] (const key_type& k){
				(*((this->insert(make_pair(k,mapped_type()))).first)).second;
			}

			/**************************************************
			* assign push_front pop_front push_back pop_back  *
			********* insert erase swap resize clear **********
			**************************************************/

			void								assign(size_type n, const value_type& val){
				if (this->_begin != NULL)
					this->clear();
				for (size_t i = 0; i < n; i++)
					push_back(val);
			}
			void								assign(int n, const value_type& val){
				if (this->_begin != NULL)
					this->clear();
				for (int i = 0; i < n; i++)
					push_back(val);
			}
			template <class InputIterator>
			void 								assign(InputIterator first, InputIterator last){
				if (this->_begin != NULL)
					this->clear();
				while (first != last){
					this->push_back(*first);
					first++;
				}
			}
			
			Iterator							insert (Iterator position, const value_type& val){
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
				return (position);
			}	
			void								insert (Iterator position, size_type n, const value_type& val){
				while (n--){
					insert(position, val);
				}
			}
			void								insert (Iterator position, int n, const value_type& val){
				while (n--){
					insert(position, val);
				}
			}
			template <class InputIterator>
			void								insert (Iterator position, InputIterator first, InputIterator last){
				while (first != last){
					insert(position, first);
					first++;
				}
			}
			Iterator							erase (Iterator position){
				maillon<T> *pos = position.get_it();
				pos->prev->next = pos->next;
				pos->next->prev = pos->prev;
				this->_al.deallocate(pos->ptr, 1);
				position++;
				delete (pos);
				this->_size -= 1;
				return (position);
			}
			Iterator							erase (Iterator first, Iterator last){
				while (first != last)
					first = erase(first);
				return (last);
			}
			void								swap (map& x){
				std::swap(x._begin, this->_begin);
				std::swap(x._endsize, this->_endsize);
				std::swap(x._size, this->_size);
			}

			void								clear(void){
				while (this->_size)
					this->pop_back();
			}

			/**************************************************
			**** splice remove remove_if unique merge sort ****
			********************* reverse *********************
			**************************************************/

			
		
		
		private :
			allocator_type						_al;
			key_compare							_key;
			maillon<T>							*_begin;
			maillon<T>							*_endsize;
			size_t								_size;
	};
}



template <class T, class Alloc>
	bool operator== (const ft::map<T,Alloc>& lhs, const ft::map<T,Alloc>& rhs){
		
		if (lhs.size() != rhs.size())
			return false;
		BidirectionalIterator<T>	itr = rhs.begin();
		BidirectionalIterator<T>	itl = lhs.begin();

		while (itr != rhs.end())
		{
			if (*itr != *itl)
				return (false);
			itr++;
			itl++;
		}
		return true;
	}

template <class T, class Alloc>
	bool operator!= (const ft::map<T,Alloc>& lhs, const ft::map<T,Alloc>& rhs){
		if (!operator==(lhs, rhs))
			return true;
		return false;
	}

template <class T, class Alloc>
	bool operator<  (const ft::map<T,Alloc>& lhs, const ft::map<T,Alloc>& rhs){
		if (lhs.size() < rhs.size())
			return true;
		else if (rhs.size() > lhs.size())
			return false;
		BidirectionalIterator<T>	itr = rhs.begin();
		BidirectionalIterator<T>	itl = lhs.begin();

		while (itr != rhs.end())
		{
			if (*itl < *itr)
				return (true);
			itr++;
			itl++;
		}
		return false;
	}

template <class T, class Alloc>
	bool operator<= (const ft::map<T,Alloc>& lhs, const ft::map<T,Alloc>& rhs){
		if (operator<(lhs, rhs) || operator==(lhs, rhs))
			return (true);
		return (false);
	}

template <class T, class Alloc>
	bool operator>  (const ft::map<T,Alloc>& lhs, const ft::map<T,Alloc>& rhs){
		if (lhs.size()	> rhs.size())
			return true;
		else if (rhs.size() < lhs.size())
			return false;
		BidirectionalIterator<T>	itr = rhs.begin();
		BidirectionalIterator<T>	itl = lhs.begin();

		while (itr != rhs.end())
		{
			if (*itl > *itr)
				return (true);
			itr++;
			itl++;
		}
		return false;
	}

template <class T, class Alloc>
	bool operator>= (const ft::map<T,Alloc>& lhs, const ft::map<T,Alloc>& rhs){
		if (operator>(lhs, rhs) || operator==(lhs, rhs))
			return (true);
		return (false);
	}

template <class T, class Alloc>
  void swap (ft::map<T,Alloc>& x, ft::map<T,Alloc>& y){
	  x->swap(y);
  }
#endif
