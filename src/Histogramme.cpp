#include "Histogramme.h"

#include <algorithm>
#include <iterator>

Histogramme::Histogramme(float min, float max, std::size_t nbClasses) {
	//_classes.reserve(nbClasses);
	std::generate_n(
		std::inserter(_classes, end(_classes)),
		nbClasses,
		[min, cl = (max - min) / nbClasses, i = std::size_t{0}]() mutable {
			Classe c(min + i * cl, min + (i + 1) * cl);
			++i;
			return c;
		}
	);
}
