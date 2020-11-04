/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainstack.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 16:53:54 by user42            #+#    #+#             */
/*   Updated: 2020/11/04 17:37:22 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Headers/Header.hpp"
#include <iostream>
#include <sstream>
#include <iomanip>
#include <set>
#include <vector>
#include <tgmath.h>
#include <list>

int main_stack ()
{
	std::cout << std::endl << BLUE << "***************** Test Constructeur ************" << RESET << std::endl;
	try{
		std::deque<int> mydeque (3,100);          // deque with 3 elements
  		std::vector<int> myvector (2,200);        // vector with 2 elements

  		ft::stack<int> first;                    // empty stack
 		ft::stack<int> second (mydeque);         // stack initialized to copy of deque

  		ft::stack<int,std::vector<int> > third;  // empty stack using vector
  		ft::stack<int,std::vector<int> > fourth (myvector);

		std::cout << "size of first: " << first.size() << '\n';
		std::cout << "size of second: " << second.size() << '\n';
		std::cout << "size of third: " << third.size() << '\n';
		std::cout << "size of fourth: " << fourth.size() << '\n';

	}catch(const std::exception &e){};


std::cout << std::endl << BLUE << "***************** Test Empty ************" << RESET << std::endl;
	try{
		ft::stack<int> mystack;
		int sum (0);

		for (int i=1;i<=10;i++) mystack.push(i);

		while (!mystack.empty())
		{
			sum += mystack.top();
			mystack.pop();
		}

		std::cout << "total: " << sum << '\n';

	}catch(const std::exception &e){};


std::cout << std::endl << BLUE << "***************** Test Size ************" << RESET << std::endl;
	try{
		ft::stack<int> myints;
		std::cout << "0. size: " << myints.size() << '\n';

		for (int i=0; i<5; i++) myints.push(i);
		std::cout << "1. size: " << myints.size() << '\n';

		myints.pop();
		std::cout << "2. size: " << myints.size() << '\n';

	}catch(const std::exception &e){};


std::cout << std::endl << BLUE << "***************** Test Top ************" << RESET << std::endl;
	try{
		ft::stack<int> mystack;

		mystack.push(10);
		mystack.push(20);

		mystack.top() -= 5;

		std::cout << "mystack.top() is now " << mystack.top() << '\n';

	}catch(const std::exception &e){};


std::cout << std::endl << BLUE << "***************** Test Push ************" << RESET << std::endl;
	try{
		ft::stack<int> mystack;

		for (int i=0; i<5; ++i) mystack.push(i);

		std::cout << "Popping out elements...";
		while (!mystack.empty())
		{
			std::cout << ' ' << mystack.top();
			mystack.pop();
		}
		std::cout << '\n';

	}catch(const std::exception &e){};


std::cout << std::endl << BLUE << "***************** Test Pop ************" << RESET << std::endl;
	try{
		ft::stack<int> mystack;

		for (int i=0; i<5; ++i) mystack.push(i);

		std::cout << "Popping out elements...";
		while (!mystack.empty())
		{
			std::cout << ' ' << mystack.top();
			mystack.pop();
		}
		std::cout << '\n';

	}catch(const std::exception &e){};

	std::cout << std::endl << BLUE << "***************** Test Operators ************" << RESET << std::endl;
	try{
		ft::stack<int> a;
		a.push(10);
		a.push(20);
		a.push(30);
		ft::stack<int> b;
		b.push(10);
		b.push(20);
		b.push(30);
		ft::stack<int> c;
		c.push(30);
		c.push(20);
		c.push(10);

		if (a==b) std::cout << "a and b are equal\n";
		if (b!=c) std::cout << "b and c are not equal\n";
		if (b<c) std::cout << "b is less than c\n";
		if (c>b) std::cout << "c is greater than b\n";
		if (a<=b) std::cout << "a is less than or equal to b\n";
		if (a>=b) std::cout << "a is greater than or equal to b\n";
	}catch(const std::exception &e){};

	return 0;
}

