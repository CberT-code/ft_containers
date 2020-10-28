/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbertola <cbertola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 09:22:09 by cbertola          #+#    #+#             */
/*   Updated: 2020/10/28 12:10:44 by cbertola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "../Headers/Header.hpp"
#include <algorithm>
#include <list>
#include <iostream>
#include <set>
int main(void)
{
	// std::cout << "*************** Test vrai list ***************" << std::endl;
	// std::list<int> titi = std::list<int>(2,8);
	// std::list<int>::iterator ite = titi.begin();
	// std::cout << &ite << std::endl;
	// ite++;
	// std::cout << &ite << std::endl;

	// std::cout << titi.max_size() << std::endl;
	// std::cout << &ite << std::endl;
	// std::cout << titi[0] << std::endl;
	// titi.push_back(42);
	// std::cout << titi[0] << std::endl;
	// //titi.push_front(42);
	// // ite = titi.begin();
	// std::cout << &ite << std::endl;
	// // for (size_t i = 0; i < titi.size(); i++)
	// // {
	// // 	std::cout << *ite + i << std::endl;
	// // }
	// // titi.insert(ite, 8);
	// // for (size_t i = 0; i < titi.size(); i++)
	// // {
	// // 	std::cout << *ite + i << std::endl;
	// // }
	

	std::cout << "*************** Test ft list ***************" << std::endl;
	size_t length = 8;
	ft::list<int> tata = ft::list<int>(length, 10);
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
	std::cout << "*************** Test ft list clear ***************" << std::endl;
	tata.clear();
	tata.aff();
	std::cout << "*************** Test ft list assign ***************" << std::endl;
	tata.assign(static_cast<size_t>(7),5);
	tata.aff();
	std::cout << "*************** Test ft list ***************" << std::endl;
	tata.resize(2);
	tata.aff();

	std::cout << "*************** Test ft push front and back ***************" << std::endl << std::endl;
	tata.push_front(450);
	tata.push_front(370);
	tata.push_back(125);
	tata.push_back(687);
	tata.aff();
	std::cout << "*************** Test ft list ITERATOR ***************" << std::endl;
	ft::list<int>::Iterator it;
	it = tata.begin();
	std::cout << *it << std::endl;
	++it; std::cout << *it << std::endl;
	++it; std::cout << *it << std::endl;
	++it; std::cout << *it << std::endl;
	++it; std::cout << *it << std::endl;
	++it; std::cout << *it << std::endl;
	++it; std::cout << *it << std::endl;
	++it; std::cout << *it << std::endl;
	++it; std::cout << *it << std::endl;
	++it; std::cout << *it << std::endl;
	++it; std::cout << *it << std::endl;
	++it; std::cout << *it << std::endl;
	++it; std::cout << *it << std::endl;
	++it; std::cout << *it << std::endl;
	++it; std::cout << *it << std::endl;
	std::cout << "*************** Test ft list ITERATOR ***************" << std::endl;
	it = tata.begin();
	it++;
	it++;
	it++;

	while (it != tata.end())
	{
		std::cout << *it << std::endl;
		std::cout << *it << std::endl;
		--it;
	}
		std::cout << *it++ << std::endl;

	std::cout << "*************** Test SWAP LIST***************" << std::endl;
	ft::list<int> toto = ft::list<int>(static_cast<size_t>(3), 4);
	std::cout  << std::endl << "aff toto" << std::endl << std::endl;
	toto.aff();
	std::cout  << std::endl << "aff tata" << std::endl << std::endl;
	tata.aff();
	std::cout  << std::endl << "SWAP" << std::endl << std::endl;
	tata.swap(toto);
	std::cout  << std::endl << "aff toto" << std::endl;
	toto.aff();
	std::cout  << std::endl << "aff tata" << std::endl << std::endl;
	tata.aff();

	it = tata.begin();
	it++;
	tata.erase(it);
	tata.aff();
	return 0;
}
