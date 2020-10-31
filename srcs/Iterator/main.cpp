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

#include <iostream>
#include <sstream>
#include <iomanip>
#include <set>
#include <vector>
#include <tgmath.h>
#include <list>


void  compare_result(std::string res1, std::string res2)
{
	if (!res1.compare(res2)) 
		std::cout << GREEN << res1  << RESET << std::endl;
	else{
		std::cout << RED << "Our : " << res1  << RESET << std::endl;
		std::cout << RED << "Real one : " << res2  << RESET << std::endl;
	}
}
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

bool single_digit (const int& value) { return (value<10); }

struct is_odd {
	bool operator() (const int& value) { return (value%2)==1; }
};

bool same_integral_part (double first, double second)
{ return ( int(first)==int(second) ); }

// a binary predicate implemented as a class:
struct is_near {
  bool operator() (double first, double second)
  { return (fabs(first-second)<5.0); }
};

bool mycomparison (double first, double second)
{ return ( int(first)<int(second) ); }

int main ()
{
	// std::list<int> toto;
	// toto.push_back(41);
	// toto.push_back(31);
	// toto.push_back(33);
	// toto.push_back(27);
	// toto.push_back(18);
	// std::list<int>::iterator it;
	// it = toto.begin();
	// for (size_t i = 0; i < 12; i++)
	// {
	// 	std::cout << *it << std::endl;
	// 	it++;
	// 	/* code */
	// }
	

	// std::list<std::string> tutu;
	// tutu.push_back("popooiii");
	// tutu.push_back("popod");
	// tutu.push_back("popo|||");
	// std::list<std::string>::iterator ite;
	// ite = tutu.begin();
	// for (size_t i = 0; i < 12; i++)
	// {
	// 	std::cout << *ite << std::endl;
	// 	ite++;
	// 	/* code */
	// }
	// tutu.sort();

	std::cout << std::endl << BLUE << "*************** Test Constructor ***************" << RESET << std::endl;
	try{
		// constructors used in the same order as described above:
		ft::list<int> first;                                // empty list of ints
		ft::list<int> second (4,100);                       // four ints with value 100
		ft::list<int> third (second.begin(),second.end());  // iterating through second
		ft::list<int> fourth (third);                       // a copy of third
		std::stringstream res;

		// the iterator constructor can also be used to construct from arrays:
		int myints[] = {16,2,77,29};
		for (int i = 0; i < 4; i++)
			first.push_back(myints[i]);
		first.unique();
		res << "The contents of fifth are: ";
		for (ft::list<int>::Iterator it = first.begin(); it != first.end(); it++)
			res << *it << ' ';

		compare_result(res.str(), "The contents of fifth are: 16 2 77 29 ");
		std::cout << '\n';

	}catch(const std::exception &e){};

	// std::cout << std::endl << BLUE << "*************** Test operator= ***************" << RESET << std::endl;
	// try{
	// 	ft::list<int> first (3);      // list of 3 zero-initialized ints
	// 	ft::list<int> second (5);     // list of 5 zero-initialized ints
	// 	std::stringstream res;
	// 	std::stringstream res1;

	// 	second = first;
	// 	first = ft::list<int>();

	// 	res << "Size of first: " << int (first.size());
	// 	compare_result(res.str(), "Size of first: 0");
	// 	res1 << "Size of second: " << int (second.size());
	// 	compare_result(res1.str(), "Size of second: 3");
	// }catch(const std::exception &e){};


	// std::cout << std::endl << BLUE << "*************** Test begin ***************" << RESET << std::endl;
	// try{
	// 	int myints[] = {75,23,65,42,13};
	// 	ft::list<int> mylist (myints,myints+5);
	// 	std::stringstream res;

	// 	res << "mylist contains:";
	// 	for (ft::list<int>::Iterator it=mylist.begin(); it != mylist.end(); ++it)
	// 		res << ' ' << *it;
	// 	compare_result(res.str(), "mylist contains: 75 23 65 42 13");
	// }catch(const std::exception &e){};


	// std::cout << std::endl << BLUE << "*************** Test end ***************" << RESET << std::endl;
	// try{
	// 	int myints[] = {75,23,65,42,13};
	// 	ft::list<int> mylist (myints,myints+5);
	// 	std::stringstream res;

	// 	res << "mylist contains:";
	// 	for (ft::list<int>::Iterator it=mylist.begin() ; it != mylist.end(); ++it)
	// 		res << ' ' << *it;

	// 	compare_result(res.str(), "mylist contains: 75 23 65 42 13");
	// }catch(const std::exception &e){};


	// 	std::cout << std::endl << BLUE << "*************** Test rbegin ***************" << RESET << std::endl;
	// try{
	// 	ft::list<int> mylist;
	// 	std::stringstream res;
	// 	for (int i=1; i<=5; ++i) mylist.push_back(i);

	// 	res << "mylist backwards:";
	// 	for (ft::list<int>::reverse_Iterator rit=mylist.rbegin(); rit!=mylist.rend(); ++rit)
	// 		res << ' ' << *rit;

	// 	compare_result(res.str(), "mylist backwards: 5 4 3 2 1");
	// }catch(const std::exception &e){};


	// 	std::cout << std::endl << BLUE << "*************** Test rend ***************" << RESET << std::endl;
	// try{
	// 	 ft::list<int> mylist;
	// 	 std::stringstream res;
	// 	for (int i=1; i<=5; ++i) mylist.push_back(i);

	// 	res << "mylist backwards:";
	// 	for (ft::list<int>::reverse_Iterator rit=mylist.rbegin(); rit!=mylist.rend(); ++rit)
	// 		res << ' ' << *rit;

	// 	compare_result(res.str(), "mylist backwards: 5 4 3 2 1");
	// }catch(const std::exception &e){};


	// 	std::cout << std::endl << BLUE << "*************** Test empty ***************" << RESET << std::endl;
	// try{
	// 	ft::list<int> mylist;
	// 	std::stringstream res;
	// 	int sum (0);

	// 	for (int i=1 ;i <= 10; ++i) mylist.push_back(i);

	// 	while (!mylist.empty())
	// 	{
	// 		sum += mylist.front();
	// 		mylist.pop_front();
	// 	}
	// 	res << "total: " << sum;
	// 	compare_result(res.str(), "total: 55");
	// }catch(const std::exception &e){};


	// 	std::cout << std::endl << BLUE << "*************** Test size ***************" << RESET << std::endl;
	// try{
	// 	ft::list<int> myints;
	// 	std::stringstream res;
	// 	std::stringstream res1;
	// 	std::stringstream res2;
	// 	std::stringstream res3;
	// 	res << "0. size: " << myints.size();
	// 	compare_result(res.str(), "0. size: 0");

	// 	for (int i=0; i<10; i++) myints.push_back(i);
	// 	res1 << "1. size: " << myints.size();
	// 	compare_result(res1.str(), "1. size: 10");

	// 	myints.insert (myints.begin(),10,100);
	// 	res2 << "2. size: " << myints.size();
	// 	compare_result(res2.str(), "2. size: 20");

	// 	myints.pop_back();
	// 	res3 << "3. size: " << myints.size();
	// 	compare_result(res3.str(), "3. size: 19");

	// }catch(const std::exception &e){};

	// // // std::cout << std::endl << BLUE << "*************** Test max_size ***************" << RESET << std::endl;
	// // // try{
	// // // 	size_t i;
	// // // 	ft::list<int> mylist;

	// // // 	std::cout << "Enter number of elements: ";
	// // // 	std::cin >> i;

	// // // 	if (i < mylist.max_size()) 
	// // // 		mylist.resize(i);
	// // // 	else std::cout << "That size exceeds the limit.\n";
	// // // }catch(const std::exception &e){};

	// std::cout << std::endl << BLUE << "*************** Test front ***************" << RESET << std::endl;
	// try{
	// 	ft::list<int> mylist;
	// 	std::stringstream res;

	// 	mylist.push_back(77);
	// 	mylist.push_back(22);

	// 	// now front equals 77, and back 22

	// 	mylist.front() -= mylist.back();

	// 	res << "mylist.front() is now " << mylist.front();
	// 	compare_result(res.str(), "mylist.front() is now 55");

	// }catch(const std::exception &e){};


	// 	std::cout << std::endl << BLUE << "*************** Test back ***************" << RESET << std::endl;
	// try{
	// 	ft::list<int> mylist;
	// 	std::stringstream res;

	// 	mylist.push_back(10);

	// 	ft::list<int>::Iterator it1 = mylist.begin();

	// 	while (mylist.back() != 0){
	// 		mylist.push_back ( mylist.back() -1 );
	// 	}

	// 	res << "mylist contains:";
	// 	for (ft::list<int>::Iterator it=mylist.begin(); it!=mylist.end() ; ++it)
	// 		res << ' ' << *it;
	// 	compare_result(res.str(), "mylist contains: 10 9 8 7 6 5 4 3 2 1 0");

	// }catch(const std::exception &e){};

	// 	std::cout << std::endl << BLUE << "*************** Test assign ***************" << RESET << std::endl;
	// try{
	// 	ft::list<int> first;
	// 	ft::list<int> second;
	// 	std::stringstream res;
	// 	std::stringstream res1;

	// 	first.assign (7,100);                      // 7 ints with value 100

	// 	second.assign (first.begin(),first.end()); // a copy of first

	// 	int myints[]={1776,7,4};
	// 	first.assign (myints,myints+3);            // assigning from array

	// 	res << "Size of first: " << int (first.size());
	// 	compare_result(res.str(), "Size of first: 3");
	// 	res1 << "Size of second: " << int (second.size());
	// 	compare_result(res1.str(), "Size of second: 7");

	// }catch(const std::exception &e){};


	// std::cout << std::endl << BLUE << "*************** Test push_front ***************" << RESET << std::endl;
	// try{
	// 	std::stringstream res;
	// 	ft::list<int> mylist (2,100);         // two ints with a value of 100
	// 	mylist.push_front (200);
	// 	mylist.push_front (300);

	// 	res << "mylist contains:";
	// 	for (ft::list<int>::Iterator it=mylist.begin(); it!=mylist.end(); ++it)
	// 		res << ' ' << *it;
	// 	compare_result(res.str(), "mylist contains: 300 200 100 100");
	// }catch(const std::exception &e){};


	// std::cout << std::endl << BLUE << "*************** Test pop_front ***************" << RESET << std::endl;
	// try{
	// 	std::stringstream res;
	// 	std::stringstream res1;
	// 	ft::list<int> mylist;
	// 	mylist.push_back (100);
	// 	mylist.push_back (200);
	// 	mylist.push_back (300);

	// 	res << "Popping out the elements in mylist:";
	// 	while (!mylist.empty())
	// 	{
	// 		res << ' ' << mylist.front();
	// 		mylist.pop_front();
	// 	}
	// 	compare_result(res.str(), "Popping out the elements in mylist: 100 200 300");
	// 	res1 << "Final size of mylist is " << mylist.size();
	// 	compare_result(res1.str(), "Final size of mylist is 0");
	// }catch(const std::exception &e){};


	// std::cout << std::endl << BLUE << "*************** Test Push_back ***************" << RESET << std::endl;
	// try{
	// 	ft::list<int> mylist;
	// 	std::stringstream res;
	// 	int myint;

	// 	std::cout << "Please enter some integers (enter 0 to end):\n";

	// 	do {
	// 		std::cin >> myint;
	// 		mylist.push_back (myint);
	// 	} while (myint);

	// 	std::cout << "mylist stores " << mylist.size() << " numbers.\n";
	// }catch(const std::exception &e){};


	// std::cout << std::endl << BLUE << "*************** Test Pop_back ***************" << RESET << std::endl;
	// try{
	// 	ft::list<int> mylist;
	// 	std::stringstream res;
	// 	int sum (0);
	// 	mylist.push_back (100);
	// 	mylist.push_back (200);
	// 	mylist.push_back (300);

	// 	while (!mylist.empty())
	// 	{
	// 		sum+=mylist.back();
	// 		mylist.pop_back();
	// 	}

	// 	res << "The elements of mylist summed " << sum;
	// 	compare_result(res.str(), "The elements of mylist summed 600");
	// }catch(const std::exception &e){};


	// std::cout << std::endl << BLUE << "*************** Test Insert ***************" << RESET << std::endl;
	// try{
	// 	ft::list<int> mylist;
	// 	ft::list<int>::Iterator it;
	// 	std::stringstream res;

	// 	// set some initial values:
	// 	for (int i=1; i<=5; ++i)
	// 		mylist.push_back(i); // 1 2 3 4 5

	// 	it = mylist.begin();
	// 	++it;       // it points now to number 2           ^

	// 	mylist.insert (it,10);                        // 1 10 2 3 4 5

	// 	// "it" still points to number 2                      ^
	// 	mylist.insert (it,2,20);                      // 1 10 20 20 2 3 4 5

	// 	--it;       // it points now to the second 20            ^

	// 	// std::vector<int> myvector (2,30);
	// 	// mylist.insert (it,myvector.begin(),myvector.end());
	// 													// 1 10 20 30 30 20 2 3 4 5
	// 													//               ^
	// 	res << "mylist contains:";
	// 	for (it=mylist.begin(); it!=mylist.end(); ++it)
	// 		res << ' ' << *it;
	// 	compare_result(res.str(), "mylist contains: 1 10 20 30 30 20 2 3 4 5");
		
	// }catch(const std::exception &e){};


	// std::cout << std::endl << BLUE << "*************** Test Erase ***************" << RESET << std::endl;
	// try{
	// 	ft::list<int> mylist;
	// 	ft::list<int>::Iterator it1,it2;
	// 	std::stringstream res;

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

	// 	res << "mylist contains:";
	// 	for (it1=mylist.begin(); it1!=mylist.end(); ++it1)
	// 		res << ' ' << *it1;
	// 	compare_result(res.str(), "mylist contains: 10 30 60 80 90");
	// }catch(const std::exception &e){};


	// std::cout << std::endl << BLUE << "*************** TEST SWAP ***************" << RESET << std::endl;
	// try{
	// 	ft::list<int> first (3,100);   // three ints with a value of 100
	// 	ft::list<int> second (5,200);  // five ints with a value of 200
	// 	std::stringstream res;
	// 	std::stringstream res1;

	// 	first.swap(second);

	// 	res << "first contains:";
	// 	for (ft::list<int>::Iterator it=first.begin(); it!=first.end(); it++)
	// 		res << ' ' << *it;
	// 	compare_result(res.str(), "first contains: 200 200 200 200 200");

	// 	res1 << "second contains:";
	// 	for (ft::list<int>::Iterator it=second.begin(); it!=second.end(); it++)
	// 		res1 << ' ' << *it;
	// 	compare_result(res1.str(), "second contains: 100 100 100");
	// }catch(const std::exception &e){};


	// std::cout << std::endl << BLUE << "*************** TEST RESIZE ***************" << RESET << std::endl;
	// try{
	// 	ft::list<int> mylist;
	// 	std::stringstream res;

	// 	// set some initial content:
	// 	for (int i=1; i<10; ++i) mylist.push_back(i);

	// 	mylist.resize(5);
	// 	mylist.resize(8,100);
	// 	mylist.resize(12);

	// 	res << "mylist contains:";
	// 	for (ft::list<int>::Iterator it=mylist.begin(); it!=mylist.end(); ++it)
	// 		res << ' ' << *it;

	// 	compare_result(res.str(), "mylist contains: 1 2 3 4 5 100 100 100 0 0 0 0");
	// }catch(const std::exception &e){};


	// std::cout << std::endl << BLUE << "***************  TEST CLEAR ***************" << RESET << std::endl;
	// try{
	// 	ft::list<int> mylist;
	// 	ft::list<int>::Iterator it;
	// 	std::stringstream res;
	// 	std::stringstream res1;

	// 	mylist.push_back (100);
	// 	mylist.push_back (200);
	// 	mylist.push_back (300);

	// 	res << "mylist contains:";
	// 	for (it=mylist.begin(); it!=mylist.end(); ++it)
	// 		res << ' ' << *it;
	// 	compare_result(res.str(), "mylist contains: 100 200 300");

	// 	mylist.clear();
	// 	mylist.push_back (1101);
	// 	mylist.push_back (2202);

	// 	res1 << "mylist contains:";
	// 	for (it=mylist.begin(); it!=mylist.end(); ++it)
	// 		res1 << ' ' << *it;
	// 	compare_result(res1.str(), "mylist contains: 1101 2202");
	// }catch(const std::exception &e){};


	// 	std::cout << std::endl << BLUE << "*************** TEST SPLICE ***************" << RESET << std::endl;
	// try{
	// 	ft::list<int> mylist1, mylist2;
	// 	ft::list<int>::Iterator it;
	// 	std::stringstream res;
	// 	std::stringstream res1;

	// 	// set some initial values:
	// 	for (int i=1; i<=4; ++i)
	// 		mylist1.push_back(i);      // mylist1: 1 2 3 4

	// 	for (int i=1; i<=3; ++i)
	// 		mylist2.push_back(i*10);   // mylist2: 10 20 30

	// 	it = mylist1.begin();
	// 	++it;                         // points to 2

	// 	mylist1.splice (it, mylist2); // mylist1: 1 10 20 30 2 3 4
	// 									// mylist2 (empty)
	// 									// "it" still points to 2 (the 5th element)
												
	// 	mylist2.splice (mylist2.begin(),mylist1, it);
	// 									// mylist1: 1 10 20 30 3 4
	// 									// mylist2: 2
	// 									// "it" is now invalid.
	// 	it = mylist1.begin();
	// 	// std::advance(it,3);           // "it" points now to 30

	// 	mylist1.splice ( mylist1.begin(), mylist1, it, mylist1.end());
	// 									// mylist1: 30 3 4 1 10 20

	// 	res << "mylist1 contains:";
	// 	for (it=mylist1.begin(); it!=mylist1.end(); ++it)
	// 		res << ' ' << *it;
	// 	compare_result(res1.str(), "mylist contains: 1101 2202");

	// 	res1 << "mylist2 contains:";
	// 	for (it=mylist2.begin(); it!=mylist2.end(); ++it)
	// 		res1 << ' ' << *it;
	// 	compare_result(res1.str(), "mylist contains: 1101 2202");

	// }catch(const std::exception &e){};


	// std::cout << std::endl << BLUE << "*************** TEST REMOVE ***************" << RESET << std::endl;
	// try{
	// 	int myints[]= {17,89,7,14};
	// 	ft::list<int> mylist (myints,myints+4);
	// 	std::stringstream res;

	// 	mylist.remove(89);

	// 	res << "mylist contains:";
	// 	for (ft::list<int>::Iterator it=mylist.begin(); it!=mylist.end(); ++it)
	// 		res << ' ' << *it;
	// 	compare_result(res.str(), "mylist contains: 17 7 14");
	// }catch(const std::exception &e){};


	// // std::cout << std::endl << BLUE << "*************** TEST REMOVE IF ***************" << RESET << std::endl;
	// // try{
	// // 	int myints[]= {15,36,7,17,20,39,4,1};
	// // 	ft::list<int> mylist (myints,myints+8);   // 15 36 7 17 20 39 4 1

	// // 	mylist.remove_if(single_digit);           // 15 36 17 20 39

	// // 	mylist.remove_if(is_odd());               // 36 20

	// // 	std::cout << "mylist contains:";
	// // 	for (ft::list<int>::Iterator it=mylist.begin(); it!=mylist.end(); ++it)
	// // 		std::cout << ' ' << *it;
	// // 	std::cout << '\n';
	// // }catch(const std::exception &e){};

	// // std::cout << std::endl << BLUE << "*************** TEST UNIQUE ***************" << RESET << std::endl;
	// // try{
	// // 	double mydoubles[]={ 12.15,  2.72, 73.0,  12.77,  3.14,
    // //                    12.77, 73.35, 72.25, 15.3,  72.25 };
	// // 	ft::list<double> mylist (mydoubles,mydoubles+10);
		
	// // 	mylist.sort();             //  2.72,  3.14, 12.15, 12.77, 12.77,
	// // 								// 15.3,  72.25, 72.25, 73.0,  73.35

	// // 	mylist.unique();           //  2.72,  3.14, 12.15, 12.77
	// // 								// 15.3,  72.25, 73.0,  73.35

	// // 	mylist.unique (same_integral_part);  //  2.72,  3.14, 12.15
	// // 										// 15.3,  72.25, 73.0

	// // 	mylist.unique (is_near());           //  2.72, 12.15, 72.25

	// // 	std::cout << "mylist contains:";
	// // 	for (ft::list<double>::Iterator it=mylist.begin(); it!=mylist.end(); ++it)
	// // 		std::cout << ' ' << *it;
	// // 	std::cout << '\n';
	// // }catch(const std::exception &e){};


	// // std::cout << std::endl << BLUE << "*************** TEST MERGE ***************" << RESET << std::endl;
	// // try{
	// // 	ft::list<double> first, second;

	// // 	first.push_back (3.1);
	// // 	first.push_back (2.2);
	// // 	first.push_back (2.9);

	// // 	second.push_back (3.7);
	// // 	second.push_back (7.1);
	// // 	second.push_back (1.4);

	// // 	first.sort();
	// // 	second.sort();

	// // 	first.merge(second);

	// // 	// (second is now empty)

	// // 	second.push_back (2.1);

	// // 	first.merge(second,mycomparison);

	// // 	std::cout << "first contains:";
	// // 	for (ft::list<double>::Iterator it=first.begin(); it!=first.end(); ++it)
	// // 		std::cout << ' ' << *it;
	// // 	std::cout << '\n';
	// // }catch(const std::exception &e){};


	std::cout << std::endl << BLUE << "*************** TEST SORT ***************" << RESET << std::endl;
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
			it++;
			std::cout << ' ' << *it;
		std::cout << '\n';

		mylist.sort(compare_nocase);

		std::cout << "mylist contains:";
		for (it=mylist.begin(); it!=mylist.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << '\n';

	}catch(const std::exception &e){};

	// std::cout << std::endl << BLUE << "*************** TEST REVERSE ***************" << RESET << std::endl;
	// try{
	// 	ft::list<int> mylist;

	// 	for (int i=1; i<10; ++i) mylist.push_back(i);

	// 	mylist.reverse();

	// 	std::cout << "mylist contains:";
	// 	for (ft::list<int>::Iterator it=mylist.begin(); it!=mylist.end(); ++it)
	// 		std::cout << ' ' << *it;

	// 	std::cout << '\n';
	// }catch(const std::exception &e){};


	// // std::cout << std::endl << BLUE << "***************  ***************" << RESET << std::endl;
	// // try{
		
	// // }catch(const std::exception &e){};


	// // std::cout << std::endl << BLUE << "***************  ***************" << RESET << std::endl;
	// // try{
		
	// // }catch(const std::exception &e){};
	return 0;
}