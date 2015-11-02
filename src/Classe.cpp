#include "Classe.h"

Classe::Classe(float inf, float sup)
: inf(inf), sup(sup) {}

bool operator < (Classe const &lhs, Classe const &rhs) {
	return lhs.inf < rhs.inf;
}
