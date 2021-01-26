#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "yams.h"
#define NB_DES 5

int lancer_des() {
    int r;
    do {
        r = rand() % 7;
    } while (r == 0);
    return r;
}

void afficher_des(int des[]) {
    for (int i = 0; i < 5; ++i) {
        printf("dice %d : %d\n", i + 1, des[i]);
    }
}

void tri_tableau(int des[]) {
    // Mise en ordre du tableau pour compter plus facilement le nombre d'occurences des valeurs
    for (int i = 0; i < NB_DES; ++i) {
        for (int j = i + 1; j < NB_DES; ++j) {
            if (des[i] > des[j]) {
                int a = des[i];
                des[i] = des[j];
                des[j] = a;
            }
        }
    }
}

int brelant(int des[]) {
    int score = 0;
    int a = 0, b = 0, c = 0, d = 0, e = 0, f = 0;
    for (int i = 0; i < NB_DES; ++i) {
        switch (des[i]) {
            case 1:
                ++a;
                if (a == 3) {
                    printf("Brelant of 1\n");
                    score = (3 * 1);
                }
                break;
            case 2:
                ++b;
                if (b == 3) {
                    printf("Brelant of 2\n");
                    score = (3 * 2);
                }
                break;
            case 3:
                ++c;
                if (c == 3) {
                    printf("Brelant of 3\n");
                    score = (3 * 3);
                }
                break;
            case 4:
                ++d;
                if (d == 3) {
                    printf("Brelant of 4\n");
                    score = (3 * 4);
                }
                break;
            case 5:
                ++e;
                if (e == 3) {
                    printf("Brelant of 5\n");
                    score = (3 * 5);
                }
                break;
            case 6:
                ++f;
                if (a == 3) {
                    printf("Brelant of 6\n");
                    score = (3 * 6);
                }
                break;
        }
    }
    //printf("1 : %d\n2 : %d\n3 : %d\n4 : %d\n5 : %d\n6 : %d\n",a,b,c,d,e,f);
    printf("Score + %d \n", score);
    return score;
}

int carre(int des[]) {
    int score = 0;
    int a = 0, b = 0, c = 0, d = 0, e = 0, f = 0;
    for (int i = 0; i < NB_DES; ++i) {
        switch (des[i]) {
            case 1:
                ++a;
                if (a == 4) {
                    printf("Carre of 1\n");
                    score = (4 * 1);
                }
                break;
            case 2:
                ++b;
                if (b == 4) {
                    printf("Carre of 2\n");
                    score = (4 * 2);
                }
                break;
            case 3:
                ++c;
                if (c == 4) {
                    printf("Carre of 3\n");
                    score = (4 * 3);
                }
                break;
            case 4:
                ++d;
                if (d == 4) {
                    printf("Carre of 4\n");
                    score = (4 * 4);
                }
                break;
            case 5:
                ++e;
                if (e == 4) {
                    printf("Carre of 5\n");
                    score = (4 * 5);
                }
                break;
            case 6:
                ++f;
                if (a == 4) {
                    printf("Carre of 6\n");
                    score = (4 * 6);
                }
                break;
        }
    }
    //printf("1 : %d\n2 : %d\n3 : %d\n4 : %d\n5 : %d\n6 : %d\n",a,b,c,d,e,f);
    printf("Score + %d \n", score);
    return score;
}

// FULL

int full(int des[]) {
    int score = 0;
    int a = 0, b = 0, c = 0, d = 0, e = 0, f = 0;
    int g = 0, h = 0, i = 0, j = 0, k = 0;
    for (int i = 0; i < NB_DES; ++i) {
        switch (des[i]) {
            case 1:
                ++a;
                if (a == 3) {
                    printf("Carre of 1\n");
                    score = 25;
                }
                break;
            case 2:
                ++b;
                if (b == 5) {
                    printf("Carre of 2\n");
                    score = 25;
                }
                break;
            case 3:
                ++c;
                if (c == 5) {
                    printf("Carre of 3\n");
                    score = 25;
                }
                break;
            case 4:
                ++d;
                if (d == 5) {
                    printf("Carre of 4\n");
                    score = 25;
                }
                break;
            case 5:
                ++e;
                if (e == 5) {
                    printf("Carre of 5\n");
                    score = 25;
                }
                break;
            case 6:
                ++f;
                if (a == 5) {
                    printf("Carre of 6\n");
                    score = 25;
                }
                break;
        }
    }
    //printf("1 : %d\n2 : %d\n3 : %d\n4 : %d\n5 : %d\n6 : %d\n",a,b,c,d,e,f);
    printf("Score + %d \n", score);
    return score;
}


