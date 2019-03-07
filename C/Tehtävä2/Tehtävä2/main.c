

#include <stdio.h>
#include <string.h>

char *nurinp�in(char *pMerkkijono)						//Funktio joka laittaa merkkijonon nurinp�in
{
	char *pAlku = pMerkkijono;							//Ensimm�inen osoitin merkkijonon alkuun
	char *pLoppu = pAlku + strlen(pMerkkijono) - 1;		//Toinen osoitin merkkijonon loppuun

	while (pLoppu > pAlku)
	{
		char temp = *pAlku;								// Kopioidaan alku merkki tempiin
		*pAlku = *pLoppu;								// Kopioidaan loppu merkki alkuun
		*pLoppu = temp;									// Kopioidaan alku merkki tempist� loppuun

		pAlku++;										// Laitetaan alku osoitin eteenp�in
		pLoppu--;										// Laitetaan loppu osoitin taaksep�in
	}
	return pMerkkijono;
}

int main()
{
	char merkkijono[51];

	printf("Anna jokin merkkijono: ");
	gets_s(merkkijono);

	printf("Merkkijono on nurinp�in: %s", nurinp�in(merkkijono));

	return 0;
}