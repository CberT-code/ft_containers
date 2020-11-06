/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbertola <cbertola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 11:25:32 by cbertola          #+#    #+#             */
/*   Updated: 2020/11/06 16:18:56 by cbertola         ###   ########.fr       */
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
			typedef BidirectionalIterator<T>						Iterator;
			typedef T												&reference;
			typedef const T&										const_reference;
			typedef T*												pointer;
			typedef const T*										const_pointer;
			typedef const Iterator 									const_Iterator;
			typedef size_t											size_type;
			typedef ReverseBidirectionalIterator<T> 				reverse_Iterator;
			typedef ReverseBidirectionalIterator<const T>			const_reverse_Iterator;
			typedef std::ptrdiff_t 									difference_type;

			/**************************************************
			****************** Form Coplien *******************
			**************************************************/

			explicit 					map(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()){
			}

			template<class InputIterator>
			map(InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()){

			}

			map(const map &objmap){
			}

			~map(void){
			}

			map							&operator=(const map &objmap){
			}

			/**************************************************
			******************** Iterators ********************
			**************************************************/

			Iterator					begin(void) const {
			}
			const_iterator 				begin() const{
			}
			Iterator					end(void) const {
			}
			const_iterator 				end() const{
			}
			reverse_Iterator			rbegin(void) const {
			}
			const_reverse_iterator 		rbegin() const{
			}
			reverse_Iterator			rend(void) const {
			}
			const_reverse_iterator 		rend() const{
			}
	
			/**************************************************
			********************* Capacity ********************
			**************************************************/

			bool						empty(void) const {
			}

			size_type					size(void) const {
			}

			size_type					max_size() const{
				return (std::numeric_limits<std::size_t>::max() / sizeof(this->launch));
			}

			/**************************************************
			****************** Element Access *****************
			**************************************************/

			mapped_type& 				operator[] (const key_type& k){
			}

			/**************************************************
			******************** Modifiers ********************
			**************************************************/

			pair<Iterator, bool> 		insert(const value_type &val){
			}
			iterator 					insert (iterator position, const value_type& val){
			}
			void 						insert (InputIterator first, InputIterator last){
			}
			void 						erase (iterator position){
			}
			size_type 					erase (const key_type& k){
			}
     		void 						erase (iterator first, iterator last){
	 		}
			void 						swap (map& x){
			}
			void						clear(){
			}

			/**************************************************
			******************** Observers ********************
			**************************************************/

			key_compare 				key_comp() const{
			}
			value_compare 				value_comp() const{
			}
			
			/**************************************************
			******************** Operations *******************
			**************************************************/

			Iterator					find(const key_type& k){
			}

			const_Iterator				find(const key_type& k) const {
			}

		private:
			maillon<value_type>			*_begin;
			maillon<value_type>			*_endsize;
			size_t						_size;
			allocator_type				_al;

	};

}

#endif