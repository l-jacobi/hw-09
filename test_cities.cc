#include <cassert>
#include "cities.hh"
#include <iostream>
#include <fstream>
#include <cmath>
using coord_t = Cities::coord_t;

/*
void debug_print_city(Cities cities){
	for(coord_t coord : cities.map_){
		std::cout << coord.first << ", " << coord.second << std::endl;
	}
}
*/

void test_tpd(){
	std::ifstream five("five.tsv");
	Cities five_cities;
	five >> five_cities;

	double sum = 0;
	sum += std::hypot(15 - 7, 7 - 7);
//	std::cout << sum << std::endl;
	sum += std::hypot(7 - 15, 7 - 12);
//	std::cout << sum << std::endl;
	sum += std::hypot(15 - 10, 12 - 5);
//	std::cout << sum << std::endl;
	sum += std::hypot(10 - 2, 5 - 20);
//	std::cout << sum << std::endl;
	sum += std::hypot(2 - 15, 20 - 7);
//	std::cout << sum << std::endl;

	// wow i sure wish there was some form of technology that made doing repetitive computations quicker and easier

	Cities::permutation_t order = {3, 4, 2, 0, 1};
	assert(five_cities.total_path_distance(order) == sum);
	//assert(five_cities.total_path_distance({ 0, 1, 2, 3, 4 }) == 48.8699);	//total_path_distance does evaluate this to be 48.8699 but doesn't agree that that is equal for some reason
}

void test_reorder(){
	std::ifstream five("five.tsv");
	Cities five_cities;
	five >> five_cities;
	Cities reordered_cities = five_cities.reorder({3, 2, 4, 1, 0});
	double a = five_cities.total_path_distance({3, 2, 4, 1, 0});
	double b = reordered_cities.total_path_distance({0, 1, 2, 3, 4});
	assert(a == b);
}

int main(/*int argc, char* argv[]*/){
/*	
	if(argc != 2){std::cerr << "not enough\n";}

	std::string input_file = argv[1];
	std::ifstream fis(input_file);
	if(!fis){assert(false);}

	Cities cities;
	fis >> cities;
//	debug_print_city(cities);
//	std::cout << cities;
*/
	test_tpd();
	test_reorder();

	return 0;
}