# hw-09
El &amp; Rebecca

El Jacobi: Problems 1 - 4
=========================

## operator>>

## operator<<

## total_path_distance

## reorder



Rebecca Guglin: random_permutation, tsp.cc, visualization

random_permutation:

*** Testing this function revealed that, because the uniform_int_distribution is pseudo-random, it only really permutes its range once per compilation. To ensure that it would return different values every time it's called, even within the same compilation, I borrowed some code from the second answer to this question: https://stackoverflow.com/questions/32575167/generate-random-numbers-with-uniform-distribution-getting-same-number-in-loop 

random_permutation first asserts that len is a positive number, otherwise the while loop will just run forever. Declares an vector of unsigned ints (a permutation_t). As long as that vector's size is less than len, the function produces a random number within the range of (0, len-1]. Then it uses std::count to check if that number is already in the vector. If it is, it generates a new number. Otherwise the number is pushed to the back of the vector. When the vector is full the function returns it. 

tsp.cc:

Fixes the number of iterations at 1 million, as suggested in the assignment description, and makes a double object to store the current minimum distance. Builds streams from the input file and into shortest.tsv, reads in the Cities from the input file, and finds the size of the Cities object using city_count_().
Then it enters a while loop. For each iteration, it generates a new permutation of the range from 0 to the size of the Cities, i.e. a potential reordering of all the cities. The while loop checks for two conditions:
If this is the very first iteration, it initializes Min to the distance calculated, so that every other iteration has something to compare its distance to.
Otherwise, if the total_path_distance of this iteration is less than the minimum, then Min is updated, the current iteration and Min are printed to the console, and the Cities object is reordered to match the current fastest permutation. When the the loop is done, the final reordering is fed into shortest.tsv. 
