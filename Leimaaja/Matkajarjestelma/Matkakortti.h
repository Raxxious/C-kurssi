#pragma once
#include "stdafx.h"
#define SISÄINENHINTA 3.0 // vaihtoehto 2: const float HELSINKIHINTA = 3.0; // C++:n nimetty vakio
#define SEUTUHINTA 4.8

using namespace std;

enum Matkatyyppi {SISÄINEN, SEUTU};

class Matkakortti
{
private:
	/*
	string *omistajanNimi;	// T4
	float *saldo;			// T4
	*/

	std::unique_ptr<string> omistajanNimi;
	std::unique_ptr<float> saldo;

public:
	Matkakortti();
	void lataaSaldo(float raha);
	void alusta(string rivi, float raha);
	bool matkusta(enum Matkatyyppi tyyppi);
	//void tulostaTiedot(); // ongelma: matkakortti ei suoraan saisi tulostaa kl:ään
	string palautaNimi();
	float palautaSaldo();
	~Matkakortti();
};

