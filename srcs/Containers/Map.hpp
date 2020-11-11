/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbertola <cbertola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 11:25:32 by cbertola          #+#    #+#             */
/*   Updated: 2020/11/11 11:27:15 by cbertola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef MAP_HPP
#define MAP_HPP
#include "../Headers/Header.hpp"
#include <map>

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
			typedef BidirectionalIterator<value_type>				Iterator;
			typedef T												&reference;
			typedef const T&										const_reference;
			typedef T*												pointer;
			typedef const T*										const_pointer;
			typedef const Iterator 									const_Iterator;
			typedef size_t											size_type;
			typedef ReverseBidirectionalIterator<value_type> 		reverse_Iterator;
			typedef ReverseBidirectionalIterator<const T>			const_reverse_Iterator;
			typedef std::ptrdiff_t 									difference_type;

			class value_compare
			{ 
				friend class map;
				
				protected:
					Compare comp;
					value_compare (Compare c) : comp(c) {}  // constructed with map's comparison object
				
				public:
					typedef bool result_type;
					typedef value_type first_argument_type;
					typedef value_type second_argument_type;

					bool operator() (const value_type& x, const value_type& y) const
					{
						return comp(x.first, y.first);
					}
			};

			/**************************************************
			****************** Form Coplien *******************
			**************************************************/

			explicit 									map(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()){
				this->_begin = new maillon<value_type>;
				memset(this->_begin, 0, sizeof(maillon<value_type>));
				this->_begin->ptr = reinterpret_cast<value_type *>(&this->_size);
				this->_begin->prev = this->_begin;
				this->_begin->next = this->_begin;
				this->_al = alloc;
				this->_comp = comp;
			}

			template<class InputIterator>
			map(InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()){
				this->_begin = new maillon<value_type>;
				memset(this->_begin, 0, sizeof(maillon<value_type>));
				this->_begin->ptr = reinterpret_cast<value_type *>(&this->_size);
				this->_begin->prev = this->_begin;
				this->_begin->next = this->_begin;
				this->_al = alloc;
				this->_comp = comp;
				insert(first, last);
			}

			map(const map &objmap){
				this->_begin = new maillon<value_type>;
				memset(this->_begin, 0, sizeof(maillon<value_type>));
				this->_begin->ptr = reinterpret_cast<value_type *>(&this->_size);
				this->_begin->prev = this->_begin;
				this->_begin->next = this->_begin;
				operator=(objmap);
			}

			~map(void){
				 clear();
				 delete this->_begin;
			}

			map											&operator=(const map &objmap){
				this->clear();
				this->_begin = NULL;
				this->_size = 0;
				if (this != &objmap){
					if (objmap._size == 0)
						insert(objmap.begin(), objmap.end());
					this->_size = objmap._size;
					this->_comp = objmap._comp;
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
				return (this->_begin);
			}
			const_Iterator 								end() const{
				return (this->_begin);
			}
			reverse_Iterator							rbegin(){
								maillon<value_type> *tmp = this->_begin;
				while (tmp && tmp->right != NULL)
					tmp = tmp->right;
				return (tmp);
			}
			const_reverse_Iterator 						rbegin() const{
								maillon<value_type> *tmp = this->_begin;
				while (tmp && tmp->right != NULL)
					tmp = tmp->right;
				return (tmp);
			}
			reverse_Iterator							rend(){
				return (this->_begin);
			}
			const_reverse_Iterator 						rend() const{
				return (this->_begin);
			}
	
			/**************************************************
			********************* Capacity ********************
			**************************************************/

			bool										empty(void) const {
				return (!this->size());
			}

			size_type									size(void) const {
				return (this->_size);
			}

			size_type									max_size() const{
				return (std::numeric_limits<std::size_t>::max() / sizeof(this->_begin));
			}

			/**************************************************
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

				if (this->size() && this->_begin->next != this->_begin && (it = this->find(val.first)) != this->end())
					return (std::make_pair(it, false));
				it = insert(this->_begin, val);
							
				return (std::make_pair(it, true));
			}
			Iterator 									insert(Iterator position, const value_type& val){

					maillon<value_type> *tmp = new maillon<value_type>;
					memset(tmp, 0, sizeof(maillon<value_type>));
					tmp->ptr = this->_al.allocate(1);
					this->_al.construct(tmp->ptr, val);
					this->_size += 1;


					maillon<value_type> *cpy = this->begin().get_it();
					if ((*cpy->ptr).first > (*tmp->ptr).first)
					{
						tmp->prev = this->_begin;
						tmp->next = cpy;
						cpy->prev = tmp;
						this->_begin->next = tmp;
					}
					else
					{
						while (cpy != this->_begin && (*cpy->ptr).first < (*tmp->ptr).first)
							cpy = cpy->next;
						tmp->prev = cpy->prev;
						tmp->next = cpy;
						cpy->prev->next = tmp;
						cpy->prev = tmp;
					}
				
					std::cout << RED << "test ici" << RESET << std::endl;
					if (this->size() > 1){
						maillon<value_type> *cpyTree = this->_begin->next;
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
					}
					position = tmp;

				return (position);
			}

			template <class InputIterator>
			void 										insert(InputIterator first, InputIterator last){
				while (first != last){
					insert(*first);
					first++;
				}
			}
			void 										erase(Iterator position) {
				maillon<value_type> *tmp = position.get_it();
				tmp->prev->next = tmp->next;
				tmp->next->prev = tmp->prev;


				// arbre
				if (tmp->right) {
					maillon<value_type> *tmpi = this->upper_bound(tmp->ptr->first).get_it();
					for (Iterator ite = this->begin(); ite != this->end(); ite++) {
						if (ite.get_it()->left == tmpi)
							ite.get_it()->left = NULL;
						else if (ite.get_it()->right == tmpi)
							ite.get_it()->right = NULL;
					}
					if (tmp != this->_begin->next)
						(position--).get_it()->left = tmpi;
					else
						this->_begin->next = tmpi;
					tmpi->left = tmp->left;
					tmpi->right = tmp->right;
				} else if(tmp && tmp->left){
					if (tmp != this->_begin->next)
						(position--).get_it()->left = tmp->left;
					else
						this->_begin->next->next = tmp->left;
				}
				this->_al.deallocate(tmp->ptr, 1);
				tmp->ptr = NULL;
				delete tmp;
				tmp = NULL;					
				this->_size -= 1;
			}
			size_type 									erase(const key_type& k) {
				size_t	tmpsize = this->_size;
				
				this->erase(this->find(k));
				return (tmpsize - this->_size);
			}
			void										erase(Iterator first, Iterator last) {
				Iterator	tmp;

				while (first != last) {
					tmp = first;
					first++;
					erase(tmp);
				}
			}
			void 										swap(map& x){
				std::swap(x._begin, this->_begin);
				std::swap(x._size, this->_size);
				std::swap(x._comp, this->_comp);
				std::swap(x._al, this->_al);
			}
			void										clear(){
				Iterator cpy;
				Iterator it = this->begin();
				
				while (it != this->end()) {
					if (it.get_it()->ptr) {
						this->_al.deallocate(it.get_it()->ptr, 1);
						it.get_it()->ptr = NULL;
					}
					cpy = it;
					it++;
					delete cpy.get_it();
				}
				this->_size = 0;
			}
			/**************************************************
			******************** Observers ********************
			**************************************************/

			key_compare 								key_comp() const{
				return (this->_comp);
			}
			value_compare 								value_comp(void) const{
				return value_compare(this->_comp);
			}
			
			/**************************************************
			******************** Operations *******************
			**************************************************/

			Iterator									find(const key_type& k){
				Iterator it = this->begin();

				while (it != this->end() && it->first != k){
					it++;
				}
				return (it);
			}
			const_Iterator								find(const key_type& k) const {
				Iterator it = this->begin();

				while (it != this->end() && it->first != k){
					it++;
				}
				return (it);
			}
			size_type 									count(const key_type& k) const{
				return (this->find(k) != this->end());
			}
			Iterator 									lower_bound(const key_type& k){
				Iterator it = this->begin();

				while (it->first < k){
					it++;
				}
				return (it);
			}
			const_Iterator 								lower_bound(const key_type& k) const{
				Iterator it = this->begin();

				while (it->first < k){
					it++;
				}
				return (it);
			}
			Iterator 									upper_bound(const key_type& k){
				Iterator it = this->begin();

				while (it->first < k && it != this->end())
					it++;
				if (it->first == k)
					it++;
				return (it);
			}
			const_Iterator 								upper_bound(const key_type& k) const{
				Iterator it = this->begin();
				while (it->first < k){
					it++;
				}
				if (it->first == k)
					it++;
				return (it);
			}
			std::pair<const_Iterator,const_Iterator> 	equal_range(const key_type& k) const{
				return (this->equal_range(k));
			}
			std::pair<Iterator,Iterator>             	equal_range(const key_type& k){
				Iterator it = this->lower_bound(k);
				Iterator ite = this->upper_bound(k);
				return (std::make_pair(it,ite));
			}

		private:
			maillon<value_type>							*_begin;
			size_t										_size;
			allocator_type								_al;
			key_compare									_comp;

	};

}

#endif
