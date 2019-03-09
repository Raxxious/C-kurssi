// Matkajarjestelma.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


using namespace std;

std::ostream& operator<<(std::ostream& stream, const Leimaaja& leimaaja)
{
	stream << leimaaja.omistajanNimi.size() << " viimeistä leimausta linjalle " << std::to_string(leimaaja.linja) << " ovat:" << endl << endl;
	for (int i = 0; i < leimaaja.omistajanNimi.size(); i++) 
	{
		stream << "Omistaja: " << leimaaja.omistajanNimi[i] << ", Saldo: " << leimaaja.saldo[i] <<", Aika: " << leimaaja.leimaajaAika[i] << endl;
	}
	stream << endl;
	return stream;
}

std::ostream& operator<<(std::ostream& stream, Matkakortti& kortti)
{
	stream << "Omistaja: " << kortti.palautaNimi() << endl << "Saldo: " << std::to_string(kortti.palautaSaldo()) << endl;
	return stream;
}

int main()
{
	int v;
	string rivi;
	float raha;
	//Matkakortti kortti;
	Leimaaja leimaaja = Leimaaja();
	std::unique_ptr<Matkakortti> kortti(new Matkakortti());
	do
	{
		system("cls");
		cout <<"-------------------Matkakortin testausvalikko--------------------";
		cout <<"\n\n\n\n";
		cout << "\t\t\t\tAlusta matkakortti 1.\n";
		cout << "\t\t\t\tLataa matkakortti 2.\n";
		cout << "\t\t\t\tMatkusta sisäisellä 3.\n";
		cout << "\t\t\t\tMatkusta seudulla 4.\n";
		cout << "\t\t\t\tTulosta kortin tiedot 5.\n";
		cout << "\t\t\t\tTulosta kortin leimaukset 6.\n";
		cout << "\t\t\t\tLopeta 7.\n";
		gotoxy(43,12);
		v=getIntFromStream();
		switch (v)
		{
			case 1:
				gotoxy(25, 14);
				cout << "Anna kortin omistajan nimi: ";
				getline(cin, rivi);
				gotoxy(25, 14);
				cout << " Anna korttiin laitettava saldo: ";
				raha = getFloatFromStream();
				kortti->alusta(rivi, raha);
			break;
			case 2:
				gotoxy(30, 14);
				cout << "Anna lisättävä saldo: ";
				raha = getFloatFromStream();
				kortti->lataaSaldo(raha);
				cin.get();
				
			break;
			case 3:
				gotoxy(25, 14);
				//kortti->matkusta(SISÄINEN);
				//leimaaja.leimaa(*kortti, SISÄINEN);		// T7
				leimaaja << *kortti;
				cin.get();
			break;
			case 4: 
				gotoxy(25, 14);
				//leimaaja.leimaa(*kortti, SEUTU);
				kortti->matkusta(SEUTU);
				cin.get();

			break;
			case 5:
				//cout << "Omistaja: " << kortti->palautaNimi() << endl;
				//cout << "Saldo: " << kortti->palautaSaldo();
				cout << *kortti;
				cin.get();
			case 6:
				//leimaaja.tulostaLeimaukset();
				cout << leimaaja;
				cin.get();
				break;
			case 7:       
				cin.get();
			break;
						
		}
	}
	while (v!=6);
	kortti.reset();
	return 0;
}



