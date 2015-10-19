#include <iostream>
#include <Echantillon.h>

#include <algorithm>
#include <iterator>

int main() {
	using std::begin;
	using std::end;

	Echantillon ech;

	std::generate_n(std::back_inserter(ech), 10,[i = 0]() mutable { return ++i; });

	ech[4] = 42.0f;

	std::copy(begin(ech), end(ech), std::ostream_iterator<float>(std::cout, ", "));

	return 0;
}