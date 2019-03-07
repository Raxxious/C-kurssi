

#include <stdio.h>
#include <string.h>

char *nurinpäin(char *pMerkkijono)						//Funktio joka laittaa merkkijonon nurinpäin
{
	char *pAlku = pMerkkijono;							//Ensimmäinen osoitin merkkijonon alkuun
	char *pLoppu = pAlku + strlen(pMerkkijono) - 1;		//Toinen osoitin merkkijonon loppuun

	while (pLoppu > pAlku)
	{
		char temp = *pAlku;								// Kopioidaan alku merkki tempiin
		*pAlku = *pLoppu;								// Kopioidaan loppu merkki alkuun
		*pLoppu = temp;									// Kopioidaan alku merkki tempistä loppuun

		pAlku++;										// Laitetaan alku osoitin eteenpäin
		pLoppu--;										// Laitetaan loppu osoitin taaksepäin
	}
	return pMerkkijono;
}

int main()
{
	char merkkijono[51];

	printf("Anna jokin merkkijono: ");
	gets_s(merkkijono);

	printf("Merkkijono on nurinpäin: %s", nurinpäin(merkkijono));

	return 0;
}