#pragma once

struct Classe {
	Classe(float inf, float sup);

	float const inf, sup;
	int qte = 0;
};

bool operator < (Classe const &lhs, Classe const &rhs);
