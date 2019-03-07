
#include <stdio.h>
#include <string.h>

char *nurinpäin(char *pMerkkijono)							// Funktio joka syötetään merkkijonolle
{
	char *pAlku = pMerkkijono;								// Ensimmäinen osoitin merkkijonon alkuun
	char *pLoppu = pAlku + strlen(pMerkkijono) - 1;			// Toinen osoitin merkkijonon loppuun

	while (pLoppu > pAlku)									// Muuttaa merkkijonon nurinpäin
	{
		char temp = *pAlku;									// Kopioidaan alku merkki tempiin
		*pAlku = *pLoppu;									// Kopioidaan loppu merkki alkuun
		*pLoppu = temp;										// Kopioidaan alku merkki tempistä loppuun

		pAlku++;											// Laitetaan alku osoitin eteenpäin
		pLoppu--;											// Laitetaan loppu osoitin taaksepäin
	}
		
	while (*pMerkkijono != '\0')							// Muuttaa merkkijonossa olevat isot/pienet kirjaimet nurinpäin
	{														// Käyttää ASCII taulua, jossa pienet kirjaimet ovat 65-90 (A-Z) ja suuret 97-122 (a-z).
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
	nurinpäin(merkkijono);									// Kutsuu funktion merkkijonolle		
	printf("Merkkijono on nurinpäin: %s", merkkijono);

	return 0;
}
