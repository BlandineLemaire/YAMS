#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "yams.h"
#define NB_DES 5      // On d�finit une constante pour le nombre de DES d�finit sur 5

// La fonction lancer_des permet de g�n�rer un valeur al�a
int lancer_des() 
{
    // d�claration de la variable qui prend la valeur de d�
    int r;
    do 
    {
        // On affecte � r une variale al�atoire entre 0 et 6
        r = rand() % 7;
    } while (r == 0); // On rentre dans boucle pour reg�n�rer la valeur tant que r vaut 0
    return r; // La fonction retourne la valeur de r
}

// AFFICHER TABLEAU

void afficher_des(int des[]) {
    // Boucle entre 0 et 5 et incr�mentation de l'index pour parcourir le tableau de d�s du tour courant
    for (int i = 0; i < 5; ++i) {
        // affichage de la valeur du d�s en fonction de l'index (que l'on affiche incr�ment� de 1 pour que l'affichage soit coh�rent)
        printf("dice %d : %d\n", i + 1, des[i]);
    }
}

// TRI TABLEAU

void tri_tableau(int des[]) {
    // Mise en ordre du tableau pour compter plus facilement le nombre d'occurences des valeurs
    // Parcours du tableau de d�s
    for (int i = 0; i < NB_DES; ++i) {
        // Parcours du tableau de d�s � la position i + 1
        for (int j = i + 1; j < NB_DES; ++j) {
            // Condition si la valeur i est sup�rieure � i+1
            if (des[i] > des[j]) {
                // sauvegarde de la valeur des[i] dans une variable tampon
                int a = des[i];
                // inversion des valeurs des[i] et des[i+1]
                des[i] = des[j];
                // affectation de la valeur sauvegard�e en tampon � des[j]
                des[j] = a;
            }
        }
    }
}

// BRELANT

int brelant(int des[]) {
    // initialisation d'une valeur pour sauvegarder le score en cas de brelant
    int score = 0;
    // Cr�ation et initialisation de 6 compteurs (1 par valeur de d�s) pour d�terminer la pr�sence d'un brelant ou non
    // Le compteur est incr�ment� � chaque fois que la valeur se r�p�te lorsque l'on parcourt le tableau de d�s
    // Ensuite, si le compteur vaut 3, alors on a un brelant, on calcul le score et on sort de la boucle
    int a = 0, b = 0, c = 0, d = 0, e = 0, f = 0;
    // Boucle qui parcourt le tableau de d� pass� en param�tre
    for (int i = 0; i < NB_DES; ++i) {
        // Cas o� la valeur du d� � l'indice courant vaut 1
        if (des[i] == 1)
        {
            ++a;
            if (a == 3) {
                score = (3 * 1);
                break;
            }
        }
        // Cas o� la valeur du d� � l'indice courant vaut 2
        else if (des[i] == 2)
        {
            ++b;
            if (b == 3) {
                score = (3 * 2);
                break;
            }
        }
        // Cas o� la valeur du d� � l'indice courant vaut 3
        else if (des[i] == 3)
        {
            ++c;
            if (c == 3) {
                score = (3 * 3);
                break;
            }

        }
        // Cas o� la valeur du d� � l'indice courant vaut 4
        else if (des[i] == 4)
        {
            ++d;
            if (d == 3) {
                score = (3 * 4);
                break;
            }
        }
        // Cas o� la valeur du d� � l'indice courant vaut 5
        else if (des[i] == 5)
        {
            ++e;
            if (e == 3) {
                score = (3 * 5);
                break;
            }
        }
        // Cas o� la valeur du d� � l'indice courant vaut 6
        else if(des[i] == 6)
        {
            ++f;
            if (f == 3) {
                score = (3 * 6);
                break;
            }
        }
    };
    // On retourne la valeur du score
    return score;
}

// CARRE

int carre(int des[]) {
    // Initialisation de la valeur du score � 0
    int score = 0;
    // Comme pour le brelant on cr�� et on initialise 6 compteurs � 0
    // Chaque compteur est incr�ment� de 1 si la valeur courante correspond � la condition
    // Si le compteur vaut 4, alors on a un carr�, et on calcul le score en fonction et on sort de la boucle
    int a = 0, b = 0, c = 0, d = 0, e = 0, f = 0;
    // Boucle de parcourt le tableau de d�s en param�tres
    for (int i = 0; i < NB_DES; ++i) {
        switch (des[i]) {
        // Cas o� la valeur courante du d� vaut 1
        case 1:
            ++a;
            if (a == 4) {
                score = (4 * 1);
            }
            break;
        // Cas o� la valeur courante du d� vaut 2
        case 2:
            ++b;
            if (b == 4) {
                score = (4 * 2);
            }
            break;
        // Cas o� la valeur courante du d� vaut 3
        case 3:
            ++c;
            if (c == 4) {
                score = (4 * 3);
            }
            break;
            // Cas o� la valeur courante du d� vaut 4
        case 4:
            ++d;
            if (d == 4) {
                score = (4 * 4);
            }
            break;
            // Cas o� la valeur courante du d� vaut 5
        case 5:
            ++e;
            if (e == 4) {
                score = (4 * 5);
            }
            break;
            // Cas o� la valeur courante du d� vaut 6
        case 6:
            ++f;
            if (f == 4) {
                score = (4 * 6);
            }
            break;
        }
    }
    // On retourne le score
    return score;
}

