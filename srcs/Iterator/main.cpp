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

// a predicate implemented as a function:
bool single_digit (const int& value) { return (value<10); }

// a predicate implemented as a class:
struct is_odd {
  bool operator() (const int& value) { return (value%2)==1; }
};

int main ()
{
  int myints[]= {15,36,7,17,20,39,4,1};
  ft::list<int> mylist (myints,myints+8);
  ft::list<int> secondlist;

  secondlist.push_back(18);
  secondlist.push_back(6);
  mylist.merge(secondlist);
    // 15 36 7 17 20 39 4 1

            // 36 20

  std::cout << "mylist contains:";
  for (ft::list<int>::Iterator it=mylist.begin(); it!=mylist.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';

  return 0;
}