// MatkakorttiC.cpp : Defines the entry point for the console application.
//

#include <stdio.h>
#include <string.h>

struct Matkakortti
{
	char omistajanNimi[21];
	float saldo;
};

struct Matkakortti kortti; // kortti = tietuemuuttuja

void tulostaValikko(); // prototyyppi vaaditaan, jos kutsu on ennen m‰‰rittely‰
void alustaKortti();
void tulostaKortti();
void lataaKortti();
void helsinkiKortti();
void seutuKortti();

void alustaKortti()
{
	kortti.omistajanNimi[0] = '\0';
	kortti.saldo = 0;
}

void tulostaKortti()
{
	printf("\n\t\t\t\tKortin omistaja: %s", kortti.omistajanNimi);
	printf("\n\t\t\t\tSaldo: %F", kortti.saldo);
}

void lataaKortti()
{
	float arvo = 0;
	printf("\n\t\t\tPaljonko haluat lataa kortille massia: ");
	scanf("%F", &arvo);
	kortti.saldo = kortti.saldo + arvo;

}

void helsinkiKortti()
{
	if (kortti.saldo >= 2.5)
	{
		kortti.saldo = kortti.saldo - 2.5;
		printf("Hyv‰‰ matkaa!");
		printf("\n\t\t\t\tKortin saldo on nyt: %F", kortti.saldo);
	}
	else
	{
		printf("Saldosi on %F, se ei riit‰ matkaan", kortti.saldo);
	}
	
}

void seutuKortti()
{
	if (kortti.saldo >= 3.8)
	{
		kortti.saldo = kortti.saldo - 3.8;
		printf("Hyv‰‰ matkaa!");
		printf("\n\t\t\t\tKortin saldo on nyt: %F", kortti.saldo);
	}
	else
	{
		printf("Saldosi on %F, se ei riit‰ matkaan", kortti.saldo);
	}
}

int main()
{
	tulostaValikko();
	return 0;
}

void tulostaValikko()
{
	char v;
	enum boolean ok;
	alustaKortti();

	do
	{
		system("cls");
		printf("---------------------------------Valikko------------------------------");
		printf("\n\n\n\n");
		printf("\t\t\tLuo matkakortti\t\t\t1");
		printf("\n\t\t\tLataa saldoa\t\t\t2");
		printf("\n\t\t\tMatkusta Helsingiss‰\t\t3");
		printf("\n\t\t\tMatkusta seutuliikenteess‰\t4");
		printf("\n\t\t\tTulosta kortin tiedot\t\t5");
		printf("\n\t\t\tLopetus\t\t\t\t6");
		printf("\n\t\t\tValitse:");
		v = _getch();
		switch (v) {
		case '1':
			break;
		case '2':
			lataaKortti();
			_getch;
			break;
		case '3':
			helsinkiKortti();
			_getch();
			break;
		case '4':
			seutuKortti();
			_getch();
			break;
		case '5':
			tulostaKortti();
			_getch(); // Pys‰ytet‰‰n kontrolli...
			break;
		case '6':
			break;
		}
	} while (v != '6');


}
