#include "stdafx.h"

using namespace std;

Matkakortti::Matkakortti()
{
}


Matkakortti::~Matkakortti()
{
	/*
	delete omistajanNimi;		// T4
	delete saldo;				// T4
	*/

}

void Matkakortti::lataaSaldo(float raha)
{
	/*
	*saldo += raha;							// T4 
	*/

	saldo.reset(new float(*saldo + raha));
}

void Matkakortti::alusta(string rivi, float raha)
{
	/*
	this->omistajanNimi = new string(rivi);	// T4
	this->saldo = new float(raha);			// T4
	*/

	omistajanNimi = std::unique_ptr<string>{ new string(rivi) };
	saldo = std::unique_ptr<float>{ new float(raha) };
}


bool Matkakortti::matkusta(enum Matkatyyppi tyyppi)
{
	if (tyyppi == SISÄINEN)
	{
		if (*saldo >= SISÄINENHINTA)
		{
			//	*saldo = *saldo - SISÄINENHINTA;	// T4
			saldo.reset(new float(*saldo - SISÄINENHINTA));
			cout << "Hyvää matkaa! Saldosi on nyt: " << palautaSaldo();
			return true;
		}
		else
		{
			cout << "Sinulla ei ole tarpeeksi saldoa matkaan, saldosi on: " << palautaSaldo();
			return false;
		}
	}
	if (tyyppi == SEUTU)
	{
		if (*saldo >= SEUTUHINTA)
		{
			//	*saldo = *saldo - SEUTUHINTA;	// T4
			saldo.reset(new float(*saldo - SEUTUHINTA));
			cout << "Hyvää matkaa! Saldosi on nyt: " << palautaSaldo();
			return true;
		}
		else
		{
			cout << "Sinulla ei ole tarpeeksi saldoa matkaan, saldosi on: " << palautaSaldo();
			return false;
		}
	}

}

string Matkakortti::palautaNimi()
{
	return *omistajanNimi;
}

float Matkakortti::palautaSaldo()
{
	return *saldo;
}