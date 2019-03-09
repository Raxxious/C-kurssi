#include "Leimaaja.h"


Leimaaja::Leimaaja()										// Leimaaja kysyy muodostuessaan linjan numeron, jonka matkoja leimaa.		
{
	cout << "Anna linjan numero: ";
	linja = getIntFromStream();
	omistajanNimi = std::deque<string>();
}

void Leimaaja::leimaa(Matkakortti& kortti, Matkatyyppi matkatyyppi) {
	if (kortti.matkusta(matkatyyppi))
	{
		omistajanNimi.push_front(kortti.palautaNimi());		// push_front lis‰‰ elementin luettelon etupuolelle
		saldo.push_front(kortti.palautaSaldo());

		auto t = std::time(nullptr);					
		auto tm = *std::localtime(&t);
		std::ostringstream oss;
		oss << std::put_time(&tm, "%d.%m.%Y %H:%M:%S");
		auto str = oss.str();
		leimaajaAika.push_front(str);						// Ottaa leimaus ajan luetteloon

		if (omistajanNimi.size() > 5)
		{
			omistajanNimi.pop_back();						// pop_back poistaa viimeisen elementin luettelosta
		}
		if (saldo.size() > 5)
		{
			saldo.pop_back();
		}
		if (leimaajaAika.size() > 5)
		{
			leimaajaAika.pop_back();
		}
	}
}

Leimaaja &Leimaaja::operator<<(Matkakortti& kortti)			// T7
{
	leimaa(kortti, SISƒINEN);
	return *this;
}


void Leimaaja::tulostaLeimaukset() {
	cout << omistajanNimi.size() << " viimeist‰ leimausta linjalle " << std::to_string(linja) << "ovat;" << endl << endl;
	for (int i = 0; i < omistajanNimi.size(); i++)
	{
		cout << "Omistaja: " << omistajanNimi[i] << ", Saldo: " << saldo[i] << ", Aika: " << leimaajaAika[i] << endl;
	}
	cout << endl;
}


Leimaaja::~Leimaaja()
{
}






