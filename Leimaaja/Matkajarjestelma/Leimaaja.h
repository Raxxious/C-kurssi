#pragma once
#include "stdafx.h"


class Leimaaja
{
public:
	Leimaaja();
	int linja;
	std::deque<float> saldo;
	std::deque<string> omistajanNimi;
	std::deque<string> leimaajaAika;
	void leimaa(Matkakortti& kortti, Matkatyyppi tyyppi);
	void tulostaLeimaukset();
	~Leimaaja();
	Leimaaja &operator<<(Matkakortti& kortti);
};



