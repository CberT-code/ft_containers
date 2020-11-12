/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_main.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbertola <cbertola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 11:50:14 by cbertola          #+#    #+#             */
/*   Updated: 2020/11/12 11:56:28 by cbertola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Headers/Header.hpp"

int queue_main()
{

	std::cout << std::endl << std::endl << YELLOW;
	std::cout << "***********************************************************" << std::endl;
	std::cout << "*****************           QUEUE         *****************" << std::endl;
	std::cout << "***********************************************************" << std::endl;
	std::cout << RESET << std::endl << std::endl;

	std::cout << std::endl << BLUE << "**********     Constructor      **********" << RESET << std::endl;
	try{
		std::stringstream res;
		std::deque<int> mydeck (3,100);        // deque with 3 elements
		ft::list<int> mylist (2,200);         // list with 2 elements

		ft::queue<int> first;                 // empty queue
		ft::queue<int> second (mydeck);       // queue initialized to copy of deque

		ft::queue<int,ft::list<int> > third; // empty queue with list as underlying container
		ft::queue<int,ft::list<int> > fourth (mylist);

		res << "size of first: " << first.size() << '\n';
		res << "size of second: " << second.size() << '\n';
		res << "size of third: " << third.size() << '\n';
		res << "size of fourth: " << fourth.size() << '\n';

		compare_result(res.str(), "size of first: 0\nsize of second: 3\nsize of third: 0\nsize of fourth: 2\n");
	}catch(const std::exception &e){};


	std::cout << std::endl << BLUE << "**********        empty         **********" << RESET << std::endl;
	try{
		std::stringstream res;
		ft::queue<int> myqueue;
		int sum (0);

		for (int i=1;i<=10;i++) myqueue.push(i);

		while (!myqueue.empty())
		{
		 	sum += myqueue.front();
		 	myqueue.pop();
		}

		res << "total: " << sum << '\n';


		compare_result(res.str(), "total: 55\n");
	}catch(const std::exception &e){};

	std::cout << std::endl << BLUE << "**********        size          **********" << RESET << std::endl;
	try{
		std::stringstream res;
		ft::queue<int> myints;
		res << "0. size: " << myints.size() << '\n';

		for (int i=0; i<5; i++) myints.push(i);
		res << "1. size: " << myints.size() << '\n';

		myints.pop();
		res << "2. size: " << myints.size() << '\n';


		compare_result(res.str(), "0. size: 0\n1. size: 5\n2. size: 4\n");
	}catch(const std::exception &e){};

	std::cout << std::endl << BLUE << "**********        front         **********" << RESET << std::endl;
	try{
		std::stringstream res;
		ft::queue<int> myqueue;

		myqueue.push(77);
		myqueue.push(16);

		myqueue.front() -= myqueue.back();				// 77-16=61

		res << "myqueue.front() is now " << myqueue.front() << '\n';



		compare_result(res.str(), "myqueue.front() is now 61\n");
	}catch(const std::exception &e){};

	std::cout << std::endl << BLUE << "**********        back          **********" << RESET << std::endl;
	try{
		std::stringstream res;
		ft::queue<int> myqueue;

		myqueue.push(12);
		myqueue.push(75);		 // this is now the back

		myqueue.back() -= myqueue.front();

		res << "myqueue.back() is now " << myqueue.back() << '\n';



		compare_result(res.str(), "myqueue.back() is now 63\n");
	}catch(const std::exception &e){};

	std::cout << std::endl << BLUE << "**********         push         **********" << RESET << std::endl;
	try{
		ft::queue<int> myqueue;
  		int myint;
		std::cout << "Please enter some integers (enter 0 to end):\n";

		do {
			std::cin >> myint;
			myqueue.push (myint);
		} while (myint);

		std::cout << "myqueue contains: ";
		while (!myqueue.empty())
		{
			std::cout << ' ' << myqueue.front();
			myqueue.pop();
		}
		std::cout << '\n';

	}catch(const std::exception &e){};

	std::cout << std::endl << BLUE << "**********          pop         **********" << RESET << std::endl;
	try{
		ft::queue<int> myqueue;
		int myint;

		std::cout << "Please enter some integers (enter 0 to end):\n";

		do {
			std::cin >> myint;
			myqueue.push (myint);
		} while (myint);

		std::cout << "myqueue contains: ";
		while (!myqueue.empty())
		{
			std::cout << ' ' << myqueue.front();
			myqueue.pop();
		}
		std::cout << '\n';


	}catch(const std::exception &e){};

	
	std::cout << std::endl << BLUE << "**********        Operators      **********" << RESET << std::endl;
	try{
		std::stringstream res;
		ft::queue<int> a;
		a.push(10);
		a.push(20);
		a.push(30);
		ft::queue<int> b;
		b.push(10);
		b.push(20);
		b.push(30);
		ft::queue<int> c;
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

