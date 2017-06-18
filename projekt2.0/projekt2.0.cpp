

#include "stdafx.h"
#include <stdio.h>
#include<string.h>
#include<locale.h>
#include <stdlib.h>
FILE *fd, *fp;

int main()
{
	setlocale(LC_ALL, "polish");
	system("chcp 1250");


	
	char k, l, pom;
	int i = 0, j=0;
	if (!(fd = fopen("tekst1.txt", "r")))
	{
		printf("B³¹d wczytwania tekstu 1\n");
		exit(5);
	}
	if (!(fp = fopen("tekst2.txt", "r")))
	{
		printf("B³¹d wczytwania tekstu 2\n");

		exit(4);

	}
	printf("\nTekst nr. 1: \n");       // Wypisywanie tekstu 1 
	printf("'");
	while (fscanf(fd, "%c", &k) != EOF)
	{
		printf("%c", k);
	}
	printf("'");
	printf("\n\nTekst nr. 2: \n"); // Wypisanie tekstu 2
	printf("'");
		while (fscanf(fp, "%c", &l) != EOF)
		{
			printf("%c", l);
		}
		printf("'");
		fclose(fp);
		fclose(fd);
	fp = fopen("tekst2.txt", "r");
	fd = fopen("tekst1.txt", "r");
	while (fscanf(fd, "%c", &k) != EOF)  // Szukanie znaku wspólnego 
	{
		
		while (fscanf(fp, "%c", &l) != EOF)
		{
			if (k == l)
			{
				pom = k;                   // Zapisanie znaku wspólnego do zmiennej pomocniczej 
				i++;
			}
		
		}
		j++;
		fclose(fp);
		//fp = fopen("tekst2.txt", "r");
		if (!(fp = fopen("tekst2.txt", "r")))
		{
			printf("B³¹d wczytwania tekstu 2\n");

			exit(4);

		}
	}
	
	
	if (i != 0)  // sprawdzanie czy istnieje znak wspólny 
	{
		if (pom == '\n')    // Sprawdzanie czy znak wspólny jest koncem lini 
		{
			printf("Ostanim znakiem który powtarza siê w Tekscie 1 oraz zawarty jest w tekscie 2 jest znak  koñca linii %d \n\n "); 
		}
		else
		{
			printf("\n\nOstanim znakiem który wystêpuje w Tescie 1 oraz zawarty jest w tekscie 2 jest znak ' %c '  \n\n", pom );  // wypisanie znaku wspólnego oraz jego pozycji 
		}
	}

	else
	{
		printf("\n\n W tekscie 1 nie wystêpuje ¿aden znak  z tekstu 2 \n");
	}
    return 0;
}

