# hw-09
El &amp; Rebecca

El Jacobi: Problems 1 - 4, cities.hh, Makefile
=========================

## General additions to cities.hh

`map_t` is used as a type which is a vector of coordinate pairs. This is for consistency across multiple usages of it in cities.hh and cities.cc

`cities.hh` was given one private data member of the `map_t` described above, `map_`. This is a vector of the coordinates of all cities.

`Cities` was also given a constructor function and is implemented in cities.cc. `Cities::Cities` defines `map_` as empty by default, or a `map_t` if one is passed to it. This was necessary for `Cities::reorder()`.

Lastly, I added one public function, `Cities::city_count_()` which returns the size of `Cities::map_`. This was necessary for the work Rebecca was doing so that we could still keep `map_` private, but she could still know how many elements the random permutation of orders would have.

## operator>>

These two operators were suprisingly easy. They essentially already handled everything for us, and we just needed to read two ints at a time and input them into a `coord_t` to be pushed into the map. `x` and `y` being defined as `int`s makes them automatically read the next integer, which basically did all the work for us.

## operator<<

This was even easier, and just loops for all coordinates and outputs them all to the ostream with <<.

## total_path_distance

The function is pretty simple. It takes an order of coordinates, and then goes through them all, starting at the second pair of coordinates. It uses `std::hypot` to find the distance between the current pair given from the order of coordiantes and the previous pair. After it has summed the distance going from the first to the last city, it finally adds the distance from the last city returning to the first.

## reorder

While I'd guess that we were supposed to use `std::sort` and create a fancy custom compare function that determines the order of the items in the reordering it's given, given by how we talked about using `std::sort` with custom comparation functions in class, I figued that even the most optimized sorting algorith wouldn't be faster than just O(n), which is what we get going through the reordering and making a new vector using the reordering elements as indices to access elements of the current map. This scales at O(n) since we just do one assignment per item. I don't think any sorting algorithm comes even close, unless all items are already the the correct place.

## the test_cities file

This isn't being graded, I just want to know why `assert(five_cities.total_path_distance({ 0, 1, 2, 3, 4 })` = 48.8699 but `assert(five_cities.total_path_distance({ 0, 1, 2, 3, 4 }) == 48.8699);` crashes

## the Makefile

You compile the final program with `make what` and run it with `./what`. I probably could've thought of something better. I can't guarentee anything other than `make what` and `make test_cities` will actually compile. Anything else in there is a wild experiment with something I do not fully understand.

Rebecca Guglin: random_permutation, tsp.cc, visualization
=========================================================

random_permutation:

*** Testing this function revealed that, because the uniform_int_distribution is pseudo-random, it only really permutes its range once per compilation. To ensure that it would return different values every time it's called, even within the same compilation, I borrowed some code from the second answer to this question: https://stackoverflow.com/questions/32575167/generate-random-numbers-with-uniform-distribution-getting-same-number-in-loop 

random_permutation first asserts that len is a positive number, otherwise the while loop will just run forever. Declares an vector of unsigned ints (a permutation_t). As long as that vector's size is less than len, the function produces a random number within the range of (0, len-1]. Then it uses std::count to check if that number is already in the vector. If it is, it generates a new number. Otherwise the number is pushed to the back of the vector. When the vector is full the function returns it. 

tsp.cc:

Fixes the number of iterations at 1 million, as suggested in the assignment description, and makes a double object to store the current minimum distance. Builds streams from the input file and into shortest.tsv, reads in the Cities from the input file, and finds the size of the Cities object using city_count_().
Then it enters a while loop. For each iteration, it generates a new permutation of the range from 0 to the size of the Cities, i.e. a potential reordering of all the cities. The while loop checks for two conditions:
If this is the very first iteration, it initializes Min to the distance calculated, so that every other iteration has something to compare its distance to.
Otherwise, if the total_path_distance of this iteration is less than the minimum, then Min is updated, the current iteration and Min are printed to the console, and the Cities object is reordered to match the current fastest permutation. When the the loop is done, the final reordering is fed into shortest.tsv. 
