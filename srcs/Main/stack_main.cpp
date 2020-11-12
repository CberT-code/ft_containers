/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_main.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 14:31:36 by user42            #+#    #+#             */
/*   Updated: 2020/11/12 14:31:39 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Headers/Header.hpp"

int stack_main ()
{

	std::cout << std::endl << std::endl << YELLOW;
	std::cout << "***********************************************************" << std::endl;
	std::cout << "*****************           Stack         *****************" << std::endl;
	std::cout << "***********************************************************" << std::endl;
	std::cout << RESET << std::endl << std::endl;

	std::cout << std::endl << BLUE << "**********     Constructor      **********" << RESET << std::endl;
	try{
		std::stringstream res;
		std::deque<int> mydeque (3,100);          // deque with 3 elements
  		ft::vector<int> myvector (2,200);        // vector with 2 elements

  		ft::stack<int> first;                    // empty stack
 		ft::stack<int> second (mydeque);         // stack initialized to copy of deque

  		ft::stack<int,ft::vector<int> > third;  // empty stack using vector
  		ft::stack<int,ft::vector<int> > fourth (myvector);

		res << "size of first: " << first.size() << '\n';
		res << "size of second: " << second.size() << '\n';
		res << "size of third: " << third.size() << '\n';
		res << "size of fourth: " << fourth.size() << '\n';

		compare_result(res.str(), "size of first: 0\nsize of second: 3\nsize of third: 0\nsize of fourth: 2\n");
	}catch(const std::exception &e){};


	std::cout << std::endl << BLUE << "**********        Empty         **********" << RESET << std::endl;
	try{
		std::stringstream res;
		ft::stack<int> mystack;
		int sum (0);

		for (int i=1;i<=10;i++) mystack.push(i);

		while (!mystack.empty())
		{
			sum += mystack.top();
			mystack.pop();
		}

		res << "total: " << sum << '\n';

		compare_result(res.str(), "total: 55\n");
	}catch(const std::exception &e){};


	std::cout << std::endl << BLUE << "**********         Size         **********" << RESET << std::endl;
	try{
		std::stringstream res;
		ft::stack<int> myints;
		res << "0. size: " << myints.size() << '\n';

		for (int i=0; i<5; i++) myints.push(i);
		res << "1. size: " << myints.size() << '\n';

		myints.pop();
		res << "2. size: " << myints.size() << '\n';

		compare_result(res.str(), "0. size: 0\n1. size: 5\n2. size: 4\n");
	}catch(const std::exception &e){};


	std::cout << std::endl << BLUE << "**********         Top          **********" << RESET << std::endl;
	try{
		std::stringstream res;
		ft::stack<int> mystack;

		mystack.push(10);
		mystack.push(20);

		mystack.top() -= 5;

		res << "mystack.top() is now " << mystack.top() << '\n';

		compare_result(res.str(), "mystack.top() is now 15\n");
	}catch(const std::exception &e){};

	std::cout << std::endl << BLUE << "**********         Push         **********" << RESET << std::endl;
	try{
		std::stringstream res;
		ft::stack<int> mystack;

		for (int i=0; i<5; ++i) mystack.push(i);

		res << "Popping out elements...";
		while (!mystack.empty())
		{
			res << ' ' << mystack.top();
			mystack.pop();
		}
		res << '\n';

		compare_result(res.str(), "Popping out elements... 4 3 2 1 0\n");
	}catch(const std::exception &e){};


	std::cout << std::endl << BLUE << "**********         Pop          **********" << RESET << std::endl;
	try{
		std::stringstream res;
		ft::stack<int> mystack;

		for (int i=0; i<5; ++i) mystack.push(i);

		res << "Popping out elements...";
		while (!mystack.empty())
		{
			res << ' ' << mystack.top();
			mystack.pop();
		}
		res << '\n';

		compare_result(res.str(), "Popping out elements... 4 3 2 1 0\n");
	}catch(const std::exception &e){};

	std::cout << std::endl << BLUE << "**********      Operators       **********" << RESET << std::endl;
	try{
		std::stringstream res;
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

		if (a==b) res << "a and b are equal\n";
		if (b!=c) res << "b and c are not equal\n";
		if (b<c) res << "b is less than c\n";
		if (c>b) res << "c is greater than b\n";
		if (a<=b) res << "a is less than or equal to b\n";
		if (a>=b) res << "a is greater than or equal to b\n";
		compare_result(res.str(), "a and b are equal\nb and c are not equal\nb is less than c\nc is greater than b\na is less than or equal to b\na is greater than or equal to b\n");
	}catch(const std::exception &e){};

	return 0;
}