int yams(int des[]) {
    int score = 0;
    int a = 0, b = 0, c = 0, d = 0, e = 0, f = 0;
    for (int i = 0; i < NB_DES; ++i) {
        switch (des[i]) {
            case 1:
                ++a;
                if (a == 5) {
                    printf("Yams of 1\n");
                    score = (50 + 5 * 1);
                }
                break;
            case 2:
                ++b;
                if (b == 5) {
                    printf("Yams of 2\n");
                    score = (50 + 5 * 2);
                }
                break;
            case 3:
                ++c;
                if (c == 5) {
                    printf("Yams of 3\n");
                    score = (50 + 5 * 3);
                }
                break;
            case 4:
                ++d;
                if (d == 5) {
                    printf("Yams of 4\n");
                    score = (50 + 5 * 4);
                }
                break;
            case 5:
                ++e;
                if (e == 5) {
                    printf("Yams of 5\n");
                    score = (50 + 5 * 5);
                }
                break;
            case 6:
                ++f;
                if (a == 5) {
                    printf("Yams of 6\n");
                    score = (50 + 5 * 6);
                }
                break;
        }
    }
    //printf("1 : %d\n2 : %d\n3 : %d\n4 : %d\n5 : %d\n6 : %d\n",a,b,c,d,e,f);
    printf("Score + %d \n", score);
    return score;
}

int check_doublons(int des[])
{
    int check = 0;

    for (int i = 0; i < NB_DES - 1; i++) {
        for (int j = i + 1; j < NB_DES; j++) {
            if (des[i] == des[j]) {
                check = 1;
            }
        }
    }
    return check;
}

int petite_suite(int des[])
{
    int score = 0;
    check_doublons(des);
    tri_tableau(des);

    if (check_doublons == 0)
    {
        if (des[0] == 1 && des[3] == 4)
        {
            printf("This is a small straight\n");
            score = 30;
        }
        else if (des[0] == 2 && des[3] == 5)
        {
            printf("This is a small straight\n");
            score = 30;
        }
        else if (des[1] == 2 && des[4] == 5)
        {
            printf("This is a small straight\n");
            score = 30;
        }
        else if (des[2] == 3 && des[5] == 6)
        {
            printf("This is a small straight\n");
            score = 30;
        }
    }
    return score;
}

int grande_suite(int des[])
{
    int score = 0;
    check_doublons(des);
    tri_tableau(des);

    if (des[0] == 1 && des[4] == 5)
    {
        printf("This is a small straight\n");
        score = 40;
    }
    else if (des[0] == 2 && des[4] == 6)
    {
        printf("This is a small straight\n");
        score = 40;
    }
    return score;
}

/*int* lancer_joueur() {
    int des[5];
        // premier lancer
        for (int i = 0; i < NB_DES; ++i) {
            des[i] = lancer_des();
        }
    afficher_des(des);
    // relance pour le second tour
    int choice;
    int cptT2 = 0;
    printf("Second turn\nSelect the dice you want to run again (1 to 5) - 0 to go on 3rd turn : \n");
    do {
        scanf("%d", &choice);
        if (choice > 0 && choice < 6) {
            des[choice - 1] = lancer_des();
        }
        cptT2++;
    } while (choice != 0 && cptT2 < 6);
    afficher_des(des);
    // relance pour le troisieme tour
    int cptT3 = 0;
    printf("third turn\nSelect the dice you want to run again (1 to 5) - 0 to finish : \n");
    do {
        scanf("%d", &choice);
        if (choice > 0 && choice < 6) {
            des[choice - 1] = lancer_des();
        }
        cptT3++;
    } while (choice != 0 && cptT3 < 6);
    afficher_des(des);
    return des;
}
*/

