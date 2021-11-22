#include <cassert>
#include "cities.hh"
#include <iostream>
#include <fstream>
using coord_t = Cities::coord_t;

void debug_print_city(Cities cities){
	for(coord_t coord : cities.map_){
		std::cout << coord.first << ", " << coord.second << std::endl;
	}
}

int main(int argc, char* argv[]){
	
	if(argc != 2){std::cerr << "fuck you\n";}

	std::string input_file = argv[1];
	std::ifstream fis(input_file);
	if(!fis){assert(false);}

	Cities cities;
	fis >> cities;
	debug_print_city(cities);

	return 0;
}