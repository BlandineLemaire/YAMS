/*
L'affichage de notre jeu est en anglais
Tous nos compteurs commencent à 0 et pas à 1
*/
#define _CRT_SECURE_NO_WARNINGS
#define NB_DES 5
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "yams.h"


// Déclaration d'un structure de donnée joueur avec un pseudo et un score
typedef struct joueur joueur;

struct joueur
{
    char* pseudo;
    int scorePartie;
};

int main(void)
{
    joueur joueurA;
    joueur joueurB;
    
    // Definition du random pour que les valeurs ne soit pas les m�mes � chaque tirages :
    time_t  t;
    srand((int)time(&t));
    // test
    printf(" _________________________________________________________________________________________________________________\n");
    printf("|                                                 YAHTZEE !                                                       |\n");
    printf("|                                          By Blandine & Enotian                                                  |\n");
    printf("|_________________________________________________________________________________________________________________|\n");
    
    int* compteurTours = 0;
    // Invitation de renseignement des information des joueurs
    // Joueur A
    printf("Saisir le pseudo du joueur A\n");
    printf("Pseudo : ");
    *&joueurA.pseudo = (char*)malloc(sizeof(char) * 20);
    scanf("%s", *&joueurA.pseudo);
    // Joueur B
    printf("Saisir le pseudo du joueur B\n");
    printf("Pseudo : ");
    *&joueurB.pseudo = (char*)malloc(sizeof(char) * 20);
    scanf("%s", *&joueurB.pseudo);


    // Initialisation des tableaux contenant les dès des joueurs
    int scoreTourJoueurA = 0;
    int scoreTourJoueurB = 0;
    // Initialisation des scores des joueurs à 0
    joueurA.scorePartie = 0;
    joueurB.scorePartie = 0;
    // Boucle permetant de faire les 10 manches de la partie
    for (int i = 1; i < 11; i++) {
        printf("\n----------------------------------------\n");
        printf("Tour %d\n", i);
        printf("----------------------------------------\n");
        // Tour du joueur 1
        printf("\n----------------------------------------\n");
        printf("Tour de : %s\n", joueurA.pseudo);
        printf("----------------------------------------\n");
        // Initialisation de ses valeurs et demande s'il souhaite en changer
        scoreTourJoueurA = lancer_joueur();
        // Check de toutes les options de score
        joueurA.scorePartie = joueurA.scorePartie + scoreTourJoueurA;
        printf("Score total de %s : %d\n", joueurA.pseudo, joueurA.scorePartie);
        // Tour du joueur 2
        printf("\n----------------------------------------\n");
        printf("Tour de : %s\n", joueurB.pseudo);
        printf("----------------------------------------\n");
        // Initialisation de ses valeurs et demande s'il souhaite en changer
        scoreTourJoueurB = lancer_joueur();
        // Check de toutes les options de score
        joueurB.scorePartie = joueurB.scorePartie + scoreTourJoueurB;
        printf("Score total de %s : %d\n", joueurB.pseudo, joueurB.scorePartie);
        // Check du milieu de partie pour ajouter des points bonus
        if (i == 5) {
            checkMilieuPartie(&joueurA.scorePartie, &joueurB.scorePartie);
        }
    }
    // Affichage du gagnant
    if (joueurA.scorePartie > joueurB.scorePartie) {
        printf("Le joueur A a gagne\n");
        char* nom;
        int partie = 0;
        nom = joueurA.pseudo;
        partie = joueurA.scorePartie;
        save(nom,partie);
    }
    else {
        printf("Le joueur B a gagne\n");
        char* nom;
        int partie = 0;
        nom = joueurB.pseudo;
        partie = joueurB.scorePartie;
        save(nom,partie);
    }

    free(joueurA.pseudo);
    free(joueurB.pseudo);

    return 0;
}