#include <iostream>
#include <random>
#include <algorithm>
#include <cassert>
#include <chrono>
#include <fstream>
#include "cities.hh"

using namespace std;

Cities::permutation_t
random_permutation(unsigned len)
{
  assert(int(len) > 0);
  Cities::permutation_t out;
  int end = len-1;
  unsigned seed = chrono::system_clock::now().time_since_epoch().count();
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
  int iterations = 1000000;
  double min = 0;
  ifstream ifs(argv[1]);   //open the infile
  ofstream ofs("shortest.tsv");  //build an outfile for the final ordering
  Cities cities;
  ifs >> cities; //read in Cities object
  int size = cities.city_count_();
  int i = 1; while(i <= iterations){
    Cities::permutation_t ordering = cities.random_permutation(size);
    double distance = cities.total_path_distance(ordering);
    //this should initialize the minimum to the first distance outputted
    if((i==1) || distance < min){
      min = distance;
      cout<<i<<"\t"<<distance<<endl;
      cities = cities.reorder(ordering);
    }
    i++;
  }
  ofstream << cities;
  return 0;
}
