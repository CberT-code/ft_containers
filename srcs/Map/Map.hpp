
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

			template<class InputIterator>
			Map(InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) {

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

			iterator	begin(void) const {
				return (this->_start->get_it());
			}

			iterator	end(void) const {
				return (this->_end->get_it());
			}

			reverse_Iterator	rbegin(void) const {
				return (this->end());
			}

			reverse_Iterator	rend(void) const {
				return (this->begin());
			}

			const_Iterator		cbegin(void) const {
				return (this->_start->get_it());
			}

			const_Iterator		cend(void) const {
				return (this->_end->get_it());
			}

			reverse_Iterator	crbegin(void) const {
				return (this->cend());
			}

			reverse_Iterator	crend(void) const {
				return (this->cbegin());
			}

			bool		empty(void) const {
				return (!this->_size);
			}

			size_type	size(void) const {
				return (this->_size);
			}

			size_type	max_size() const{
				return (std::numeric_limits<std::size_t>::max() / sizeof(this->launch));
			}

			std::pair<iterator, bool> insert(const value_type &val) {
				if (this->_size == 0) {
					this->_al->allocate(this->launch->ptr, 1);
					this->_al->construct(this->launch->ptr, val);
					this->_size += 1;
					return (std::make_pair(this->launch->get_it(), true));
				} else {
					if (this->_size == 1 && this->launch->ptr > val) {
						this->_al->allocate(this->_start->ptr, 1);
						this->_al->construct(this->_start->ptr, val);
						this->_size += 1;
						return (std::make_pair(this->_start->get_it(), true));
					}
				}
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