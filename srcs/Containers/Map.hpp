/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbertola <cbertola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 11:25:32 by cbertola          #+#    #+#             */
/*   Updated: 2020/11/06 11:25:33 by cbertola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


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
				this->_end = new maillontree<Key, T>();
				this->_start->left = _end;
				this->_start->right = NULL;
				this->_start->prev = NULL;
				this->_end->right = NULL;
				this->_end->prev = this->_start;
				this->launch = this->start;
				this->_size = 0;
			}

			template<class InputIterator>
			Map(InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) {

			}

			Map(const Map &objmap) {
				this->_al = alloc;
				this->_start = new maillontree<Key, T>();
				this->_end = new maillontree<Key, T>();
				this->_start->left = _end;
				this->_start->right = NULL;
				this->_start->prev = NULL;
				this->_end->right = NULL;
				this->_end->prev = this->_start;
				this->launch = this->start;
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

			void		clear() {
				maillontree<Key, T> *tmp = this->launch;

				while (this->_size != 0) {
					for (maillontree<Key, T> *tleft = tmp->left; tmp != NULL;) {
						if (tmp->right) {
							tmp = 
						}
					}
				}
			}

			iterator	find(const key_type& k) {
				maillontree<Key, T> *tmp  = this->launch;
				int					i = 0;
				
				while (i != this->_size) {
					if (*tmp->ptr == val)
						return (iterator(tmp));
					else if (k < *tmp->ptr)
						tmp = tmp->left;
					else
						tmp = tmp->right;
					i++;
				}
				return (tmp->launch);
			}

			const_iterator	find(const key_type& k) const {
				maillontree<Key, T> *tmp  = this->launch;
				int					i = 0;
				
				while (i != this->_size) {
					if (*tmp->ptr == val)
						return (iterator(tmp));
					else if (k < *tmp->ptr)
						tmp = tmp->left;
					else
						tmp = tmp->right;
					i++;
				}
				return (tmp->launch);
			}

			std::pair<iterator, bool> insert(const value_type &val) {
				if (this->_size == 0) {
					this->_al->allocate(this->launch->ptr, 1);
					this->_al->construct(this->launch->ptr, val);
					this->_size += 1;
					return (std::make_pair(this->launch->get_it(), true));
				} else {
					if (this->launch->ptr > val) {
						maillontree<Key, T> new_maillon = new maillontree<Key, T>();
						this->_al->allocate(new_maillon->ptr, 1);
						this->_al->construct(new_maillon->ptr, val);
						new_maillon->left = NULL;
						new_maillon->right = NULL;
						//maillontree<Key, T> *tmp = tm? this->launch->left;
						for (int i = 0; i < this->_size; this->_size++) {
							if (val <= *tmp->ptr) {
								if (tmp->left == NULL) {
									tmp->left = new_maillon;
									tmp->left->prev = tmp;
									return (std::make_pair(tmp->left->get_it(), true));
								} else {
									tmp = tmp->left
								}
							} else {
								if (tmp->right == NULL) {
									tmp->right = new_maillon;
									tmp->right->prev = tmp;
									return (std::make_pair(tmp->right->get_it(), true));
								} else {
									tmp = tmp->right;
								}
							}
						}
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