void checkMilieuPartie(int* scoreA, int* scoreB) {
    int* a = scoreA;
    int* b = scoreB;
    if (a  > 63) {
        scoreA += 35;
    }
    if (b > 63) {
        scoreB += 35;
    }
}

int chance(int des[]) {
    int score = 0;
    for (int i = 0; i < NB_DES; ++i) {
        score += des[i];
    }
    printf("Score + %d", score);
    return score;
}

int tour() {
    int des[5];
    int score;
    // Lancement de des
    lancer_joueur(des);
    // Tri des valeurs
    tri_tableau(des);
    // rechercge des differents points possibles
    if (brelant(des) > 0) {
        score = brelant(des);
    }
    if (carre(des) > 0) {
        score = carre(des);
    }
    if (petite_suite(des) > 0) {
        score = petite_suite(des);
    }
    if (grande_suite(des) > 0) {
        score = grande_suite(des);
    }
    if (yams(des) > 0) {
        score = yams(des);
    }
    if (score = 0) {
        score = chance(des);
    }
    return score;
}

int checkFigure(int des[]) {
    int scoreA = 0;
    if (yams(des) == 0) {
        if (carre(des) == 0) {
            if (full(des) == 0) {
                if (brelant(des) == 0) {
                    if (grande_suite(des) == 0) {
                        if (petite_suite(des) == 0) {
                            scoreA = chance(des);
                        }
                        else {
                            scoreA = petite_suite(des);
                        }
                    }
                    else {
                        scoreA = grande_suite(des);
                    }
                }
                else {
                    scoreA = brelant(des);
                }
            }
            else {
                scoreA = full(des);
            }
        }
        else {
            scoreA = carre(des);
        }
    }
    else {
        scoreA = yams(des);
    }
    return scoreA;
}

int lancer_joueur() {
    int score = 0;
    int des[5];
    // premier lancer
    for (int i = 0; i < NB_DES; ++i) {
        des[i] = lancer_des();
    }
    afficher_des(des);
    // relance pour le second tour
    int choice;
    int cptT2 = 0;
    printf("Second turn\nSelect the dice you want to run again (1 to 5) - 0 to go on 3rd turn : \n");
    do {
        scanf("%d", &choice);
        if (choice > 0 && choice < 6) {
            des[choice - 1] = lancer_des();
        }
        cptT2++;
    } while (choice != 0 && cptT2 < 6);
    afficher_des(des);
    // relance pour le troisieme tour
    int cptT3 = 0;
    printf("third turn\nSelect the dice you want to run again (1 to 5) - 0 to finish : \n");
    do {
        scanf("%d", &choice);
        if (choice > 0 && choice < 6) {
            des[choice - 1] = lancer_des();
        }
        cptT3++;
    } while (choice != 0 && cptT3 < 6);
    afficher_des(des);

    score = checkFigure(des);
    return score;
}
/*
void save(char* nom, int scorePartie) {
    int num;
    FILE* fichier;
    fichier = fopen("D:\BSI\04 - Language C avancé\Projet Yams\projectYams\program.txt", "w");

    if (fichier == NULL)
    {
        printf("Erreur! impossible de sauvegarder votre score");
        exit(1);
    }
    // obtention de la date
    time_t t;
    time(&t);
    fprintf(fichier, "------------------------------------------------------------");
    // Ecriture de la date
    fprintf(fichier, "Date de la partie : %s", ctime(&t));
    // Ecriture du nom du gagnant
    fprintf(fichier, "Gagnant : %s", nom);
    // Ecrtiture du score de la partie :
    fprintf(fichier, "score de la partie : %d", scorePartie);
    fclose(fichier);
}*/