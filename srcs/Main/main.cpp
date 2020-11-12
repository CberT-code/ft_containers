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
	list_main();
	
	// std::system("clear");
	vector_main();
	// std::system("clear");
	queue_main();
	// std::system("clear");
	stack_main();
	// std::system("clear");
	map_main();
	return (1);
}
