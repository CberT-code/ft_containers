/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbertola <cbertola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 09:22:09 by cbertola          #+#    #+#             */
/*   Updated: 2020/10/21 14:53:31 by cbertola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "../Headers/Header.hpp"
#include <algorithm>
#include <list>
#include <array>
#include <vector>
#include <iostream>
#include <set>
int main(int argc, char const *argv[])
{

	// std::cout << "*************** Test vrai list ***************" << std::endl;
	// std::list<int> toto(4, 15);
	// std::list<int>::iterator::iterator_category::forward_iterator_tag titi = toto.begin() ;
	
	// std::cout << *titi << std::endl; 
	// std::cout << *(titi++)<< std::endl; 
	// std::cout << *(titi++) << std::endl; 
	// std::cout << *(titi++)<< std::endl; 
	// std::cout << *(titi++)<< std::endl; 
	// std::cout << *(titi++)<< std::endl; 
	// std::cout << *(titi++)<< std::endl; 
	// std::cout << *(titi++)<< std::endl; 
 
	std::cout << "*************** Test vrai list ***************" << std::endl;
	std::vector<int> titi = std::vector<int>(2,8);
	std::vector<int>::iterator ite = titi.begin();
	std::cout << &ite << std::endl;

	std::cout << titi.max_size() << std::endl;
	std::cout << &ite << std::endl;
	std::cout << titi[0] << std::endl;
	titi.push_back(42);
	std::cout << titi[0] << std::endl;
	//titi.push_front(42);
	// ite = titi.begin();
	std::cout << &ite << std::endl;
	// for (size_t i = 0; i < titi.size(); i++)
	// {
	// 	std::cout << *ite + i << std::endl;
	// }
	// titi.insert(ite, 8);
	// for (size_t i = 0; i < titi.size(); i++)
	// {
	// 	std::cout << *ite + i << std::endl;
	// }
	

	std::cout << "*************** Test ft list ***************" << std::endl;
	ft::list<int> tata = ft::list<int>(4, 10);
	tata.aff();
	std::cout << "*************** Test ft list ***************" << std::endl;
	tata.push_front(450);
	tata.push_front(370);
	tata.aff();
	std::cout << "*************** Test ft list ***************" << std::endl;
	tata.pop_front();
	tata.aff();
	std::cout << "*************** Test ft list ***************" << std::endl;
	tata.push_back(125);
	tata.push_back(687);
	tata.aff();
	std::cout << "*************** Test ft list ***************" << std::endl;
	tata.pop_back();
	tata.aff();

	// ft::list<int>::Iterator it;
	// std::cout << &it << std::endl;
	// for (size_t i = 0; i < tata.size(); i++)
	// {
		// std::cout << it << std::endl;
	// }
	// std::cout << tata.insert() << std::endl;
	// std::cout << tata.max_size() << std::endl;


	// std::cout << *tita << std::endl; 
	// tata.push_back(8);
	
	// toto.

	
	// std::cout << toto << std::endl;
	// ForwardIterator<int> toto = ForwardIterator<int>();
	// std::cout << *toto << std::endl;
	return 0;
}
