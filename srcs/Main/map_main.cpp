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

  ft::map<char,int> first;
first.insert(std::make_pair('c',45));
std::cout << RED << "1" << RESET << std::endl;
first.insert(std::make_pair('a',55));
std::cout << RED << "2" << RESET << std::endl;
first.insert(std::make_pair('b',65));
//   first['a']=10;
//   first['b']=30;
//   first['c']=50;
//   first['d']=70;

  ft::map<char,int> second (first.begin(),first.end());

  ft::map<char,int> third (second);

  ft::map<char,int,classcomp> fourth;                 // class as Compare

//   bool(*fn_pt)(char,char) = fncomp;
//   ft::map<char,int,bool(*)(char,char)> fifth (fn_pt); // function pointer as Compare


	return 0;
}