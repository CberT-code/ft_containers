
#ifndef MAP_HPP
#define MAP_HPP
#include "../Headers/Header.hpp"

namespace ft
{
	template < class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<std::pair<const Key,T> > >
	class Map
	{
		public:
			typedef Key											key_type;
			typedef T											mapped_type;
			typedef std::pair<const key_type, mapped_type> 		value_type;
			typedef std::less<key_type>							key_compare;
			typedef Alloc 										allocator_type;
			typedef BidirectionalIterator<T>					Iterator;
			typedef T											&reference;
			typedef const T&									const_reference;
			typedef T*											pointer;
			typedef const T*									const_pointer;
			typedef const Iterator 								const_Iterator;
			typedef size_t										size_type;
			typedef ReverseBidirectionalIterator<T> 			reverse_Iterator;
			typedef ReverseBidirectionalIterator<const T>		const_reverse_Iterator;
			typedef std::ptrdiff_t 								difference_type;

			explicit Map(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) {
				this->_al = alloc;
				this->_start = new maillontree<Key, T>();
				this->_start->left = NULL;
				this->_start->right = NULL;
				this->_end = new maillontree<Key, T>();
				this->_end->left = this->_start;
				this->_start->prev = this->_end;
				this->_end->right = NULL;
				this->_end->prev = NULL;
				this->launch = this->_end;
				this->_size = 0;
			}

			Map(const Map &objmap) {
				this->_start = new maillontree<Key, T>();
				this->_end = new maillontree<Key, T>();
				this->launch = this->_end;
				this->_start->left = NULL;
				this->_start->right = NULL;
				this->_end->left = this->_start;
				this->_end->right = NULL;
				this->_end->prev = NULL;
				this->_size = 0;
				*this = objmap;
				return ;
			}

			~Map(void) {
				return ;
			}

			Map		&operator=(const Map &objmap) {
				if (this != &objmap) {

					// clear de la map 

					this->_size = objmap._size;
					this->_al = objmap._al;

					// insert objmap._begin -> objmap._end
				}
				return (*this);
			}

		private:
			maillontree<Key, T>		*_end;
			maillontree<Key, T>		*_start;
			maillontree<Key, T>		*launch;
			size_t					_size;
			allocator_type			_al;
			key_compare				comp;

	};

}

#endif