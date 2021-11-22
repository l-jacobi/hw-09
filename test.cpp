#include <iostream>
#include <cassert>
#include <fstream>
#include <vector>


void do_things(std::istream& is, std::vector<int>& v){
	while(!is.eof()){
		int x;
		is >> x;
		v.push_back(x);
	}
}

void print_vector(std::ostream& os, std::vector<int>& v){
	for(int e : v){
		os << e << std::endl;
	}
}

int main(int argc, char* argv[]){
	
	std::string input_file = argv[1];
	std::ifstream fis(input_file);
	if(!fis){assert(false);}

	std::vector<int> v;

	do_things(fis, v);
	print_vector(std::cout, v);

	return 0;
}