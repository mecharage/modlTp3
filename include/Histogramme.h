#pragma once

#include <vector>
#include <algorithm>

#include "Classe.h"

struct Histogramme {
	Histogramme(float min, float max, std::size_t nbClasses);

	template <class InputIte>
	Histogramme(float min, float max, std::size_t nbClasses, InputIte dataBeg, InputIte dataEnd);

//private:
	std::vector<Classe> _classes;
};

template <class InputIte>
Histogramme::Histogramme(float min, float max, std::size_t nbClasses, InputIte dataBeg, InputIte dataEnd)
	: Histogramme(min, max, nbClasses) {

	std::for_each(dataBeg, dataEnd, [this](auto const &val) {
		auto classe = std::find_if(begin(_classes), end(_classes), [&val](Classe const &classe) {
			return classe.inf <= val && val < classe.sup;
		});

		if(classe == end(_classes))
			return;

		++classe->qte;
	});
}
