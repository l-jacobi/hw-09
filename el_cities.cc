#include "cities.hh"
#include <iostream>
using coord_t = Cities::coord_t;

std::istream& operator>> (std::istream& is, Cities& cities){
	//getine, go until it reaches space? then until it ends?
	int x, y;
	while(!is.eof()){
		is >> x >> y;
		cities.map_.push_back(Cities::coord_t(x, y));
	}
	cities.map_.pop_back();	//remove weird last element idk what to do about
	return is;
}

std::ostream& operator<< (std::ostream& os, Cities& cities){
	for(coord_t coord : cities.map_){
		os << coord.first << " " << coord.second << std::endl;
	}
	return os;
}