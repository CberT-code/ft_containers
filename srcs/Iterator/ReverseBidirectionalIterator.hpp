/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ReverseBidirectionalIterator.hpp                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbertola <cbertola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 11:42:49 by cbertola          #+#    #+#             */
/*   Updated: 2020/11/12 11:42:53 by cbertola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSEBIDIRECTIONALITERATOR_H
#define REVERSEBIDIRECTIONALITERATOR_H

#include "../Headers/Header.hpp"
template <typename T>
class ReverseBidirectionalIterator : public ReverseForwardIterator<T>
{
	public:

		/**************************************************
		****************** Form Coplien *******************
		**************************************************/

		ReverseBidirectionalIterator(void){}
		ReverseBidirectionalIterator(ReverseBidirectionalIterator const &src){
			operator=(src);
		}
		ReverseBidirectionalIterator &	operator=( ReverseBidirectionalIterator const &src){
			if (this != &src){
				this->it = src.it;
			}
			return (*this);
		}
		virtual ~ReverseBidirectionalIterator(void){}
		ReverseBidirectionalIterator(maillon<T> *src){
			this->it = src;
		}

		/**************************************************
		********* operator '--a' 'a--' '*a--' *************
		**************************************************/
		ReverseBidirectionalIterator				operator--(int){
			ReverseBidirectionalIterator I = *this;
			if (this->it && this->it->next)
				this->it = this->it->next;
			return (I);
		}
		ReverseBidirectionalIterator				&operator--(void){
			if (this->it && this->it->next)
				this->it = this->it->next;
			return (*this);
		}

};

#endif
