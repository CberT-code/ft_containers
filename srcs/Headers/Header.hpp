/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Header.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbertola <cbertola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 17:16:44 by cbertola          #+#    #+#             */
/*   Updated: 2020/11/11 10:29:46 by cbertola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
#define HEADER_H

template <class T>
struct maillon
{
	maillon					*prev;
	maillon					*next;
	maillon					*right;
	maillon					*left;
	T						*ptr;		
};


# define RESET   		"\033[0m"
# define BLACK   		"\033[30m"				/* Black */
# define RED     		"\033[31m"				/* Red */
# define GREEN   		"\033[32m"				/* Green */
# define YELLOW  		"\033[33m"				/* Yellow */
# define BLUE    		"\033[34m"				/* Blue */
# define MAGENTA 		"\033[35m"				/* Magenta */
# define CYAN    		"\033[36m"				/* Cyan */
# define WHITE   		"\033[37m"				/* White */
# define BOLDBLACK   	"\033[1m\033[30m"      /* Bold Black */
# define BOLDRED     	"\033[1m\033[31m"      /* Bold Red */
# define BOLDGREEN   	"\033[1m\033[32m"      /* Bold Green */
# define BOLDYELLOW  	"\033[1m\033[33m"      /* Bold Yellow */
# define BOLDBLUE    	"\033[1m\033[34m"      /* Bold Blue */
# define BOLDMAGENTA 	"\033[1m\033[35m"      /* Bold Magenta */
# define BOLDCYAN    	"\033[1m\033[36m"      /* Bold Cyan */
# define BOLDWHITE   	"\033[1m\033[37m"      /* Bold White */

#include <algorithm>
#include <cstddef>
#include <deque>
#include <iostream>
#include <iomanip>
#include <limits>
#include <list>
#include <memory>
#include <sstream>
#include <string>
#include <cstring>
#include <stdio.h>
#include <tgmath.h>
#include <utility>
#include <variant>


#include "../Iterator/InputIterator.hpp"
#include "../Iterator/OutputIterator.hpp"
#include "../Iterator/ForwardIterator.hpp"
#include "../Iterator/BidirectionalIterator.hpp"
#include "../Iterator/RandomAccessIterator.hpp"
#include "../Iterator/ReverseInputIterator.hpp"
#include "../Iterator/ReverseForwardIterator.hpp"
#include "../Iterator/ReverseBidirectionalIterator.hpp"
#include "../Iterator/ReverseRandomAccessIterator.hpp"


#include "../Containers/List.hpp"
#include "../Containers/Vector.hpp"
#include "../Containers/Vector_bool.hpp"
#include "../Containers/Queue.hpp"
#include "../Containers/Stack.hpp"
#include "../Containers/Map.hpp"

int 			list_main(void);
int				vector_main(void);
int				queue_main(void);
int				stack_main(void);
int				map_main(void);
void 			compare_result(std::string res1, std::string res2);

#endif
