#include "cities.hh"
#include <iostream>

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