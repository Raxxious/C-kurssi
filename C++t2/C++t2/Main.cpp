#include <stdio.h>
#include <tchar.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

#include "stdafx.h"
#include "IOHelper.h"


using namespace std;

#define MAX 2

typedef struct kokoelma {
	char nimi[41];
	char tekija[31];
	int jvuosi;
} aanite;

aanite levy, *levyOsoitin, levyt[MAX];




int kysyTiedot()
{
	/* pyyt„„ „„nitteiden tiedot k„ytt„j„lt„. palauttaa arvonaan sy”tettyjen lukum„„r„n*/
	//char rivi[81];
	int i;
	//levyOsoitin=&levy; // asetetaan osoitin osoitamaan levy-muuttujaa
	cout << "kirjoita „„nilevykokoelmasi tiedot. Lopetus: \"teoksen nimi\"-kent„ss„ = *" << endl;
	i = 0;
	do
	{
		//cin.ignore();								// tapa2: ongelmana oli whilin kuluttama enterin painallus, pitää olla tää mukana
		cout << "\nteoksen nimi? (40 merkki„) ";
		levyOsoitin = &levyt[i];
		cin.getline(levyOsoitin->nimi,41);
		
		if (levyOsoitin->nimi[0] != '*')
		{
			cout << endl << "tekij„? (30 merkki„) ";
			cin.getline(levyOsoitin->tekija, 31);

			cout << endl << "julkaisuvuosi? ";
			//cin >> levyOsoitin->jvuosi;			// tapa2
			levyOsoitin->jvuosi = getIntFromStream();
			/*while (!cin) {						// tapa2
				// user didn't input a number
				cin.clear(); // reset failbit
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');//skip bad input
				cout << endl << "antamasi tieto ei ollut numeerinen. Kirjoita uusi";
				cin >> levyOsoitin->jvuosi;
			}*/
			i++;
		}
	} while ((levyOsoitin->nimi[0] != '*') && (i < MAX));
	return(i);
}

void tulostaTiedot(int lkm)
/* tulostetaan levyt */
{
	int i = 0;
	system("cls");
	if (lkm == 0)
	{
		cout << "Et sy”tt„nyt yht„k„„n levy„" << endl;
	}
	else
		for (i = 0; i < lkm; i++)
		{
			cout << endl << levyt[i].nimi << " " << levyt[i].tekija << " " << levyt[i].jvuosi;
		}
	cout << endl; // rivinvaihto
	_getch();
}

void main()
{
	tulostaTiedot(kysyTiedot());
}