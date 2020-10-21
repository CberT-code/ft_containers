/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbertola <cbertola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 17:04:26 by cbertola          #+#    #+#             */
/*   Updated: 2020/10/19 17:16:54 by cbertola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Headers/Header.hpp"

template <class T, class Container = std::deque<T> >


class stack
{
	public:
		typedef T				value_type;
		typedef Container		Container;
		typedef size_t			size_type;

	private:
		Container			container;

	public:
		stack(const Container &container){
			this->container = container;
		}
		stack(const stack &obj){ 
			if (*this != obj)
				*this = obj;
		};
		virtual ~stack() {
			return ; 
		}
		stack				&operator=(const stack &obj){
			if (*this != obj)
				this->container = obj.container;
			return (*this);
		}

		bool				empty()	const{
			return (container.empty());
		}
		size_t				size()	const{
			return (container.size());
		}
		value_type			&top(){
			return (container.back());
		}
		const value_type	&top()	const{
			return (container.back());
		}
		void				push(value_type &element){
			container.push_back(element);
		}
		void				pop(){
			container.pop_back();
		}
};

