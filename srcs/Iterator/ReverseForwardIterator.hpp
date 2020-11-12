/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ReverseForwardIterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbertola <cbertola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 11:43:06 by cbertola          #+#    #+#             */
/*   Updated: 2020/11/12 11:43:09 by cbertola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSEFORWARDITERATOR_H
#define REVERSEFORWARDITERATOR_H

#include "../Headers/Header.hpp"

template <typename T>
struct ReverseForwardIterator : public ReverseInputIterator<T>
{
	/**************************************************
	****************** Form Coplien *******************
	**************************************************/
	public :
		ReverseForwardIterator(void){}

};

#endif
