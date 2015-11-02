#pragma once

#include <string>
#include <iosfwd>

struct Valeur {
	std::string nom;
	float note;
};

bool operator < (Valeur const &lhs, Valeur const &rhs);
bool operator < (Valeur const &lhs, float rhs);
bool operator <= (float lhs, Valeur const &rhs);


std::ostream &operator << (std::ostream &str, Valeur const &val);
