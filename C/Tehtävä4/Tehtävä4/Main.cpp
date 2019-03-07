
#include <stdio.h>

void nollaaTaulukko(int l[])		// Funktio jolla nollataan taulukko
{
	int i;
	for (i = 0; i < 10; i++)
	{
		*(l+i) = 0; 
	}
}

void main()
{
	int kokonaisluku[10], *ptr, i;
	ptr = kokonaisluku;

	nollaaTaulukko(kokonaisluku);	// Kutsutaan taulukon nollaus

	for (i = 0;i < 10;i += 2)		// Laitetaan kokonaisluvut taulukon joka toiselle arvolle
	{
		printf("Anna kokonaisluku: ");
		scanf("%d", ptr + i); 
	}

	printf("\n10 \t Hex \t\t Osoite hex \t Osoite 10 \n");

	for (i = 0;i < 10;i++)			
	{
		printf("%d \t %p \t %d \t %p \t \n", *(ptr + i), *(ptr + i), (ptr + i), (ptr + i));
	}

}
