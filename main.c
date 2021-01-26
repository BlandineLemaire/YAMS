/*
L'affichage de notre jeu est en anglais
Tous nos compteurs commencent à 0 et pas à 1
*/
#define _CRT_SECURE_NO_WARNINGS
#define NB_DES 5
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "yams.h"

int main(void)
{
	// Definition du random pour que les valeurs ne soit pas les mêmes à chaque tirages :
	time_t  t;
	srand((unsigned)time(&t));
	// test
	int d;
	int *compteurTours = 0;
	int joueurA[NB_DES];
	int joueurB[NB_DES];
	int scoreA = 0;
	int scoreB = 0;
	for (int i = 0; i < NB_DES; ++i) {
		d = lancer_des();
		joueurA[i] = d;
	}
	tour(joueurB);
	//tri_tableau(joueurA);
	//afficher_des(joueurA);
	
	
	

	return 0;
}