#include "cities.hh"
#include <cmath>
#include <cassert>

using coord_t = Cities::coord_t;

int Cities::city_count_(){
	return map_.size();
}

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

double Cities::total_path_distance(const permutation_t& ordering) const{
	double distance = 0;
	int ordering_size = ordering.size();
	assert(ordering.size() == map_.size());
	//make into a do while loop later if time
	for(int i = 1; i < ordering_size; i++){
		std::cout << "finding d between " << map_[ordering[i]].first << " " << map_[ordering[i]].second << " and " << map_[ordering[i-1]].first << " " << map_[ordering[i-1]].second << std::endl;
		distance += hypot(map_[ordering[i]].first - map_[ordering[i-1]].first, map_[ordering[i]].second - map_[ordering[i-1]].second);
		std::cout << distance << std::endl;
	}
	std::cout << "finding d between " << map_[ordering[ordering_size - 1]].first << " " << map_[ordering[ordering_size - 1]].second << " and " << map_[ordering[0]].first << " " << map_[ordering[0]].second << std::endl;
	distance +=  hypot(map_[ordering[ordering_size - 1]].first - map_[ordering[0]].first, map_[ordering[ordering_size - 1]].second - map_[ordering[0]].second);
	std::cout << distance << std::endl;
	return distance;
}