// FULL

int full(int des[])
{
    // On initialise le score � 0
    int score = 0;
    // On parcourt le tableau de d�s pass� en param�tres
    for (int j = 0; j <= NB_DES; j++)
    {
        // On d�termine si il existe un brelant de valeur index + 1 (on teste donc les valeur de 1 � 6)
        // On ajoute �galement une condition si le score est toujours �gal � 0, afin d'�viter de potentielles erreurs dans l'utilisation de la condition
        if (brelant(des) == (3 * (j + 1)) && score == 0)
        {
            // On cr�� 3 variables des1, des2 et tmp qui vont nous permettre de d�teriner si les deux autre d�s sont �gaux
            int tmp = 0; // cette variable va servir de tampon
            int des1 = 0;
            int des2 = 0;
            // On parcourt les index du tableau
            for (int i = 0; i < 5; i++)
            {
                // Si la valeur du d� est �gale � diff�rente de la valeur du brelant
                if (des[i] != j + 1)
                {
                    // Si tmp vaut 0 on rentre dans la condition 
                    if (tmp == 0)
                    {
                        // des1 prend la valeur courante du des et tmp passe � 1
                        des1 = des[i];
                        tmp = 1;
                    }
                    // Sinon on le cas ou tmp != 0 indique que l'on a d�j� un des1 enregistr� donc on donne la valeur courante du d� � des2
                    else
                    {
                        des2 = des[i];
                    }
                }
            }
            // On compare maintenant la valeur des deux des et on donne au score la valeur de 25
            if (des1 == des2)
            {
                score = 25;
            }
        }
    }
    // On retourne la valeur du score
    return score;
}


int yams(int des[]) {
    // L'algo de cette fonction est le m�me que pour le brelant et le carr� mais la condition du compteur est fix�e � 5
    int score = 0;
    int a = 0, b = 0, c = 0, d = 0, e = 0, f = 0;
    for (int i = 0; i < NB_DES; ++i) {
        switch (des[i]) {
        case 1:
            ++a;
            if (a == 5) {
                score = 50;
            }
            break;
        case 2:
            ++b;
            if (b == 5) {
                score = 50;
            }
            break;
        case 3:
            ++c;
            if (c == 5) {
                score = 50;
            }
            break;
        case 4:
            ++d;
            if (d == 5) {
                score = 50;
            }
            break;
        case 5:
            ++e;
            if (e == 5) {
                score = 50;
            }
            break;
        case 6:
            ++f;
            if (f == 5) {
                score = 50;
            }
            break;
        }
    }
    return score;
}

// La fonction check doublons permet de d�terminer si il existe au moins un doublons dans le tableau pass� en param�tres
int check_doublons(int des[])
{
    // On cr�� une variable qui si elle est � 0  indique une absence de doublons. Dans le cas contraire, il existe des doublons  
    int check = 0;
    // On parcourt le tableau jusqu'� l'indice NB_DES - 1
    for (int i = 0; i < NB_DES - 1; i++) {
        // On parcourt une deuxi�me fois le tableau jusqu'� l'indice maximum du nombre de d�s
        for (int j = i + 1; j < NB_DES; j++) {
            // Si la valeur deus des d'indices i et j sont �gaux, cela signifie que c'est un doublon
            if (des[i] == des[j]) {
                // On passe le check � 1
                check = 1;
            }
        }
    }
    // on retourne check 
    return check;
}

// La fonction petite suite permet de d�terminer si le lancer de des contient cette figure
int petite_suite(int des[])
{
    // Initialisation d'une variable score � 0
    int score = 0;
    // Appel de la fonction tri_tableau, afin de faciliter la recherche d'une petite suite
    tri_tableau(des);
    // Condition d'une petite suite qui commence � 1
    if (des[0] == 1 && des[4] == 4)
    {
        score = 30;
    }
    // Condition d'une petite suite qui commence � 2
    else if (des[0] == 2 && des[4] == 5)
    {
        score = 30;
    }
    // Condition d'une petite suite qui commence � "
    else if (des[0] == 3 && des[4] == 6)
    {
        score = 30;
    }
    return score;
}

// Fonction qui permet de d�terminer si il existe une grande suite dans le tableau pass� en param�tre
int grande_suite(int des[])
{
    // Initialisation d'une variable score � 0
    int score = 0;
    // On initialise une variable check � -1
    int check = -1;
    // On appelle la fonction check_doublons et on envoie la valeur dans notre variable check
    check = check_doublons(des);
    // On tri notre tableau de des
    tri_tableau(des);
    // On rentre dans la condition si il n'existe pas de doublons
    if (check == 0) {
        // Cas o� la grande suite commence � 1
        if (des[0] == 1 && des[4] == 5)
        {
            score = 40;
        }
        // Cas o� la grande suite commence � 2
        else if (des[0] == 2 && des[4] == 6)
        {
            score = 40;
        }
    }
    // On retourne 
    return score;
}

