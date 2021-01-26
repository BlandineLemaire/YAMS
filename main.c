/*
L'affichage de notre jeu est en anglais
Tous nos compteurs commencent � 0 et pas � 1
*/
#define _CRT_SECURE_NO_WARNINGS
#define NB_DES 5
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "yams.h"

int main(void)
{
    // Definition du random pour que les valeurs ne soit pas les m�mes � chaque tirages :
    time_t  t;
    srand((unsigned)time(&t));
    // test
    int d;
    int* compteurTours = 0;
    // Initialisation des tableaux contenant les dès des joueurs
    int scoreTourJoueurA = 0;
    int scoreTourJoueurB = 0;
    // Initialisation des scores des joueurs à 0
    int scoreA = 0;
    int scoreB = 0;
    // Boucle permetant de faire les 10 manches de la partie
    for (int i = 0; i < 10; i++) {
        // Tour du joueur 1
        printf("----------------------------------------\n");
        printf("Tour du joueur 1\n");
        printf("----------------------------------------\n");
        // Initialisation de ses valeurs et demande s'il souhaite en changer
        scoreTourJoueurA = lancer_joueur();
        // Check de toutes les options de score
        scoreA = scoreA + scoreTourJoueurA;
        // Tour du joueur 2
        printf("----------------------------------------\n");
        printf("Tour du joueur 2\n");
        printf("----------------------------------------\n");
        // Initialisation de ses valeurs et demande s'il souhaite en changer
        scoreTourJoueurB = lancer_joueur();
        // Check de toutes les options de score
        scoreB = scoreB + scoreTourJoueurB;
        // Check du milieu de partie pour ajouter des points bonus
        if (i == 5) {
            checkMilieuPartie(&scoreA, &scoreB);
        }
    }
    // Affichage du gagnant
    if (scoreA > scoreB) {
        printf("Le joueur A a gagner\n");
    }
    else {
        printf("Le joueur B a gagner\n");
    }
    return 0;
}