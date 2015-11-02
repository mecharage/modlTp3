#pragma once

#include <cstdint>
#include <vector>

#include "Valeur.h"

struct Echantillon {
	using value_type = Valeur;
	using reference = value_type &;
	using const_reference = value_type const &;
	using size_type = std::size_t;
	using iterator = typename std::vector<value_type>::iterator;
	using const_iterator = typename std::vector<value_type>::const_iterator;

	iterator begin();
	iterator end();
	const_iterator begin() const;
	const_iterator end() const;

	const_iterator cbegin() const { return static_cast<Echantillon const &>(*this).begin(); }

	const_iterator cend() const { return static_cast<Echantillon const &>(*this).end(); }

	void push_back(const_reference val);

	reference operator [](std::size_t idx);
	const_reference operator [](std::size_t idx) const;

	reference min();
	const_reference min() const;

	reference max();
	const_reference max() const;

private:
	std::vector<value_type> _valeurs;
};
