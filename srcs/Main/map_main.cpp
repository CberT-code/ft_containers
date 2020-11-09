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

#include<map>
#include<iterator>

	bool fncomp (char lhs, char rhs) {return lhs<rhs;}

	struct classcomp {
	bool operator() (const char& lhs, const char& rhs) const
	{return lhs<rhs;}
	};

int map_main()
{
	std::cout << std::endl << std::endl << YELLOW;
	std::cout << "***********************************************************" << std::endl;
	std::cout << "*****************             MAP         *****************" << std::endl;
	std::cout << "***********************************************************" << std::endl;
	std::cout << RESET << std::endl << std::endl;

	// std::cout << std::endl << BLUE << "**********     Constructor      **********" << RESET << std::endl;
	// try{
	// 	std::stringstream 	res;
	// 	ft::map<char,int> first;

	// 	first['a']=10;
	// 	first['b']=30;
	// 	first['c']=50;
	// 	first['d']=70;

	// 	ft::map<char,int> second (first.begin(),first.end());

	// 	ft::map<char,int> third (second);

	// 	ft::map<char,int,classcomp> fourth;                 // class as Compare

	// 	bool(*fn_pt)(char,char) = fncomp;
	// 	ft::map<char,int,bool(*)(char,char)> fifth (fn_pt); 
	// 	compare_result(res.str(), "The contents of fifth are: 16 2 77 29");
	// }catch(const std::exception &e){};

	std::cout << std::endl << BLUE << "**********       Operator=        **********" << RESET << std::endl;
	try{
		std::stringstream 	res;
		ft::map<char,int> first;
		ft::map<char,int> second;

		first['x']=8;
		first['y']=16;
		first['z']=32;

		second=first;                // second now contains 3 ints
		first=ft::map<char,int>();  // and first is now empty

		res << "Size of first: " << first.size() << '\n';
		res << "Size of second: " << second.size();
		compare_result(res.str(), "Size of first: 0\nSize of second: 3");
	}catch(const std::exception &e){};

	std::cout << std::endl << BLUE << "**********         Begin        **********" << RESET << std::endl;
	try{
		std::stringstream 	res;
		ft::map<char,int> 	mymap;

		mymap['b'] = 100;
		mymap['a'] = 200;
		mymap['c'] = 300;

		// show content:
		for (ft::map<char,int>::Iterator it=mymap.begin(); it!=mymap.end(); ++it)
		res << it->first << " => " << it->second << "\n";
		compare_result(res.str(), "a => 200\nb => 100\nc => 300\n");
	}catch(const std::exception &e){};

	std::cout << std::endl << BLUE << "**********          End         **********" << RESET << std::endl;
	try{
		std::stringstream 	res;
		ft::map<char,int> 	mymap;

		mymap['b'] = 100;
		mymap['a'] = 200;
		mymap['c'] = 300;

		// show content:
		for (ft::map<char,int>::Iterator it=mymap.begin(); it!=mymap.end(); ++it)
		res << it->first << " => " << it->second << "\n";
		compare_result(res.str(), "a => 200\nb => 100\nc => 300\n");
	}catch(const std::exception &e){};

 	std::cout << std::endl << BLUE << "**********         Rbegin       **********" << RESET << std::endl;
	try{
		std::stringstream 	res;
		ft::map<char,int> mymap;

		mymap['x'] = 100;
		mymap['y'] = 200;
		mymap['z'] = 300;

		// show content:
		ft::map<char,int>::reverse_Iterator rit;
		for (rit=mymap.rbegin(); rit!=mymap.rend(); ++rit)
			res<< rit->first << " => " << rit->second << '\n';
		compare_result(res.str(), "z => 300\ny => 200\nx => 100\n");
	}catch(const std::exception &e){};

	std::cout << std::endl << BLUE << "**********          Rend        **********" << RESET << std::endl;
	try{
		std::stringstream 	res;
		ft::map<char,int>	mymap;

		mymap['x'] = 100;
		mymap['y'] = 200;
		mymap['z'] = 300;

		// show content:
		ft::map<char,int>::reverse_Iterator rit;
		for (rit=mymap.rbegin(); rit!=mymap.rend(); ++rit)
			res << rit->first << " => " << rit->second << "\n";
		compare_result(res.str(), "z => 300\ny => 200\nx => 100\n");
	}catch(const std::exception &e){};

	std::cout << std::endl << BLUE << "**********          Empty        **********" << RESET << std::endl;
	try{
		std::stringstream 	res;
		std::map<char,int> mymap;
		
		mymap['a']=10;
		mymap['b']=20;
		mymap['c']=30;

		while (!mymap.empty())
		{
			std::cout << "test ici" << std::endl;
			res << mymap.begin()->first << " => " << mymap.begin()->second << '\n';
			mymap.erase(mymap.begin());
		}
		compare_result(res.str(), "a => 10\nb => 20\nc => 30\n");
	}catch(const std::exception &e){};

	std::cout << std::endl << BLUE << "**********          Size        **********" << RESET << std::endl;
	try{
		std::stringstream 	res;
		ft::map<char,int> mymap;
		mymap['a']=101;
		mymap['b']=202;
		mymap['c']=302;

		res << "mymap.size() is " << mymap.size();
		compare_result(res.str(), "mymap.size() is 3");
	}catch(const std::exception &e){};

	std::cout << std::endl << BLUE << "**********        Max_size      **********" << RESET << std::endl;
	try{
		int i;
		ft::map<int,int> mymap;

		if (mymap.max_size()>1000)
		{
			for (i=0; i<1000; i++) mymap[i]=0;
			std::cout << "The map contains 1000 elements.\n";
		}
		else std::cout << "The map could not hold 1000 elements.\n";
	}catch(const std::exception &e){};

	std::cout << std::endl << BLUE << "**********        Operator[]     **********" << RESET << std::endl;
	try{
		std::stringstream 			res;
		ft::map<char,std::string>	mymap;

		mymap['a']="an element";
		mymap['b']="another element";
		mymap['c']=mymap['b'];

		res << "mymap['a'] is " << mymap['a'] << '\n';
		res << "mymap['b'] is " << mymap['b'] << '\n';
		res << "mymap['c'] is " << mymap['c'] << '\n';
		res << "mymap['d'] is" << mymap['d'] << '\n';

		res << "mymap now contains " << mymap.size() << " elements.\n";
		compare_result(res.str(), "mymap['a'] is an element\nmymap['b'] is another element\nmymap['c'] is another element\nmymap['d'] is\nmymap now contains 4 elements.\n");
	}catch(const std::exception &e){};

	std::cout << std::endl << BLUE << "**********         insert       **********" << RESET << std::endl;
	try{
		std::stringstream 	res;
		ft::map<char,int> mymap;

		// first insert function version (single parameter):
		mymap.insert ( std::pair<char,int>('a',100) );
		mymap.insert ( std::pair<char,int>('z',200) );

		std::pair<ft::map<char,int>::Iterator,bool> ret;
		ret = mymap.insert ( std::pair<char,int>('z',500) );
		if (ret.second==false) {
			res << "element 'z' already existed";
			res << " with a value of " << ret.first->second << '\n';
		}

		// second insert function version (with hint position):
		ft::map<char,int>::Iterator it = mymap.begin();
		mymap.insert (it, std::pair<char,int>('b',300));  // max efficiency inserting
		mymap.insert (it, std::pair<char,int>('c',400));  // no max efficiency inserting

		// third insert function version (range insertion):
		ft::map<char,int> anothermap;
		anothermap.insert(mymap.begin(),mymap.find('c'));

		// showing contents:
		res << "mymap contains:\n";
		for (it=mymap.begin(); it!=mymap.end(); ++it)
			res << it->first << " => " << it->second << '\n';

		res << "anothermap contains:\n";
		for (it=anothermap.begin(); it!=anothermap.end(); ++it)
			res << it->first << " => " << it->second << '\n';
		compare_result(res.str(), "element 'z' already existed with a value of 200\nmymap contains:\na => 100\nb => 300\nc => 400\nz => 200\nanothermap contains:\na => 100\nb => 300\n");
	}catch(const std::exception &e){};

	std::cout << std::endl << BLUE << "**********        Erase      **********" << RESET << std::endl;
	try{
		std::stringstream 	res;
		ft::map<char,int> mymap;
		ft::map<char,int>::Iterator it;

		// insert some values:
		mymap['a']=10;
		mymap['b']=20;
		mymap['c']=30;
		mymap['d']=40;
		mymap['e']=50;
		mymap['f']=60;

		it=mymap.find('b');
		mymap.erase (it);                   // erasing by iterator

		mymap.erase ('c');                  // erasing by key

		it=mymap.find ('e');
		mymap.erase ( it, mymap.end() );    // erasing by range

		// show content:
		for (it=mymap.begin(); it!=mymap.end(); ++it)
			res << it->first << " => " << it->second << '\n';
		compare_result(res.str(), "a => 10\nd => 40\n");
	}catch(const std::exception &e){};

	// std::cout << std::endl << BLUE << "**********         Swap        **********" << RESET << std::endl;
	// try{
	// 	std::stringstream 	res;
	// 	ft::map<char,int> foo,bar;

	// 	foo['x']=100;
	// 	foo['y']=200;

	// 	bar['a']=11;
	// 	bar['b']=22;
	// 	bar['c']=33;

	// 	foo.swap(bar);

	// 	std::cout << "foo contains:\n";
	// 	for (ft::map<char,int>::Iterator it=foo.begin(); it!=foo.end(); ++it)
	// 		std::cout << it->first << " => " << it->second << '\n';

	// 	std::cout << "bar contains:\n";
	// 	for (ft::map<char,int>::Iterator it=bar.begin(); it!=bar.end(); ++it)
	// 		std::cout << it->first << " => " << it->second << '\n';
	// 	compare_result(res.str(), "foo contains:\na => 11\nb => 22\nc => 33\nbar contains:\nx => 100\ny => 200\n");
	// }catch(const std::exception &e){};

	std::cout << std::endl << BLUE << "**********        Reserve //check clear       **********" << RESET << std::endl;
	try{
		std::stringstream 	res;
		ft::map<char,int> mymap;

		mymap['x']=100;
		mymap['y']=200;
		mymap['z']=300;

		res << "mymap contains:\n";
		for (ft::map<char,int>::Iterator it=mymap.begin(); it!=mymap.end(); ++it)
			res << it->first << " => " << it->second << '\n';

		// mymap.clear();
		mymap['a']=1101;
		mymap['b']=2202;

		res << "mymap contains:\n";
		for (ft::map<char,int>::Iterator it=mymap.begin(); it!=mymap.end(); ++it)
			res << it->first << " => " << it->second << '\n';
		compare_result(res.str(), "mymap contains:\nx => 100\ny => 200\nz => 300\nmymap contains:\na => 1101\nb => 2202\n");
	}catch(const std::exception &e){};

	std::cout << std::endl << BLUE << "**********      key_comp      **********" << RESET << std::endl;
	try{
		std::stringstream 	res;
		ft::map<char,int> mymap;

		ft::map<char,int>::key_compare mycomp = mymap.key_comp();

		mymap['a']=100;
		mymap['b']=200;
		mymap['c']=300;

		res << "mymap contains:\n";

		char highest = mymap.rbegin()->first;     // key value of last element

		ft::map<char,int>::Iterator it = mymap.begin();
		do {
			res << it->first << " => " << it->second << '\n';
		} while ( mycomp((*it++).first, highest) );

		compare_result(res.str(), "mymap contains:\na => 100\nb => 200\nc => 300\n");
	}catch(const std::exception &e){};

	// std::cout << std::endl << BLUE << "**********          value_comp          **********" << RESET << std::endl;
	// try{
	// 	std::stringstream 	res;
	// 	ft::map<char,int> mymap;

	// 	mymap['x']=1001;
	// 	mymap['y']=2002;
	// 	mymap['z']=3003;

	// 	std::cout << "mymap contains:\n";

	// 	std::pair<char,int> highest = *mymap.rbegin();          // last element

	// 	ft::map<char,int>::Iterator it = mymap.begin();
	// 	do {
	// 		std::cout << it->first << " => " << it->second << '\n';
	// 	} while ( mymap.value_comp()(*it++, highest) );

	// 	compare_result(res.str(), "myvector contains: 0 1 2 3 4 5 6 7 8 9");
	// }catch(const std::exception &e){};

	// std::cout << std::endl << BLUE << "**********         Find        **********" << RESET << std::endl;
	// try{
	// 	std::stringstream 	res;
	// 	ft::map<char,int> mymap;
	// 	ft::map<char,int>::Iterator it;

	// 	mymap['a']=50;
	// 	mymap['b']=100;
	// 	mymap['c']=150;
	// 	mymap['d']=200;

	// 	it = mymap.find('b');
	// 	if (it != mymap.end())
	// 		mymap.erase (it);

	// 	// print content:
	// 	res << "elements in mymap:" << '\n';
	// 	res << "a => " << mymap.find('a')->second << '\n';
	// 	res << "c => " << mymap.find('c')->second << '\n';
	// 	res << "d => " << mymap.find('d')->second << '\n';

	// 	compare_result(res.str(), "elements in mymap:\na => 50\nc => 150\nd => 200\n");
	// }catch(const std::exception &e){};

	std::cout << std::endl << BLUE << "**********         Back         **********" << RESET << std::endl;
	try{
		std::stringstream 	res;
		ft::map<char,int> mymap;
		char c;

		mymap ['a']=101;
		mymap ['c']=202;
		mymap ['f']=303;

		for (c='a'; c<'h'; c++)
		{
			res << c;
			if (mymap.count(c)>0)
			res << " is an element of mymap.\n";
			else 
			res << " is not an element of mymap.\n";
		}
		compare_result(res.str(), "a is an element of mymap.\nb is not an element of mymap.\nc is an element of mymap.\nd is not an element of mymap.\ne is not an element of mymap.\nf is an element of mymap.\ng is not an element of mymap.\n");
	}catch(const std::exception &e){};

	std::cout << std::endl << BLUE << "**********        Count        **********" << RESET << std::endl;
	try{
		std::stringstream 	res;
		ft::map<char,int> mymap;
		char c;

		mymap ['a']=101;
		mymap ['c']=202;
		mymap ['f']=303;

		for (c='a'; c<'h'; c++)
		{
			res << c;
			if (mymap.count(c)>0)
			res << " is an element of mymap.\n";
			else 
			res << " is not an element of mymap.\n";
		}
		compare_result(res.str(), "a is an element of mymap.\nb is not an element of mymap.\nc is an element of mymap.\nd is not an element of mymap.\ne is not an element of mymap.\nf is an element of mymap.\ng is not an element of mymap.\n");
	}catch(const std::exception &e){};

	std::cout << std::endl << BLUE << "**********      Lower_bound      **********" << RESET << std::endl;
	try{
		std::stringstream 	res;
		ft::map<char,int> mymap;
		ft::map<char,int>::Iterator itlow,itup;

		mymap['a']=20;
		mymap['b']=40;
		mymap['c']=60;
		mymap['d']=80;
		mymap['e']=100;

		itlow=mymap.lower_bound ('b');  // itlow points to b
		itup=mymap.upper_bound ('d');   // itup points to e (not d!)

		mymap.erase(itlow,itup);        // erases [itlow,itup)

		// print content:
		for (ft::map<char,int>::Iterator it=mymap.begin(); it!=mymap.end(); ++it)
			res << it->first << " => " << it->second << '\n';
		compare_result(res.str(), "a => 20\ne => 100\n");
	}catch(const std::exception &e){};

	std::cout << std::endl << BLUE << "**********      Upper_bound      **********" << RESET << std::endl;
	try{
		std::stringstream 	res;
		std::map<char,int> mymap;
		std::map<char,int>::iterator itlow,itup;

		mymap['a']=20;
		mymap['b']=40;
		mymap['c']=60;
		mymap['d']=80;
		mymap['e']=100;

		itlow=mymap.lower_bound ('b');  // itlow points to b
		itup=mymap.upper_bound ('d');   // itup points to e (not d!)

		mymap.erase(itlow,itup);        // erases [itlow,itup)

		// print content:
		for (std::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
			res << it->first << " => " << it->second << '\n';
		compare_result(res.str(), "a => 20\ne => 100\n");
	}catch(const std::exception &e){};

	std::cout << std::endl << BLUE << "**********      equal_range      **********" << RESET << std::endl;
	try{
		std::stringstream 	res;
		std::map<char,int> mymap;

		mymap['a']=10;
		mymap['b']=20;
		mymap['c']=30;

		std::pair<std::map<char,int>::iterator,std::map<char,int>::iterator> ret;
		ret = mymap.equal_range('b');

		res << "lower bound points to: ";
		res << ret.first->first << " => " << ret.first->second << '\n';

		res << "upper bound points to: ";
		res << ret.second->first << " => " << ret.second->second << '\n';

		compare_result(res.str(), "lower bound points to: b => 20\nupper bound points to: c => 30\n");
	}catch(const std::exception &e){};

	return 0;
}