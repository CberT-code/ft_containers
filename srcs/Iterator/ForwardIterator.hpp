/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ForwardIterator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbertola <cbertola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 11:41:17 by cbertola          #+#    #+#             */
/*   Updated: 2020/11/12 11:41:56 by cbertola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORWARDITERATOR_H
#define FORWARDITERATOR_H

#include "../Headers/Header.hpp"

template <typename T>
struct ForwardIterator : public InputIterator<T>
{
	public :
		/**************************************************
		****************** Form Coplien *******************
		**************************************************/
		ForwardIterator(void){}

};

#endif
