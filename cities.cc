#include <iostream>
#include <random>
#include <algorithm>
#include <cassert>
#include <chrono>
#include "cities.hh"

using namespace std;

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

void test(int len)
{
  auto vec = random_permutation(len);
  for(auto i=0; i < vec.size()-1; ++i){
    cout<<vec[i]<<",  ";
  }
  cout<<vec[vec.size()-1]<<endl;
}

int main()
{
  test(1);
  test(5);
  test(10);
  test(20);
  return 0;
}
