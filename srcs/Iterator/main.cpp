/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbertola <cbertola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 09:22:09 by cbertola          #+#    #+#             */
/*   Updated: 2020/10/30 17:07:50 by cbertola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "../Headers/Header.hpp"

#include <iostream>
#include <set>
#include <vector>

bool compare_nocase (const std::string& first, const std::string& second)
	{
		unsigned int i=0;
		while ( (i<first.length()) && (i<second.length()) )
		{
			if (tolower(first[i])<tolower(second[i])) return true;
			else if (tolower(first[i])>tolower(second[i])) return false;
			++i;
		}
		return ( first.length() < second.length() );
	}

int main ()
{

	std::cout << std::endl << BLUE << "*************** Test Constructor ***************" << RESET << std::endl;
	try{
		// constructors used in the same order as described above:
		ft::list<int> first;                                // empty list of ints
		ft::list<int> second (4,100);                       // four ints with value 100
		ft::list<int> third (second.begin(),second.end());  // iterating through second
		ft::list<int> fourth (third);                       // a copy of third

		// the iterator constructor can also be used to construct from arrays:
		int myints[] = {16,2,77,29};
		ft::list<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );

		std::cout << "The contents of fifth are: ";
		for (ft::list<int>::Iterator it = fifth.begin(); it != fifth.end(); it++)
			std::cout << *it << ' ';

		std::cout << '\n';
	}catch(const std::exception &e){};


	std::cout << std::endl << BLUE << "*************** Test opeartor= ***************" << RESET << std::endl;
	try{
		ft::list<int> first (3);      // list of 3 zero-initialized ints
		ft::list<int> second (5);     // list of 5 zero-initialized ints

		second = first;
		first = ft::list<int>();

		std::cout << "Size of first: " << int (first.size()) << '\n';
		std::cout << "Size of second: " << int (second.size()) << '\n';
	}catch(const std::exception &e){};


	std::cout << std::endl << BLUE << "*************** Test begin ***************" << RESET << std::endl;
	try{
		int myints[] = {75,23,65,42,13};
		ft::list<int> mylist (myints,myints+5);

		std::cout << "mylist contains:";
		for (ft::list<int>::Iterator it=mylist.begin(); it != mylist.end(); ++it)
			std::cout << ' ' << *it;

		std::cout << '\n';
	}catch(const std::exception &e){};


	std::cout << std::endl << BLUE << "*************** Test end ***************" << RESET << std::endl;
	try{
		int myints[] = {75,23,65,42,13};
		ft::list<int> mylist (myints,myints+5);

		std::cout << "mylist contains:";
		for (ft::list<int>::Iterator it=mylist.begin() ; it != mylist.end(); ++it)
			std::cout << ' ' << *it;

		std::cout << '\n';
	}catch(const std::exception &e){};


		std::cout << std::endl << BLUE << "*************** Test rbegin ***************" << RESET << std::endl;
	try{
		ft::list<int> mylist;
		for (int i=1; i<=5; ++i) mylist.push_back(i);

		std::cout << "mylist backwards:";
		for (ft::list<int>::reverse_Iterator rit=mylist.rbegin(); rit!=mylist.rend(); ++rit)
			std::cout << ' ' << *rit;

		std::cout << '\n';
	}catch(const std::exception &e){};


		std::cout << std::endl << BLUE << "*************** Test rend ***************" << RESET << std::endl;
	try{
		 ft::list<int> mylist;
		for (int i=1; i<=5; ++i) mylist.push_back(i);

		std::cout << "mylist backwards:";
		for (ft::list<int>::reverse_Iterator rit=mylist.rbegin(); rit!=mylist.rend(); ++rit)
			std::cout << ' ' << *rit;

		std::cout << '\n';
	}catch(const std::exception &e){};


		std::cout << std::endl << BLUE << "*************** Test empty ***************" << RESET << std::endl;
	try{
		ft::list<int> mylist;
		int sum (0);

		for (int i=1 ;i <= 10; ++i) mylist.push_back(i);

		while (!mylist.empty())
		{
			sum += mylist.front();
			mylist.pop_front();
		}
		std::cout << "total: " << sum << '\n';
	}catch(const std::exception &e){};


		std::cout << std::endl << BLUE << "*************** Test size ***************" << RESET << std::endl;
	try{
		ft::list<int> myints;
		std::cout << "0. size: " << myints.size() << '\n';

		for (int i=0; i<10; i++) myints.push_back(i);
		std::cout << "1. size: " << myints.size() << '\n';

		myints.insert (myints.begin(),10,100);
		std::cout << "2. size: " << myints.size() << '\n';

		myints.pop_back();
		std::cout << "3. size: " << myints.size() << '\n';
	}catch(const std::exception &e){};

	// std::cout << std::endl << BLUE << "*************** Test max_size ***************" << RESET << std::endl;
	// try{
	// 	size_t i;
	// 	ft::list<int> mylist;

	// 	std::cout << "Enter number of elements: ";
	// 	std::cin >> i;

	// 	if (i < mylist.max_size()) 
	// 		mylist.resize(i);
	// 	else std::cout << "That size exceeds the limit.\n";
	// }catch(const std::exception &e){};

	std::cout << std::endl << BLUE << "*************** Test front ***************" << RESET << std::endl;
	try{
		ft::list<int> mylist;

		mylist.push_back(77);
		mylist.push_back(22);

		// now front equals 77, and back 22

		mylist.front() -= mylist.back();

		std::cout << "mylist.front() is now " << mylist.front() << '\n';

	}catch(const std::exception &e){};


		std::cout << std::endl << BLUE << "*************** Test back ***************" << RESET << std::endl;
	try{
		ft::list<int> mylist;

		mylist.push_back(15);

		ft::list<int>::Iterator it1 = mylist.begin();

		while (mylist.back() != 0){
			mylist.push_back ( mylist.back() -1 );
		}

		std::cout << "mylist contains:";
		for (ft::list<int>::Iterator it=mylist.begin(); it!=mylist.end() ; ++it)
			std::cout << ' ' << *it;

		std::cout << '\n';

	}catch(const std::exception &e){};

		std::cout << std::endl << BLUE << "*************** Test assign ***************" << RESET << std::endl;
	try{
		ft::list<int> first;
		ft::list<int> second;

		first.assign (7,100);                      // 7 ints with value 100

		second.assign (first.begin(),first.end()); // a copy of first

		int myints[]={1776,7,4};
		first.assign (myints,myints+3);            // assigning from array

		std::cout << "Size of first: " << int (first.size()) << '\n';
		std::cout << "Size of second: " << int (second.size()) << '\n';

	}catch(const std::exception &e){};


	std::cout << std::endl << BLUE << "*************** Test push_front ***************" << RESET << std::endl;
	try{
		ft::list<int> mylist (2,100);         // two ints with a value of 100
		mylist.push_front (200);
		mylist.push_front (300);

		std::cout << "mylist contains:";
		for (ft::list<int>::Iterator it=mylist.begin(); it!=mylist.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << '\n';
	}catch(const std::exception &e){};


	std::cout << std::endl << BLUE << "*************** Test pop_front ***************" << RESET << std::endl;
	try{
		ft::list<int> mylist;
		mylist.push_back (100);
		mylist.push_back (200);
		mylist.push_back (300);

		std::cout << "Popping out the elements in mylist:";
		while (!mylist.empty())
		{
			std::cout << ' ' << mylist.front();
			mylist.pop_front();
		}
		std::cout << "\nFinal size of mylist is " << mylist.size() << '\n';
	}catch(const std::exception &e){};


	std::cout << std::endl << BLUE << "*************** Test Push_back ***************" << RESET << std::endl;
	try{
		ft::list<int> mylist;
		int myint;

		std::cout << "Please enter some integers (enter 0 to end):\n";

		do {
			std::cin >> myint;
			mylist.push_back (myint);
		} while (myint);

		std::cout << "mylist stores " << mylist.size() << " numbers.\n";
	}catch(const std::exception &e){};


	std::cout << std::endl << BLUE << "*************** Test Pop_back ***************" << RESET << std::endl;
	try{
		ft::list<int> mylist;
		int sum (0);
		mylist.push_back (100);
		mylist.push_back (200);
		mylist.push_back (300);

		while (!mylist.empty())
		{
			sum+=mylist.back();
			mylist.pop_back();
		}

		std::cout << "The elements of mylist summed " << sum << '\n';
	}catch(const std::exception &e){};


	std::cout << std::endl << BLUE << "*************** Test Insert ***************" << RESET << std::endl;
	try{
		ft::list<int> mylist;
		ft::list<int>::Iterator it;

		// set some initial values:
		for (int i=1; i<=5; ++i)
			mylist.push_back(i); // 1 2 3 4 5

		it = mylist.begin();
		++it;       // it points now to number 2           ^

		mylist.insert (it,10);                        // 1 10 2 3 4 5

		// "it" still points to number 2                      ^
		mylist.insert (it,2,20);                      // 1 10 20 20 2 3 4 5

		--it;       // it points now to the second 20            ^

		// std::vector<int> myvector (2,30);
		// mylist.insert (it,myvector.begin(),myvector.end());
														// 1 10 20 30 30 20 2 3 4 5
														//               ^
		std::cout << "mylist contains:";
		for (it=mylist.begin(); it!=mylist.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << '\n';
		
	}catch(const std::exception &e){};


	// std::cout << std::endl << BLUE << "*************** Test Erase ***************" << RESET << std::endl;
	// try{
	// 	ft::list<int> mylist;
	// 	ft::list<int>::Iterator it1,it2;

	// 	// set some values:
	// 	for (int i=1; i<10; ++i) mylist.push_back(i*10);

	// 								// 10 20 30 40 50 60 70 80 90
	// 	it1 = it2 = mylist.begin(); // ^^
	// 	//std::advance (it2,6);
	// 	for (int i = 0; i < 6; i++){
	// 		it2++;
	// 	}
	// 						        // ^                 ^
	// 	++it1;                      //    ^              ^

	// 	it1 = mylist.erase (it1);   // 10 30 40 50 60 70 80 90
	// 								//    ^           ^

	// 	it2 = mylist.erase (it2);   // 10 30 40 50 60 80 90
	// 								//    ^           ^

	// 	++it1;                      //       ^        ^
	// 	--it2;                      //       ^     ^

	// 	mylist.erase (it1,it2);     // 10 30 60 80 90
	// 								//        ^

	// 	std::cout << "mylist contains:";
	// 	for (it1=mylist.begin(); it1!=mylist.end(); ++it1)
	// 		std::cout << ' ' << *it1;
	// 	std::cout << '\n';
	// }catch(const std::exception &e){};


	std::cout << std::endl << BLUE << "*************** TEST SWAP ***************" << RESET << std::endl;
	try{
		ft::list<int> first (3,100);   // three ints with a value of 100
		ft::list<int> second (5,200);  // five ints with a value of 200

		first.swap(second);

		std::cout << "first contains:";
		for (ft::list<int>::Iterator it=first.begin(); it!=first.end(); it++)
			std::cout << ' ' << *it;
		std::cout << '\n';

		std::cout << "second contains:";
		for (ft::list<int>::Iterator it=second.begin(); it!=second.end(); it++)
			std::cout << ' ' << *it;
		std::cout << '\n';
	}catch(const std::exception &e){};


	std::cout << std::endl << BLUE << "*************** TEST RESIZE ***************" << RESET << std::endl;
	try{
		ft::list<int> mylist;

		// set some initial content:
		for (int i=1; i<10; ++i) mylist.push_back(i);

		mylist.resize(5);
		mylist.resize(8,100);
		mylist.resize(12);

		std::cout << "mylist contains:";
		for (ft::list<int>::Iterator it=mylist.begin(); it!=mylist.end(); ++it)
			std::cout << ' ' << *it;

		std::cout << '\n';
	}catch(const std::exception &e){};


	std::cout << std::endl << BLUE << "***************  TEST CLEAR ***************" << RESET << std::endl;
	try{
		ft::list<int> mylist;
		ft::list<int>::Iterator it;

		mylist.push_back (100);
		mylist.push_back (200);
		mylist.push_back (300);

		std::cout << "mylist contains:";
		for (it=mylist.begin(); it!=mylist.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << '\n';

		mylist.clear();
		mylist.push_back (1101);
		mylist.push_back (2202);

		std::cout << "mylist contains:";
		for (it=mylist.begin(); it!=mylist.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << '\n';
	}catch(const std::exception &e){};


	std::cout << std::endl << BLUE << "*************** TEST REVERSE ***************" << RESET << std::endl;
	try{
		ft::list<int> mylist;

		for (int i=1; i<10; ++i) mylist.push_back(i);

		mylist.reverse();

		std::cout << "mylist contains:";
		for (ft::list<int>::Iterator it=mylist.begin(); it!=mylist.end(); ++it)
			std::cout << ' ' << *it;

		std::cout << '\n';
	}catch(const std::exception &e){};


	

	std::cout << std::endl << BLUE << "***************  TEST SORT ***************" << RESET << std::endl;
	try{


		ft::list<std::string> mylist;
		ft::list<std::string>::Iterator it;
		
		mylist.push_back ("one");
		mylist.push_back ("two");
		mylist.push_back ("Three");

		mylist.sort();

		std::cout << "mylist contains:";
		for (it=mylist.begin(); it!=mylist.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << '\n';

		// mylist.sort(compare_nocase);

		// std::cout << "mylist contains:";
		// for (it=mylist.begin(); it!=mylist.end(); ++it)
		// 	std::cout << ' ' << *it;
		// std::cout << '\n';

	}catch(const std::exception &e){};


	// std::cout << std::endl << BLUE << "***************  ***************" << RESET << std::endl;
	// try{
		
	// }catch(const std::exception &e){};
	return 0;
}