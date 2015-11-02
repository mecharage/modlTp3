#include <iostream>
#include <algorithm>
#include <iterator>
#include <tuple>

#include "Echantillon.h"
#include "Histogramme.h"

int main() {
	using std::begin;
	using std::end;

	Echantillon ech;

	std::generate_n(std::back_inserter(ech), 10,[i = 0]() mutable {
		Valeur v{{5, char('a' + i)}, float(i)};
		++i;
		return v;
	});

	ech[4].note = 42.0f;

	std::copy(begin(ech), end(ech), std::ostream_iterator<Valeur>(std::cout, ", "));

	struct TriDecParQte {
		bool operator () (Classe const &lhs, Classe const &rhs) const {
			return std::tie(rhs.qte, lhs.inf) < std::tie(lhs.qte, rhs.inf);
		}
	};

	Histogramme<TriDecParQte> hist{0.0f, 10.0f, 10u, begin(ech), end(ech)};

	std::cout << '\n';

	for(Classe const &c : hist._classes)
		std::cout << "[" << c.inf << ";" << c.sup << "] " << c.qte << "\n";

	std::cout << "------------------------------\n";

	Histogramme<> hist2{hist};

	for(Classe const &c : hist2._classes)
		std::cout << "[" << c.inf << ";" << c.sup << "] " << c.qte << "\n";

	return 0;
}
