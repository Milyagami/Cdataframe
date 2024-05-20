#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Définition d'une structure pour représenter une colonne
typedef struct {
    char *nom;                 // Titre de la colonne
    int capacite;              // Taille physique (capacité) de la colonne
    int nombre_elements;       // Taille logique (nombre d'éléments) de la colonne
    int *valeurs;              // Tableau pour stocker les données
} COLONNE;

/**
* Créer une nouvelle colonne
* @param1 : Titre de la colonne
* @return : Pointeur vers la colonne créée
*/
COLONNE *creer_colonne(char* titre) {
    // Allouer de la mémoire pour une nouvelle colonne
    COLONNE *nouvelle_colonne = (COLONNE*)malloc(sizeof(COLONNE));
    if (nouvelle_colonne == NULL) {
        fprintf(stderr, "Impossible d'allouer de la mémoire pour la nouvelle colonne.\n");
        return 0;
    }
    // Allouer de la mémoire pour le titre de la colonne
    nouvelle_colonne->nom = (char*)malloc((strlen(titre) + 1) * sizeof(char));
    // Copier le titre dans la nouvelle colonne
    strcpy(nouvelle_colonne->nom, titre);
    // Initialiser les données de la colonne
    nouvelle_colonne->valeurs = NULL;            // Pas de données au départ
    nouvelle_colonne->nombre_elements = 0;       // Taille logique initialisée à 0
    nouvelle_colonne->capacite = 0;              // Taille physique initialisée à 0
    return nouvelle_colonne;
}

/**
* Ajouter une nouvelle valeur dans une colonne
* @param1 : Pointeur vers la colonne
* @param2 : Valeur à ajouter
* @return : 1 si la valeur est ajoutée, 0 sinon
*/
int ajouter_valeur(COLONNE* col, int valeur) {
    if (col == NULL) {
        fprintf(stderr, "Erreur: la colonne est introuvable.\n");
        return 0;
    }
    // Si la taille logique atteint la taille physique, augmenter la taille physique
    if (col->nombre_elements == col->capacite) {
        col->capacite += 256; // Augmenter la taille physique de 256
        // Réallouer de la mémoire pour les nouvelles données
        int* nouvelles_valeurs = (int *)realloc(col->valeurs, (col->capacite) * sizeof(int));
        if (nouvelles_valeurs == NULL) {
            fprintf(stderr, "Impossible d'allouer de la mémoire pour les nouvelles valeurs.\n");
            return 0;
        }
        col->valeurs = nouvelles_valeurs;
    }
    // Ajouter la nouvelle valeur à la fin de la colonne
    col->valeurs[col->nombre_elements] = valeur;
    col->nombre_elements += 1; // Incrémenter la taille logique
    return 1;
}

/**
* Libérer la mémoire allouée à une colonne
* @param col : Pointeur vers la colonne
*/
void liberer_colonne(COLONNE **col) {
    if (col == NULL || *col == NULL) {
        fprintf(stderr, "Erreur: la colonne est introuvable.\n");
    } else {
        // Libérer le tableau de données
        free((*col)->valeurs);
        (*col)->valeurs = NULL;
        // Libérer le titre de la colonne
        free((*col)->nom);
        (*col)->nom = NULL;
        // Libérer la structure de la colonne
        free(*col);
        *col = NULL;
    }
}

/**
* Afficher le contenu d'une colonne
* @param: Pointeur vers la colonne
*/
void afficher_colonne(COLONNE* col) {
    if (col == NULL) {
        fprintf(stderr, "Erreur: la colonne est introuvable.\n");
    } else {
        // Parcourir et afficher chaque élément de la colonne
        for (int i = 0; i < col->nombre_elements; i++) {
            printf("[%d] %d\n", i, col->valeurs[i]);
        }
    }
}

/**
* Compter le nombre d'occurrences d'une valeur dans une colonne
* @param1 : Pointeur vers la colonne
* @param2 : Valeur à chercher
* @return : Nombre d'occurrences
*/
int compter_occurrences(COLONNE* col, int x) {
    if (col == NULL) {
        fprintf(stderr, "Erreur: la colonne est introuvable.\n");
        return -1;
    }
    int occurrences = 0;
    // Parcourir la colonne et compter les occurrences de la valeur x
    for (int i = 0; i < col->nombre_elements; i++) {
        if (col->valeurs[i] == x) {
            occurrences++;
        }
    }
    return occurrences;
}

/**
* Rechercher une valeur dans une colonne à un indice donné
* @param1 : Pointeur vers la colonne
* @param2 : Indice de la valeur à rechercher
* @return : Valeur à l'indice donné ou -1 si l'indice est hors limites
*/
int rechercher_valeur(COLONNE* col, int indice) {
    if (col == NULL) {
        fprintf(stderr, "Erreur: la colonne est introuvable.\n");
        return -1;
    }
    if (indice >= col->nombre_elements) {
        printf("La position %d dépasse la taille de la colonne.\n", indice);
        return -1;
    }
    return col->valeurs[indice];
}

/**
* Compter le nombre de valeurs supérieures à une valeur donnée dans une colonne
* @param1 : Pointeur vers la colonne
* @param2 : Valeur de référence
* @return : Nombre de valeurs supérieures
*/
int compter_valeurs_superieures(COLONNE* col, int valeur) {
    if (col == NULL) {
        fprintf(stderr, "Erreur: la colonne est introuvable.\n");
        return -1;
    }
    int nombre_superieures = 0;
    // Parcourir la colonne et compter les valeurs supérieures à valeur
    for (int i = 0; i < col->nombre_elements; i++) {
        if (valeur < col->valeurs[i]) {
            nombre_superieures++;
        }
    }
    return nombre_superieures;
}

/**
* Compter le nombre de valeurs inférieures à une valeur donnée dans une colonne
* @param1 : Pointeur vers la colonne
* @param2 : Valeur de référence
* @return : Nombre de valeurs inférieures
*/
int compter_valeurs_inferieures(COLONNE* col, int valeur) {
    if (col == NULL) {
        fprintf(stderr, "Erreur: la colonne est introuvable.\n");
        return -1;
    }
    int nombre_inferieures = 0;
    // Parcourir la colonne et compter les valeurs inférieures à valeur
    for (int i = 0; i < col->nombre_elements; i++) {
        if (valeur > col->valeurs[i]) {
            nombre_inferieures++;
        }
    }
    return nombre_inferieures;
}

/**
* Compter le nombre de valeurs égales à une valeur donnée dans une colonne
* @param1 : Pointeur vers la colonne
* @param2 : Valeur de référence
* @return : Nombre de valeurs égales
*/
int compter_valeurs_egales(COLONNE* col, int valeur) {
    if (col == NULL) {
        fprintf(stderr, "Erreur: la colonne est introuvable.\n");
        return -1;
    }
    int nombre_egales = 0;
    // Parcourir la colonne et compter les valeurs égales à valeur
    for (int i = 0; i < col->nombre_elements; i++) {
        if (valeur == col->valeurs[i]) {
            nombre_egales++;
        }
    }
    return nombre_egales;
}
