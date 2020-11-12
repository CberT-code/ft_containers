/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ReverseRandomAccessIterator.hpp                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbertola <cbertola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 11:43:23 by cbertola          #+#    #+#             */
/*   Updated: 2020/11/12 11:43:25 by cbertola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSERANDOMACCESSITERATOR_H
#define REVERSERANDOMACCESSITERATOR_H

#include "../Headers/Header.hpp"

template <typename T>
class ReverseRandomAccessIterator
{
	public:

		typedef ptrdiff_t					difference_type;

		/**************************************************
		****************** Form Coplien *******************
		**************************************************/
		ReverseRandomAccessIterator(void){
		}	
		ReverseRandomAccessIterator(ReverseRandomAccessIterator const &src){
			operator=(src);
		}
		ReverseRandomAccessIterator &				operator=( ReverseRandomAccessIterator const &src){
			if (this != &src){
				this->_array = src._array;
			}
			return (*this);
		}
		virtual ~ReverseRandomAccessIterator(void){}
		ReverseRandomAccessIterator(T *src){
			this->_array = src;
		}

		/**************************************************
		*************** operator '==' '!=' ****************
		**************************************************/
		bool								operator==(const ReverseRandomAccessIterator &src) const{
			if (src._array == this->_array)
				return (true);
			return (false);
		}
		bool								operator!=(const ReverseRandomAccessIterator &src) const{
			return (!operator==(src));
		}

		/**************************************************
		************* operator '*a' 'a->m' ****************
		**************************************************/
		T									&operator*(void){
			return (*this->_array);
		}
		T									*operator->(void){
			return (*this->_array);
		}

		/**************************************************
		********* operator '++a' 'a++' '*a++' *************
		**************************************************/
		ReverseRandomAccessIterator				operator++(int){
			ReverseRandomAccessIterator I = *this;
			--this->_array;
			return (I);
		}
		ReverseRandomAccessIterator				operator++(void){
			--this->_array;
			return (*this);
		}
		T									*get_it(void) const{
			return (this->_array);
		}

		/**************************************************
		********* operator '--a' 'a--' '*a--' *************
		**************************************************/
		ReverseRandomAccessIterator				operator--(int){
			ReverseRandomAccessIterator I = *this;
			++this->_array;
			return (I);
		}
		ReverseRandomAccessIterator				&operator--(void){
			++this->_array;
			return (*this);
		}

		/**************************************************
		***** operator 'a + n' 'n + a' 'a - n' 'a - b' ****
		**************************************************/
		ReverseRandomAccessIterator				operator+(int n) {
			return (this->_array -= n);
		}
		difference_type							operator+(ReverseRandomAccessIterator it) {
			return this->array - it.array;
		}
		ReverseRandomAccessIterator				operator-(int n) {
			return (this->_array += n);
		}
		difference_type							operator-(ReverseRandomAccessIterator it) {
			return (this->array + it.array);
		}

		/**************************************************
		*** operator 'a < b' 'a > b' 'a <= b' 'a >= b' ****
		**************************************************/
		bool								operator<(const ReverseRandomAccessIterator& rhs) const {
			return (this->array < rhs.array);
		}
		bool								operator>(const ReverseRandomAccessIterator& rhs) const {
			return (this->array > rhs.array);
		}
		bool								operator<=(const ReverseRandomAccessIterator& rhs) const {
			return (this->array <= rhs.array);
		}
		
		bool								operator>=(const ReverseRandomAccessIterator& rhs) const {
			return (this->array >= rhs.array);
		}

		/**************************************************
		************ operator 'a += n' 'a -= n' ***********
		**************************************************/
		ReverseRandomAccessIterator				operator+=(difference_type n) {
			this->array -= n;
			return (*this);
		}
		ReverseRandomAccessIterator				operator-=(difference_type n) {
			this->array += n;
			return (*this);
		}

		/**************************************************
		***************** operator 'a[n]' *****************
		**************************************************/
		ReverseRandomAccessIterator				operator[](int n) {
			return (this->_array[n]);
		}
		ReverseRandomAccessIterator							operator[](difference_type n) {
			return (*(this->array - n));
		}
	private:
		T*			_array;
};

#endif
