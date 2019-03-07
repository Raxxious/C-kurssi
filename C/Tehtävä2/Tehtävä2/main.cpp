
#include <stdio.h>
#include <string.h>

char *nurinp�in(char *pMerkkijono)							// Funktio joka sy�tet��n merkkijonolle
{
	char *pAlku = pMerkkijono;								// Ensimm�inen osoitin merkkijonon alkuun
	char *pLoppu = pAlku + strlen(pMerkkijono) - 1;			// Toinen osoitin merkkijonon loppuun

	while (pLoppu > pAlku)									// Muuttaa merkkijonon nurinp�in
	{
		char temp = *pAlku;									// Kopioidaan alku merkki tempiin
		*pAlku = *pLoppu;									// Kopioidaan loppu merkki alkuun
		*pLoppu = temp;										// Kopioidaan alku merkki tempist� loppuun

		pAlku++;											// Laitetaan alku osoitin eteenp�in
		pLoppu--;											// Laitetaan loppu osoitin taaksep�in
	}
		
	while (*pMerkkijono != '\0')							// Muuttaa merkkijonossa olevat isot/pienet kirjaimet nurinp�in
	{														// K�ytt�� ASCII taulua, jossa pienet kirjaimet ovat 65-90 (A-Z) ja suuret 97-122 (a-z).
		if (*pMerkkijono >= 65 && *pMerkkijono <= 90)		// Tarkistaa onko iso kirjain
			*pMerkkijono = *pMerkkijono + 32;				// Muuttaa sen pieneksi
		else
			if (*pMerkkijono >= 97 && *pMerkkijono <= 122)	// Tarkistaa onko pieni kirjain, jos on muuttaa sen suureksi
				*pMerkkijono = *pMerkkijono - 32;			// Muuttaa sen suureksi
		pMerkkijono++;
	}

	return pMerkkijono;
}

int main()
{
	char merkkijono[51];

	printf("Anna jokin merkkijono: ");
	gets_s(merkkijono);										
	nurinp�in(merkkijono);									// Kutsuu funktion merkkijonolle		
	printf("Merkkijono on nurinp�in: %s", merkkijono);

	return 0;
}
