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

	bool fncomp(char lhs, char rhs){
		return lhs < rhs ;
	}

	struct classcomp {
		bool operator() (const char& lhs, const char& rhs) const
		{return lhs<rhs;}
	};

int map_main()
{

 	 std::map<char,int> mymap;
  std::map<char,int>::iterator itlow,itup;

  mymap['e']=100;
  mymap['b']=40;
  mymap['f']=80;
  mymap['a']=20;
  mymap['c']=60;
  mymap['d']=80;


  itlow=mymap.lower_bound ('b');  // itlow points to b
  itup=mymap.upper_bound ('c');   // itup points to e (not d!)

  mymap.erase(itlow,itup);        // erases [itlow,itup)

  // print content:
  for (std::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
    std::cout << it->first << " => " << it->second << '\n';

	return 0;
}