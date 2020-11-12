/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 09:22:09 by moi          #+#    #+#             */
/*   Updated: 2020/10/30 18:24:12 by user42           ###   ########.fr       */
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

	std::cout << std::endl << BLUE << "***************** Test Constructeur ************" << RESET << std::endl;
	try{
		std::deque<int> mydeck (3,100);        // deque with 3 elements
		ft::list<int> mylist (2,200);         // list with 2 elements

		ft::queue<int> first;                 // empty queue
		ft::queue<int> second (mydeck);       // queue initialized to copy of deque

		ft::queue<int,ft::list<int> > third; // empty queue with list as underlying container
		ft::queue<int,ft::list<int> > fourth (mylist);

		std::cout << "size of first: " << first.size() << '\n';
		std::cout << "size of second: " << second.size() << '\n';
		std::cout << "size of third: " << third.size() << '\n';
		std::cout << "size of fourth: " << fourth.size() << '\n';
	}catch(const std::exception &e){};


std::cout << std::endl << BLUE << "***************** Test Empty ************" << RESET << std::endl;
	try{
		ft::queue<int> myqueue;
		int sum (0);

		for (int i=1;i<=10;i++) myqueue.push(i);

		while (!myqueue.empty())
		{
		 	sum += myqueue.front();
		 	myqueue.pop();
		}

		std::cout << "total: " << sum << '\n';

	}catch(const std::exception &e){};

std::cout << std::endl << BLUE << "***************** Test Size ************" << RESET << std::endl;
	try{
		ft::queue<int> myints;
		std::cout << "0. size: " << myints.size() << '\n';

		for (int i=0; i<5; i++) myints.push(i);
		std::cout << "1. size: " << myints.size() << '\n';

		myints.pop();
		std::cout << "2. size: " << myints.size() << '\n';

	}catch(const std::exception &e){};

std::cout << std::endl << BLUE << "***************** Test Front ************" << RESET << std::endl;
	try{
		ft::queue<int> myqueue;

		myqueue.push(77);
		myqueue.push(16);

		myqueue.front() -= myqueue.back();				// 77-16=61

		std::cout << "myqueue.front() is now " << myqueue.front() << '\n';


	}catch(const std::exception &e){};

	std::cout << std::endl << BLUE << "***************** Test Back ************" << RESET << std::endl;
	try{
		ft::queue<int> myqueue;

		myqueue.push(12);
		myqueue.push(75);		 // this is now the back

		myqueue.back() -= myqueue.front();

		std::cout << "myqueue.back() is now " << myqueue.back() << '\n';


	}catch(const std::exception &e){};

	std::cout << std::endl << BLUE << "***************** Test Push ************" << RESET << std::endl;
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

	std::cout << std::endl << BLUE << "***************** Test Pop ************" << RESET << std::endl;
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

	std::cout << std::endl << BLUE << "***************** Test Operators ************" << RESET << std::endl;
	try{
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

		if (a==b) std::cout << "a and b are equal\n";
		if (b!=c) std::cout << "b and c are not equal\n";
		if (b<c) std::cout << "b is less than c\n";
		if (c>b) std::cout << "c is greater than b\n";
		if (a<=b) std::cout << "a is less than or equal to b\n";
		if (a>=b) std::cout << "a is greater than or equal to b\n";
	}catch(const std::exception &e){};

	return 0;
}

