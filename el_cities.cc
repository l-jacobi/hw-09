#include "cities.hh"
#include <iostream>
#include <random>
#include <algorithm>
#include <chrono>

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

using namespace std;

Cities::permutation_t
Cities::random_permutation(unsigned len)
{
  assert(int(len) > 0);
  Cities::permutation_t out;
  int end = len-1;
  unsigned seed = chrono::system_clock::now().time_since_epoch().count();
  //makes sure each prog call returns a different vector, even within the same comp
  //is this necessary? seems cumbersome
  static default_random_engine generator (seed);
  uniform_int_distribution<unsigned int> distribution(0, end);
  while(out.size() != len){
    auto num = distribution(generator);
    if(count(out.begin(), out.end(), num) == 0){
      out.push_back(num);
    }
    else{ auto num = distribution(generator); }
  }
  return out;
}
