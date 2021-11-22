#include <cassert>
#include "cities.hh"
#include <iostream>
#include <fstream>

void Cities::debug_print_city_(){
	for(coord_t coord : map_){
		std::cout << coord.first << ", " << coord.second << std::endl;
	}
}

int main(int argc, char* argv[]){
	
	if(argc != 2){std::cerr << "fuck you";}

	std::string input_file = argv[1];
	std::ifstream fis(input_file);
	if(!fis){assert(false);}

	Cities cities;
	fis >> cities;
	cities.debug_print_city_();

	return 0;
}