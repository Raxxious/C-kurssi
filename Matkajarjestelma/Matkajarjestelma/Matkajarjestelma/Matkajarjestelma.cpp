// Matkajarjestelma.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <memory>


using namespace std;

int main()
{
	int v;
	string rivi;
	float raha;
	//Matkakortti kortti;
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
		cout << "\t\t\t\tLopeta 6.\n";
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
				kortti->matkusta(SISÄINEN);
				cin.get();
			break;
			case 4: 
				gotoxy(25, 14);
				kortti->matkusta(SEUTU);
				cin.get();

			break;
			case 5:
				cout << "Omistaja: " << kortti->palautaNimi() << endl;
				cout << "Saldo: " << kortti->palautaSaldo();
				cin.get();
			case 6:       

				cin.get();
			break;
						
		}
	}
	while (v!=6);
	kortti.reset();
	return 0;
}



