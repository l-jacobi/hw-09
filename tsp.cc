#include <iostream>
#include <random>
#include <algorithm>
#include <cassert>
#include <chrono>
#include <fstream>
#include "cities.hh"

Cities::permutation_t
random_permutation(unsigned len)
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

//permutation_t is an index of cities and coords: [i] would yield the coords of city 'i'

int main(int argc, char* argv[])
{
  auto infile = argv[1];   //intermediate var to name the file
  ifstream ifs(infile);   //open the infile
  Cities cities;
  ifs >> cities;
  int size = cities.city_count_();
  Cities::permutation_t ordering = cities.random_permutation(size);
  double distance = cities.total_path_distance(ordering);
  //read in the Cities from the infile
  //get the size and generate a random_permutation(size) called "ordering"
  //

}
