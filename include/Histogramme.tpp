#include "Histogramme.h"

template <class Order>
template <class InputIte>
Histogramme<Order>::Histogramme(float min, float max, std::size_t nbClasses, InputIte dataBeg, InputIte dataEnd) {

	std::vector<Classe> classes;
	classes.reserve(nbClasses);
	std::generate_n(
		std::back_inserter(classes),
		nbClasses,
		[min, cl = (max - min) / nbClasses, i = std::size_t{0}]() mutable {
			Classe c(min + i * cl, min + (i + 1) * cl);
			++i;
			return c;
		}
	);

	std::for_each(dataBeg, dataEnd, [&classes](auto const &val) {
		auto classe = std::find_if(begin(classes), end(classes), [&val](Classe const &classe) {
			return classe.inf <= val && val < classe.sup;
		});

		if(classe == end(classes))
			return;

		++classe->qte;
	});

	std::copy(
		begin(classes),
		end(classes),
		std::inserter(_classes, begin(_classes))
	);
}

template <class Order>
template <class OtherOrder>
Histogramme<Order>::Histogramme(Histogramme<OtherOrder> const &other) {
	std::copy(
		begin(other._classes),
		end(other._classes),
		std::inserter(_classes, begin(_classes))
	);
}