// Cette fonction permet de d�terminer le score de chaque joueurs au milieu de la partie afin d'ajouter ou non un bonus de milieu de partie
void checkMilieuPartie(int* scoreA, int* scoreB) {
  
    if (*scoreA  > 63) 
    {
        printf("Bonus de milieu de partie !\n");
        scoreA += 35;
    }
    if (*scoreB > 63) 
    {
        printf("Bonus de milieu de partie !\n");
        scoreB += 35;
    }
}

// Cette fonction sera appell�e si le joueur ne compl�te aucune combinaison
int chance(int des[]) {
    int score = 0;
    // On parcourt le tableau de des
    for (int i = 0; i < NB_DES; ++i) {
        // On incr�mente la variable score de la valeur courante du d�
        score += des[i];
    }
    // On retourne notre variable score
    return score;
}

// D�termination de la meilleure figure du tour
int checkFigure(int des[]) {
    // Initialisation du score � 0
    int score = 0;
    // On teste a chaque niveau de condition si le score vaut 0 ou non
    // Si la fonction renvoie 0 on passe dans le niveau de condition suivant, 
    // Sinon le score prend la valeur renvoy� par la fonction, et on annonce la pr�sence de la combinaison correspondante
    if (yams(des) == 0) {
        if (carre(des) == 0) {
            if (full(des) == 0) {
                if (brelant(des) == 0) {
                    if (grande_suite(des) == 0) {
                        if (petite_suite(des) == 0) {
                            score = chance(des);
                            printf("CHANCE !\n");
                        }
                        else {
                            score = petite_suite(des);
                            printf("PETITE SUITE !\n");
                        }
                    }
                    else {
                        score = grande_suite(des);
                        printf("GRANDE SUITE !\n");
                    }
                }
                else {
                    score = brelant(des);
                    printf("BRELANT !\n");
                }
            }
            else {
                score = full(des);
                printf("FULL !\n");
            }
        }
        else {
            score = carre(des);
            printf("CARRE !\n");
        }
    }
    else {
        score = yams(des);
        printf("YAMS !\n");
    }
    // On affiche le score marqu� par le joueur lors du tour
    printf("Score + %d\n", score);
    // On retourne le score
    return score;
}

int tour() 
{
    int des[5];
    int score;
    // Lancement de des
    lancer_joueur(des);
    // Tri des valeurs
    tri_tableau(des);
    // recherche des differents points possibles
    score = checkFigure(des);
    return score;
}

// Cette fonction permet au joueur d'effectuer son lancer et de choisir des d�s � relancer si besoin
int lancer_joueur() {
    int score = 0;
    int des[5];
    // premier lancer
    for (int i = 0; i < NB_DES; ++i) {
        des[i] = lancer_des();
    }
    afficher_des(des);
    // relance pour le second tour
    int choice; // La variable choix permet de s�lectionner le d�s � relancer
    int cptT2 = 0; // Initialisation de la variable qui nous permet de parcourir notre tableau de des
    printf("Second turn\nSelect the dice you want to run again (1 to 5) - 0 to go on 3rd turn : \n");
    do {
        // On invite l'utilisateur � saisir un choix de d� � relancer
        scanf("%d", &choice);
        if (choice > 0 && choice < 6) {
            des[choice - 1] = lancer_des(); // Relance des des
        }
        cptT2++;
    } while (choice != 0 && cptT2 < 6); // Parcourt du tableau de des 
    afficher_des(des);
    // relance pour le troisieme tour
    int cptT3 = 0; // Initialisation de la variable qui nous permet de parcourir notre tableau de des
    printf("Third turn\nSelect the dice you want to run again (1 to 5) - 0 to finish : \n");
    do {
        // On invite l'utilisateur � saisir un choix de d� � relancer
        scanf("%d", &choice);
        if (choice > 0 && choice < 6) {
            des[choice - 1] = lancer_des();   // Relance des des
        }
        cptT3++;
    } while (choice != 0 && cptT3 < 6);   // Parcourt du tableau de des
    afficher_des(des);   // Appel de la fonction pour afficher les des
    
    score = checkFigure(des);   // Appel de la fonction check figure pour r�cup�rer le score
    return score;
}

void save(char* nom, int scorePartie) {
    FILE* fichier = NULL;                           // D�claration d'une variable de ty fichier
    fichier = fopen("score.txt", "a+");             // Ouverture du fichier en mode ajout

    if (fichier != NULL)                            // Si l'ouverture du fichier fonctionne
    {
        fprintf(fichier, " Gagnant partie : %s | %d\n", nom, scorePartie);    // On ajoute le nom du gagnat avec son score
        fclose(fichier);                            // Fermeture du fichier
    }
}