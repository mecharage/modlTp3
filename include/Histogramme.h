#pragma once

#include <set>
#include <algorithm>

#include "Classe.h"

template <class Order = std::less<>>
struct Histogramme {
	Histogramme(float min, float max, std::size_t nbClasses);

	template <class InputIte>
	Histogramme(float min, float max, std::size_t nbClasses, InputIte dataBeg, InputIte dataEnd);

	template <class OtherOrder>
	Histogramme(Histogramme<OtherOrder> const &other);

//private:
	std::set<Classe, Order> _classes;
};

#include "Histogramme.tpp"
