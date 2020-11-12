/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_main.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbertola <cbertola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 11:50:38 by cbertola          #+#    #+#             */
/*   Updated: 2020/11/12 11:50:44 by cbertola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Headers/Header.hpp"

int vector_main(void) {

	std::cout << std::endl << std::endl << YELLOW;
	std::cout << "***********************************************************" << std::endl;
	std::cout << "*****************          VECTOR         *****************" << std::endl;
	std::cout << "***********************************************************" << std::endl;
	std::cout << RESET << std::endl << std::endl;

	/**************************************************
	***************** Member functions ****************
	**************************************************/

	std::cout << std::endl << BLUE << "**********    Constructor      **********" << RESET << std::endl;
	try{
		std::stringstream res;

		 // constructors used in the same order as described above:
		ft::vector<int> first;                                // empty vector of ints
		ft::vector<int> second (4,100);                     // four ints with value 100
		ft::vector<int> third (second.begin(),second.end());  // iterating through second          // four ints with value 100
		ft::vector<int> fourth (third);                       // a copy of third

		// the iterator constructor can also be used to construct from arrays:
		int myints[] = {16,2,77,29};
		ft::vector<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );

		res << "The contents of fifth are:";
		for (ft::vector<int>::Iterator it = fifth.begin(); it != fifth.end(); ++it)
			res << ' ' << *it;
		compare_result(res.str(), "The contents of fifth are: 16 2 77 29");
	}catch(const std::exception &e){};

	std::cout << std::endl << BLUE << "**********     Operator =      **********" << RESET << std::endl;
	try{
		ft::vector<int> foo (3,0);
		ft::vector<int> bar (5,0);
		std::stringstream res1;
		std::stringstream res2;

		bar = foo;
		foo = ft::vector<int>();

		res1 << "Size of foo: " << int(foo.size());
		res2 << "Size of bar: " << int(bar.size());
		compare_result(res1.str(), "Size of foo: 0");
		compare_result(res2.str(), "Size of bar: 3");
	}catch(const std::exception &e){};

	/**************************************************
	******************** Iterators ********************
	**************************************************/

	std::cout << std::endl << BLUE << "**********        Begin        **********" << RESET << std::endl;
	try{
		std::stringstream res;
		ft::vector<int> myvector;
		for (int i=1; i<=5; i++) myvector.push_back(i);

		res << "myvector contains:";
		for (ft::vector<int>::Iterator it = myvector.begin() ; it != myvector.end(); ++it)
			res << ' ' << *it;
		compare_result(res.str(), "myvector contains: 1 2 3 4 5");
	}catch(const std::exception &e){};
	
	std::cout << std::endl << BLUE << "**********         End         **********" << RESET << std::endl;
	try{
		std::stringstream res;
		ft::vector<int> myvector;
		for (int i=1; i<=5; i++){
		 myvector.push_back(i);
		}

		res << "myvector contains:";
		for (ft::vector<int>::Iterator it = myvector.begin() ; it != myvector.end(); ++it)
			res << ' ' << *it;

		compare_result(res.str(), "myvector contains: 1 2 3 4 5");
	}catch(const std::exception &e){};
	
	std::cout << std::endl << BLUE << "**********       Rbegin        **********" << RESET << std::endl;
	try{
		std::stringstream res;
		ft::vector<int> myvector (5);  // 5 default-constructed ints

		int i=0;

		for (ft::vector<int>::reverse_Iterator rit = myvector.rbegin(); rit != myvector.rend(); ++rit){
			*rit = ++i;
		}
		res << "myvector contains:";
		for (ft::vector<int>::Iterator it = myvector.begin(); it != myvector.end(); ++it)
			res << ' ' << *it;

		compare_result(res.str(), "myvector contains: 5 4 3 2 1");
	}catch(const std::exception &e){};

	std::cout << std::endl << BLUE << "**********        Rend         **********" << RESET << std::endl;
	try{
		std::stringstream res;
		ft::vector<int> myvector (5);  // 5 default-constructed ints

		ft::vector<int>::reverse_Iterator rit = myvector.rbegin();

		int i=0;
		for (rit = myvector.rbegin(); rit!= myvector.rend(); ++rit)
			*rit = ++i;

		res << "myvector contains:";
		for (ft::vector<int>::Iterator it = myvector.begin(); it != myvector.end(); ++it)
			res << ' ' << *it;

		compare_result(res.str(), "myvector contains: 5 4 3 2 1");
	}catch(const std::exception &e){};

	/**************************************************
	********************* Capacity ********************
	**************************************************/

	std::cout << std::endl << BLUE << "**********        Size         **********" << RESET << std::endl;
	try{
		std::stringstream res;
		std::stringstream res1;
		std::stringstream res2;
		std::stringstream res3;
		ft::vector<int> myints;
		res << "0. size: " << myints.size();

		for (int i=0; i<10; i++) myints.push_back(i);
		res1 << "1. size: " << myints.size();

		ft::vector<int>::Iterator it;
		it = myints.end();
		it--;
		it--;
		it--;
		myints.insert (it,10,100);
		res2 << "2. size: " << myints.size();

		myints.pop_back();
		res3 << "3. size: " << myints.size();

		compare_result(res.str(), "0. size: 0");
		compare_result(res1.str(), "1. size: 10");
		compare_result(res2.str(), "2. size: 20");
		compare_result(res3.str(), "3. size: 19");
	}catch(const std::exception &e){};

	std::cout << std::endl << BLUE << "**********      Max_Size       **********" << RESET << std::endl;
	try{
		std::stringstream res;
		std::stringstream res1;
		std::stringstream res2;
		
		ft::vector<int> myvector;

	// set some content in the vector:
		for (int i=0; i<100; i++) myvector.push_back(i);

		res << "size: " << myvector.size();
		res1 << "capacity: " << myvector.capacity();
		res2 << "max_size: " << myvector.max_size();

		compare_result(res.str(), "size: 100");
		compare_result(res1.str(), "capacity: 128");
		compare_result(res2.str(), "max_size: 4611686018427387903");
	}catch(const std::exception &e){};

	std::cout << std::endl << BLUE << "**********       Resize        **********" << RESET << std::endl;
	try{
		std::stringstream res;
		ft::vector<int> myvector;

		// set some initial content:
		for (int i=1;i<10;i++) myvector.push_back(i);

		myvector.resize(5);
		myvector.resize(8,100);
		myvector.resize(12);

		res << "myvector contains:";
		for (size_t i=0;i<myvector.size();i++)
  		res << ' ' << myvector[i];

		compare_result(res.str(), "myvector contains: 1 2 3 4 5 100 100 100 0 0 0 0");
	}catch(const std::exception &e){};

	std::cout << std::endl << BLUE << "**********      Capacity       **********" << RESET << std::endl;
	try{
		std::stringstream res;
		std::stringstream res1;
		std::stringstream res2;
		ft::vector<int> myvector;

		// set some content in the vector:
		for (int i=0; i<100; i++) myvector.push_back(i);

		res << "size: " << (int) myvector.size();
		res1 << "capacity: " << (int) myvector.capacity();
		res2 << "max_size: " << (int) myvector.max_size();
		compare_result(res.str(), "size: 100");
		compare_result(res1.str(), "capacity: 128");
		compare_result(res2.str(), "max_size: -1");
	}catch(const std::exception &e){};

	std::cout << std::endl << BLUE << "**********        Empty        **********" << RESET << std::endl;
	try{
		std::stringstream res;
		ft::vector<int> myvector;
		int sum (0);

		for (int i=1;i<=10;i++) myvector.push_back(i);

		while (!myvector.empty())
		{
			sum += myvector.back();
			myvector.pop_back();
		}

		res << "total: " << sum;
		compare_result(res.str(), "total: 55");
	}catch(const std::exception &e){};

	std::cout << std::endl << BLUE << "**********       Reserve       **********" << RESET << std::endl;
	try{
		std::stringstream res;
		ft::vector<int>::size_type sz;

		ft::vector<int> foo;
		sz = foo.capacity();
		res << "making foo grow:\n";
		for (int i=0; i<100; ++i) {
			foo.push_back(i);
			if (sz!=foo.capacity()) {
			sz = foo.capacity();
			res << "capacity changed: " << sz << '\n';
			}
		}

		ft::vector<int> bar;
		sz = bar.capacity();
		bar.reserve(100);   // this is the only difference with foo above
		res << "making bar grow:\n";
		for (int i=0; i<100; ++i) {
			bar.push_back(i);
			if (sz!=bar.capacity()) {
			sz = bar.capacity();
			res << "capacity changed: " << sz;
			}
		}
		compare_result(res.str(), "making foo grow:\ncapacity changed: 1\ncapacity changed: 2\ncapacity changed: 4\ncapacity changed: 8\ncapacity changed: 16\ncapacity changed: 32\ncapacity changed: 64\ncapacity changed: 128\nmaking bar grow:\ncapacity changed: 100");
	}catch(const std::exception &e){};

	/**************************************************
	***************** Element Access ******************
	**************************************************/

	std::cout << std::endl << BLUE << "**********     Operator []     **********" << RESET << std::endl;
	try{
		std::stringstream res;
		ft::vector<int> myvector (10);   // 10 zero-initialized elements

		ft::vector<int>::size_type sz = myvector.size();

		// assign some values:
		for (unsigned i=0; i<sz; i++) myvector[i]=i;

		// reverse vector using operator[]:
		for (unsigned i=0; i<sz/2; i++)
		{
			int temp;
			temp = myvector[sz-1-i];
			myvector[sz-1-i]=myvector[i];
			myvector[i]=temp;
		}

		res << "myvector contains:";
		for (unsigned i=0; i<sz; i++)
			res << ' ' << myvector[i];
		compare_result(res.str(), "myvector contains: 9 8 7 6 5 4 3 2 1 0");
	}catch(const std::exception &e){};

	std::cout << std::endl << BLUE << "**********         At          **********" << RESET << std::endl;
	try{
		std::stringstream res;
		ft::vector<int> myvector (10);   // 10 zero-initialized ints

		// assign some values:
		for (unsigned i=0; i<myvector.size(); i++)
			myvector.at(i)=i;

		res << "myvector contains:";
		for (unsigned i=0; i<myvector.size(); i++)
			res << ' ' << myvector.at(i);
		compare_result(res.str(), "myvector contains: 0 1 2 3 4 5 6 7 8 9");
	}catch(const std::exception &e){};

	std::cout << std::endl << BLUE << "**********        Front        **********" << RESET << std::endl;
	try{
		std::stringstream res;
		ft::vector<int> myvector;

		myvector.push_back(78);
		myvector.push_back(16);

		// now front equals 78, and back 16

		myvector.front() -= myvector.back();

		res << "myvector.front() is now " << myvector.front();
		compare_result(res.str(), "myvector.front() is now 62");
	}catch(const std::exception &e){};

	std::cout << std::endl << BLUE << "**********        Back         **********" << RESET << std::endl;
	try{
		std::stringstream res;
		ft::vector<int> myvector;

		myvector.push_back(10);

		while (myvector.back() != 0)
		{
			myvector.push_back ( myvector.back() -1 );
		}

		res << "myvector contains:";
		for (unsigned i=0; i<myvector.size() ; i++)
			res << ' ' << myvector[i];
		compare_result(res.str(), "myvector contains: 10 9 8 7 6 5 4 3 2 1 0");
	}catch(const std::exception &e){};

	/**************************************************
	***************** Element Access ******************
	**************************************************/

	std::cout << std::endl << BLUE << "**********       Assign        **********" << RESET << std::endl;
	try{
		std::stringstream res;
		std::stringstream res1;
		std::stringstream res2;
		ft::vector<int> first;
		ft::vector<int> second;
		ft::vector<int> third;

		first.assign (7,100);             // 7 ints with a value of 100

		ft::vector<int>::Iterator it;
		it=first.begin()+1;

		second.assign (it,first.end()-1); // the 5 central values of first

		int myints[] = {1776,7,4};
		third.assign (myints,myints+3);   // assigning from array.

		res << "Size of first: " << int (first.size());
		res1 << "Size of second: " << int (second.size());
		res2 << "Size of third: " << int (third.size());
		compare_result(res.str(), "Size of first: 7");
		compare_result(res1.str(), "Size of second: 5");
		compare_result(res2.str(), "Size of third: 3");
	}catch(const std::exception &e){};

	std::cout << std::endl << BLUE << "**********      Push_back      **********" << RESET << std::endl;
	try{
		ft::vector<int> myvector;
		int myint;

		std::cout << "Please enter some integers (enter 0 to end):\n";

		do {
			std::cin >> myint;
			myvector.push_back (myint);
		} while (myint);

		std::cout << "myvector stores " << int(myvector.size()) << " numbers.\n";
	}catch(const std::exception &e){};

	std::cout << std::endl << BLUE << "**********      Pop_back       **********" << RESET << std::endl;
	try{
		ft::vector<int> myvector;
		int myint;

		std::cout << "Please enter some integers (enter 0 to end):\n";

		do {
			std::cin >> myint;
			myvector.push_back (myint);
		} while (myint);

		std::cout << "myvector stores " << int(myvector.size()) << " numbers.\n";
	}catch(const std::exception &e){};

	std::cout << std::endl << BLUE << "**********       Insert        **********" << RESET << std::endl;
	try{
		std::stringstream res;
		ft::vector<int> myvector (3,100);
		ft::vector<int>::Iterator it;

		it = myvector.begin();
		it = myvector.insert ( it , 200 );

		myvector.insert (it,2,300);

		// // "it" no longer valid, get a new one:
		it = myvector.begin();

		ft::vector<int> anothervector (2,400);
		myvector.insert (it+2,anothervector.begin(),anothervector.end());

		int myarray [] = { 501,502,503 };
		myvector.insert (myvector.begin(), myarray, myarray+3);

		res << "myvector contains:";
		for (it=myvector.begin(); it<myvector.end(); it++)
			res << ' ' << *it;
		compare_result(res.str(), "myvector contains: 501 502 503 300 300 400 400 200 100 100 100");
	}catch(const std::exception &e){};

	std::cout << std::endl << BLUE << "**********        Erase        **********" << RESET << std::endl;
	try{
		std::stringstream res;
		ft::vector<int> myvector;

		// set some values (from 1 to 10)
		for (int i=1; i<=10; i++) myvector.push_back(i);

		// // erase the 6th element
		myvector.erase (myvector.begin()+5);

		// erase the first 3 elements:
		myvector.erase (myvector.begin(),myvector.begin()+3);

// attends mais je l'affiche plus ici, je le met dans res.... hein???
		res << "myvector contains:";
		for (unsigned i=0; i<myvector.size(); ++i)
			res << ' ' << myvector[i];
		compare_result(res.str(), "myvector contains: 4 5 7 8 9 10");
	}catch(const std::exception &e){};

	std::cout << std::endl << BLUE << "**********        Swap         **********" << RESET << std::endl;
	try{
		std::stringstream res;
		std::stringstream res1;
		ft::vector<int> foo (3,100);   // three ints with a value of 100
		ft::vector<int> bar (5,200);   // five ints with a value of 200

		foo.swap(bar);

		res << "foo contains:";
		for (unsigned i=0; i<foo.size(); i++)
			res << ' ' << foo[i];

		res1 << "bar contains:";
		for (unsigned i=0; i<bar.size(); i++)
			res1 << ' ' << bar[i];
		compare_result(res.str(), "foo contains: 200 200 200 200 200");
		compare_result(res1.str(), "bar contains: 100 100 100");
	}catch(const std::exception &e){};

	std::cout << std::endl << BLUE << "**********        Clear        **********" << RESET << std::endl;
	try{
		std::stringstream res;
		std::stringstream res1;
		ft::vector<int> myvector;
		myvector.push_back (100);
		myvector.push_back (200);
		myvector.push_back (300);

		res << "myvector contains:";
		for (unsigned i=0; i<myvector.size(); i++)
			res << ' ' << myvector[i];

		myvector.clear();
		myvector.push_back (1101);
		myvector.push_back (2202);

		res1 << "myvector contains:";
		for (unsigned i=0; i<myvector.size(); i++)
			res1 << ' ' << myvector[i];
		compare_result(res.str(), "myvector contains: 100 200 300");
		compare_result(res1.str(), "myvector contains: 1101 2202");
	}catch(const std::exception &e){};

	std::cout << std::endl << BLUE << "********** Operator non membre **********" << RESET << std::endl;
	try{
		std::stringstream res;
		ft::vector<int> foo (3,100);   // three ints with a value of 100
		ft::vector<int> bar (2,200);   // two ints with a value of 200

		if (foo==bar) res << "foo and bar are equal";
		if (foo!=bar) res << "foo and bar are not equal\n";
		if (foo< bar) res << "foo is less than bar\n";
		if (foo> bar) res << "foo is greater than bar\n";
		if (foo<=bar) res << "foo is less than or equal to bar";
		if (foo>=bar) res << "foo is greater than or equal to bar";
		compare_result(res.str(), "foo and bar are not equal\nfoo is less than bar\nfoo is less than or equal to bar");
	}catch(const std::exception &e){};

	std::cout << std::endl << BLUE << "**********        Swap         **********" << RESET << std::endl;
	try{
		std::stringstream res;
		std::stringstream res1;
		ft::vector<int> foo (3,100);   // three ints with a value of 100
		ft::vector<int> bar (5,200);   // five ints with a value of 200

		foo.swap(bar);

		res << "foo contains:";
		for (ft::vector<int>::Iterator it = foo.begin(); it!=foo.end(); ++it)
			res << ' ' << *it;

		res1 << "bar contains:";
		for (ft::vector<int>::Iterator it = bar.begin(); it!=bar.end(); ++it)
			res1 << ' ' << *it;
		compare_result(res.str(), "foo contains: 200 200 200 200 200");
		compare_result(res1.str(), "bar contains: 100 100 100");
	}catch(const std::exception &e){};

	std::cout << std::endl << std::endl << YELLOW;
	std::cout << "***********************************************************" << std::endl;
	std::cout << "************              Vector BOOL            **********" << std::endl;
	std::cout << "***********************************************************" << std::endl;
	std::cout << RESET << std::endl << std::endl;

	std::cout << std::endl << BLUE << "**********      Flip BOOL      **********" << RESET << std::endl;
	try{
		std::stringstream res;
		ft::vector<bool> mask;

		mask.push_back(true);
		mask.push_back(false);
		mask.push_back(false);
		mask.push_back(true);

		mask.flip();

		res << std::boolalpha;
		res << "mask contains:";
		for (unsigned i=0; i<mask.size(); i++)
			res << ' ' << mask.at(i);
		compare_result(res.str(), "mask contains: false true true false");
	}catch(const std::exception &e){};

	std::cout << std::endl << BLUE << "**********      SWAP BOOL      **********" << RESET << std::endl;
	try{
		std::stringstream res;
		std::stringstream res1;
		ft::vector<bool> foo;
		ft::vector<bool> bar;

		foo.push_back(false);
		foo.push_back(true);
		foo.push_back(false);

		bar.push_back(true);
		bar.push_back(false);

		foo.swap (foo[0], foo[1]);
		bar.swap (bar.front(), bar.back());

		foo.swap(bar);

		res << std::boolalpha;
		res1 << std::boolalpha;
		res << "foo contains:";
		for (unsigned i=0; i<foo.size(); i++) res << ' ' << foo[i];
		res1 << "bar contains:";
		for (unsigned i=0; i<bar.size(); i++) res1 << ' ' << bar[i];
		compare_result(res.str(), "foo contains: false true");
		compare_result(res1.str(), "bar contains: true false false");
	}catch(const std::exception &e){};
	return 0;
}
