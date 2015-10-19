#include "Echantillon.h"

#include <algorithm>

Echantillon::iterator Echantillon::begin() {
	using std::begin;
	return begin(_valeurs);
}

Echantillon::iterator Echantillon::end() {
	using std::end;
	return end(_valeurs);
}

Echantillon::const_iterator Echantillon::begin() const {
	using std::begin;
	return begin(_valeurs);
}

Echantillon::const_iterator Echantillon::end() const {
	using std::end;
	return end(_valeurs);
}

void Echantillon::push_back(Echantillon::value_type const &val) {
	_valeurs.push_back(val);
}

Echantillon::value_type &Echantillon::operator [](size_t idx) {
	return _valeurs[idx];
}

Echantillon::value_type const &Echantillon::operator [](size_t idx) const {
	return _valeurs[idx];
}

Echantillon::value_type &Echantillon::min() {
	return *std::min_element(begin(), end());
}

Echantillon::value_type const &Echantillon::min() const {
	return *std::min_element(begin(), end());
}

Echantillon::value_type &Echantillon::max() {
	return *std::max_element(begin(), end());
}

Echantillon::value_type const &Echantillon::max() const {
	return *std::max_element(begin(), end());
}
