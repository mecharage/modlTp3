#include "Valeur.h"

#include <iostream>

bool operator < (Valeur const &lhs, Valeur const &rhs) {
	return lhs.note < rhs.note;
}

bool operator < (Valeur const &lhs, float rhs) {
	return lhs.note < rhs;
}

bool operator <= (float lhs, Valeur const &rhs) {
	return lhs <= rhs.note;
}

std::ostream &operator << (std::ostream &str, Valeur const &val) {
	return str << val.nom << " : " << val.note;
}
