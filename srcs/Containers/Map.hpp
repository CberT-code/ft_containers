/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 11:25:32 by cbertola          #+#    #+#             */
/*   Updated: 2020/11/09 15:06:24 by cbertola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef MAP_HPP
#define MAP_HPP
#include "../Headers/Header.hpp"

namespace ft
{
	template < class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<std::pair<const Key,T> > >
	class map
	{
		public:
			typedef Key												key_type;
			typedef T												mapped_type;
			typedef std::pair<const key_type, mapped_type> 			value_type;
			typedef std::less<key_type>								key_compare;
			typedef Alloc 											allocator_type;
			typedef BidirectionalIterator<value_type>						Iterator;
			typedef T												&reference;
			typedef const T&										const_reference;
			typedef T*												pointer;
			typedef const T*										const_pointer;
			typedef const Iterator 									const_Iterator;
			typedef size_t											size_type;
			typedef ReverseBidirectionalIterator<value_type> 				reverse_Iterator;
			typedef ReverseBidirectionalIterator<const T>			const_reverse_Iterator;
			typedef std::ptrdiff_t 									difference_type;

			/**************************************************
			****************** Form Coplien *******************
			**************************************************/

			explicit 									map(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()){
				//Creation begin
				this->_begin = new maillon<value_type>;
				memset(this->_begin, 0, sizeof(maillon<value_type>));
				this->_begin->ptr = NULL;

				//Creation endsize
				this->_endsize = new maillon<value_type>;
				memset(this->_endsize, 0, sizeof(maillon<value_type>));
				this->_endsize->ptr = reinterpret_cast<value_type *>(&this->_size);

				//pointeurs
				this->_begin->prev = this->_endsize;
				this->_begin->next = this->_endsize;
				this->_endsize->prev = this->_begin;
				this->_endsize->next = this->_begin;
				this->_size = 2;
				this->_al = alloc;
				this->_comp = comp;
			}

			template<class InputIterator>
			map(InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()){
				this->_al = alloc;
				this->_comp = comp;
				this->_begin = NULL;
				this->_endsize = NULL;
				this->_size = 0;
				insert(first, last);
			}

			map(const map &objmap){
				this->_begin = NULL;
				this->_endsize = NULL;
				this->_size = 0;
				operator=(objmap);
			}

			~map(void){
				clear();
			}

			map											&operator=(const map &objmap){
				this->clear();
				if (this != &objmap){
					this->_size = objmap._size;
					insert(objmap.begin(), objmap.end());
				}
				return (*this);
			}

			/**************************************************
			******************** Iterators ********************
			**************************************************/

			Iterator									begin(){
				maillon<value_type> *tmp = this->_begin;
				while (tmp && tmp->left != NULL)
					tmp = tmp->left;
				return (tmp);
			}
			const_Iterator 								begin() const{
				maillon<value_type> *tmp = this->_begin;
				while (tmp && tmp->left != NULL)
					tmp = tmp->left;
				return (tmp);
			}
			Iterator									end(){
				return (this->_endsize);
			}
			const_Iterator 								end() const{
				return (this->_endsize);
			}
			reverse_Iterator							rbegin(){
				return (this->end());
			}
			const_reverse_Iterator 						rbegin() const{
				return (this->end());
			}
			reverse_Iterator							rend(){
				return (this->begin());
			}
			const_reverse_Iterator 						rend() const{
				return (this->begin());
			}
	
			/**************************************************
			********************* Capacity ********************
			**************************************************/

			bool										empty(void) const {
				return (this->_begin == NULL);
			}

			size_type									size(void) const {
				return (this->_size - 1);
			}

			size_type									max_size() const{
				return (std::numeric_limits<std::size_t>::max() / sizeof(this->_begin));
			}

			/**************************a	a************************
			****************** Element Access *****************
			**************************************************/

			mapped_type& 								operator[] (const key_type& k){
				return insert(std::make_pair(k, mapped_type())).first->second;
			}

			/**************************************************
			******************** Modifiers ********************
			**************************************************/

			std::pair<Iterator, bool> 					insert(const value_type &val){
				Iterator it;

				it = insert(this->_begin, val);
				return (std::make_pair(it, true));
			}
			Iterator 									insert (Iterator position, const value_type& val){
				if (this->_begin->ptr == NULL){
					this->_begin->ptr = this->_al.allocate(1);
					this->_al.construct(this->_begin->ptr, val);
				}
				else if (this->_begin == NULL ){
					//Creation begin
					memset(this->_begin, 0, sizeof(maillon<value_type>));
					this->_begin->ptr = this->_al.allocate(1);
					this->_al.construct(this->_begin->ptr, val);

					//Creation endsize
					this->_endsize = new maillon<value_type>;
					memset(this->_endsize, 0, sizeof(maillon<value_type>));
					this->_endsize->ptr = reinterpret_cast<value_type *>(&this->_size);

					//pointeurs
					this->_begin->prev = this->_endsize;
					this->_begin->next = this->_endsize;
					this->_endsize->prev = this->_begin;
					this->_endsize->next = this->_begin;
					this->_size = 2;
					
				}
				else{
					maillon<value_type> *tmp = new maillon<value_type>;
					memset(tmp, 0, sizeof(maillon<value_type>));
					tmp->ptr = this->_al.allocate(1);
					this->_al.construct(tmp->ptr, val);

					maillon<value_type> *cpy = this->begin().get_it();
					if ((*cpy->ptr).first > (*tmp->ptr).first)
					{
						tmp->prev = this->_endsize;
						tmp->next = cpy;
						cpy->prev = tmp;
						this->_endsize->next = tmp;
					}
					else
					{
						while ((*cpy->ptr).first < (*tmp->ptr).first && cpy != this->_endsize)
							cpy = cpy->next;
						tmp->prev = cpy->prev;
						tmp->next = cpy;
						cpy->prev->next = tmp;
						cpy->prev = tmp;
					}
				
					maillon<value_type> *cpyTree = this->_begin;
					while (cpyTree->right != tmp && cpyTree->left != tmp)
					{
						if ((*cpyTree->ptr).first < (*tmp->ptr).first){
						if (cpyTree->right == NULL)
								cpyTree->right = tmp;
							else
								cpyTree = cpyTree->right;
						}
						else if ((*cpyTree->ptr).first > (*tmp->ptr).first){
							if (cpyTree->left == NULL)
								cpyTree->left = tmp;
							else
								cpyTree = cpyTree->left;
						}
					}
					position = cpy;
				}


				ft::map<char,int>::Iterator it;
				std::cout << YELLOW << "Affichage iterateurs " << RESET << std::endl << std::endl;
  				for (it = this->begin(); it != this->end(); ++it)
   					std::cout << "key = " << it->first << " value = " << it->second << std::endl;
				std::cout << std::endl << std::endl;

				std::cout << GREEN << "Affichage arbre" << RESET << std::endl << std::endl;
				maillon<value_type> *aff = this->_begin;
					if (aff->ptr)
						std::cout << "node = " << (*aff->ptr).first << std::endl;
					if (aff->left)
					 std::cout << "left son = " << (*aff->left->ptr).first << std::endl;
					if (aff->right)
					  std::cout << "right son = " << (*aff->right->ptr).first << std::endl;
					if (aff->right && aff->right->right)
						std::cout << "right right  son = " << (*aff->right->right->ptr).first << std::endl;
				std::cout << std::endl << std::endl;
				getchar();


				return (position);
			}

			template <class InputIterator>
			void 										insert (InputIterator first, InputIterator last){
				while (first != last){
					insert(*first);
					first++;
				}
			}
			// void 									erase (Iterator position){
			// }
			// size_type 								erase (const key_type& k){
			// }
     		// void 									erase (Iterator first, Iterator last){
	 		// }
			// void 									swap (map& x){
			// }
			void										clear(){
				while (this->_size){
					if (this->_size == 2)
					{
						if (this->_begin->ptr) {
							this->_al.deallocate(this->_begin->ptr, 1);
						}
						delete (this->_begin);
						delete (this->_endsize);
						this->_begin = NULL;
						this->_endsize = NULL;
						this->_size = 0;
					}
					else
					{
						maillon<value_type> *replaced = this->_endsize->prev;
						maillon<value_type> *new_end = this->_endsize->prev->prev;
						
						if (replaced->ptr) {
							this->_al.deallocate(replaced->ptr, 1);
						}
						this->_endsize->prev = new_end;
						new_end->next = this->_endsize;
						delete (replaced);
						this->_size -= 1;
					}
				}
			}

			/**************************************************
			******************** Observers ********************
			**************************************************/

			key_compare 								key_comp() const{
				return (this->_comp);
			}
			// value_compare 							value_comp() const{
			// }
			
			/**************************************************
			******************** Operations *******************
			**************************************************/

			Iterator									find(const key_type& k){
				Iterator it = this->begin();

				while (it->first != k && it != NULL)
					it++;
				return (it);
			}
			const_Iterator								find(const key_type& k) const {
				return (this->find(k));
			}
			size_type 									count (const key_type& k) const{
				return (this->find(k) != NULL);
			}
			Iterator 									lower_bound (const key_type& k){
				Iterator it = this->begin();

				while (this->key_comp(*it.first,k.first)){
					it++;
				}
				return (it);
			}
			const_Iterator 								lower_bound (const key_type& k) const{
				return (this->lower_bound(k));
			}
			Iterator 									upper_bound (const key_type& k){
				Iterator it = this->begin();

				while (this->key_comp(it->first, k.first)){
					it++;
				}
				if (it->first == k.first)
					it--;
				return (it);
			}
			const_Iterator 								upper_bound (const key_type& k) const{
				return (this->upper_bound(k));
			}
			std::pair<const_Iterator,const_Iterator> 	equal_range (const key_type& k) const{
				return (this->equal_range(k));
			}
			std::pair<Iterator,Iterator>             	equal_range (const key_type& k){
				Iterator it = this->lower_bound(k);
				Iterator ite = this->upper_bound(k);
				return (std::make_pair(it,ite));
			}

		private:
			maillon<value_type>						*_begin;
			maillon<value_type>						*_endsize;
			size_t									_size;
			allocator_type							_al;
			key_compare								_comp;

	};

}

#endif
