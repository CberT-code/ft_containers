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

 	ft::map<char,int> mymap;

  	// first insert function version (single parameter):

  	// second insert function version (with hint position):
  	ft::map<char,int>::Iterator it = mymap.begin();
  	mymap.insert (it, std::pair<char,int>('b',300));  // max efficiency inserting

 	mymap.insert (it, std::pair<char,int>('d',400));  // no max efficiency inserting
	mymap.insert (it, std::pair<char,int>('a',200));  // no max efficiency inserting

	mymap.insert (it, std::pair<char,int>('f',10));  // no max efficiency inserting



	return 0;
}