
#include <stdio.h>


void yhdistä(char *p1, char *p2, char *p3)
{
	while (*p1!='\0')	
	{
		*p3 = *p1;		
		p1++;
		p3++;
	}
	while (*p2!='\0')
	{
		*p3 = *p2;		
		p2++;
		p3++;
	}
	*p3 = '\0';			
}
int main()
{
	char merkkijono1[51], merkkijono2[51], merkkijono3[51];
	
	printf("Anna ensimmäinen merkkijono: ");
	gets_s(merkkijono1);
	printf("Anna toinen merkkijono: ");
	gets_s(merkkijono2);

	yhdistä(merkkijono1, merkkijono2, merkkijono3);	

	printf("\nYhdistetty merkkijono on: %s\n", merkkijono3);

	return 0;
}