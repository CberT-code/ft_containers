/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbertola <cbertola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 11:49:47 by cbertola          #+#    #+#             */
/*   Updated: 2020/11/12 11:49:48 by cbertola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Headers/Header.hpp"

void 			compare_result(std::string res1, std::string res2)
{
	if (!res1.compare(res2)) 
		std::cout << GREEN << res1  << RESET << std::endl;
	else{
		std::cout << YELLOW << "Our : " << res1  << RESET << std::endl;
		std::cout << RED << "Real one : " << res2  << RESET << std::endl;
	}
}

int main(void) {
	
	std::system("clear");
	list_main();
	vector_main();
	queue_main();
	stack_main();
	map_main();
	return (1);
}
