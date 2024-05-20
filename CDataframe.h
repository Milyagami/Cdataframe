#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "column.h"

// Définition d'une structure pour représenter un dataframe
typedef struct {
    COLONNE **colonnes;  // Tableau de pointeurs vers des colonnes
    int nombre_logique; // Taille logique (nombre de colonnes)
    int capacite_physique; // Taille physique (capacité du tableau de colonnes)
} Dataframe;

/**
* Créer un dataframe vide
* @return : Pointeur vers le dataframe créé
*/
Dataframe *creer_dataframe() {
    // Allouer de la mémoire pour un nouveau dataframe
    Dataframe *nouveau_dataframe = (Dataframe*)malloc(sizeof(Dataframe));
    if (nouveau_dataframe == NULL) {
        fprintf(stderr, "Erreur d'allocation de mémoire\n");
        return 0;
    }
    nouveau_dataframe->colonnes = NULL;          // Pas de colonnes au départ
    nouveau_dataframe->nombre_logique = 0;       // Taille logique initialisée à 0
    nouveau_dataframe->capacite_physique = 0;    // Taille physique initialisée à 0
    return nouveau_dataframe;
}

/**
* Remplir le dataframe avec des saisies utilisateurs
* @param df : Pointeur vers le dataframe
*/
void remplir_dataframe_utilisateur(Dataframe *df) {
    if (df == NULL) {
        fprintf(stderr, "Le Dataframe est NULL\n");
    } else {
        int nb_colonnes = 0, nb_lignes = 0;
        printf("Combien de colonnes voulez-vous ajouter : ");
        scanf("%d", &nb_colonnes);
        getchar();
        printf("Combien de lignes voulez-vous ajouter : ");
        scanf("%d", &nb_lignes);
        getchar();

        for (int i = 0; i < nb_colonnes; i++) {
            // Si la taille logique atteint la taille physique, augmenter la taille physique
            if (df->nombre_logique == df->capacite_physique) {
                df->capacite_physique += 256; // Augmenter la taille physique de 256
                // Réallouer de la mémoire pour les nouvelles colonnes
                COLONNE **nouveau_df = (COLONNE **)realloc(df->colonnes, (df->capacite_physique) * sizeof(COLONNE*));
                if (nouveau_df == NULL) {
                    fprintf(stderr, "Erreur d'allocation de mémoire\n");
                    return;
                }
                df->colonnes = nouveau_df;
            }

            char nom_colonne[256]; // Taille maximale du titre
            printf("Entrez le titre de la colonne %d : ", i);
            fgets(nom_colonne, sizeof(nom_colonne), stdin);
            nom_colonne[strcspn(nom_colonne, "\n")] = '\0'; // Enlever le retour à la ligne

            // Créer une nouvelle colonne avec le titre donné
            COLONNE *nouvelle_colonne = creer_colonne(nom_colonne);

            // Remplir la colonne avec les valeurs saisies par l'utilisateur
            for (int j = 0; j < nb_lignes; j++) {
                int valeur = 0;
                printf("Veuillez saisir la valeur %d de la colonne %s : ", j, nouvelle_colonne->nom);
                scanf("%d", &valeur);
                getchar();
                ajouter_valeur(nouvelle_colonne, valeur);
            }

            // Ajouter la colonne au dataframe
            *(df->colonnes + df->nombre_logique) = nouvelle_colonne;
            df->nombre_logique++;
        }
    }
}

/**
* Remplir le dataframe avec des valeurs prédéfinies
* @param df : Pointeur vers le dataframe
*/
void remplir_dataframe_predefini(Dataframe *df) {
    if (df == NULL) {
        fprintf(stderr, "Le Dataframe est NULL\n");
    } else {
        df->nombre_logique = 2; // Définir le nombre de colonnes
        df->capacite_physique = 256; // Définir la capacité initiale
        // Réallouer de la mémoire pour les nouvelles colonnes
        COLONNE **nouveau_df = (COLONNE **)realloc(df->colonnes, (df->capacite_physique) * sizeof(COLONNE*));
        if (nouveau_df == NULL) {
            fprintf(stderr, "Erreur d'allocation de mémoire\n");
            return;
        }
        df->colonnes = nouveau_df;

        // Créer et remplir les colonnes
        COLONNE *col1 = creer_colonne("col1");
        COLONNE *col2 = creer_colonne("col2");
        ajouter_valeur(col1, 1);
        ajouter_valeur(col1, 2);
        ajouter_valeur(col2, 3);
        ajouter_valeur(col2, 4);
        ajouter_valeur(col1, 5);
        ajouter_valeur(col1, 6);
        ajouter_valeur(col2, 7);
        ajouter_valeur(col2, 8);

        // Ajouter les colonnes au dataframe
        *(df->colonnes) = col1;
        *(df->colonnes + 1) = col2;
    }
}

/**
* Afficher tout le contenu du dataframe
* @param df : Pointeur vers le dataframe
*/
void afficher_dataframe(Dataframe *df) {
    if (df == NULL) {
        fprintf(stderr, "Le Dataframe est NULL\n");
    } else {
        // Afficher les titres des colonnes
        for (int k = 0; k < df->nombre_logique; k++) {
            printf(" %s ", df->colonnes[k]->nom);
        }
        printf("\n");

        // Afficher les valeurs des colonnes
        int taille = (df->colonnes[0])->nombre_elements;
        for (int i = 0; i < taille; i++) {
            for (int j = 0; j < df->nombre_logique; j++) {
                printf(" %d ", ((df->colonnes[j])->valeurs)[i]);
            }
            printf("\n");
        }
    }
}

/**
* Afficher une partie des lignes du dataframe selon une limite fournie par l'utilisateur
* @param df : Pointeur vers le dataframe
* @param limite : Nombre de lignes à afficher
*/
void afficher_lignes(Dataframe *df, int limite) {
    if (df == NULL) {
        fprintf(stderr, "Le Dataframe est NULL\n");
    } else {
        // Implémenter la logique pour afficher les lignes selon la limite
    }
}

/**
* Afficher une partie des colonnes du dataframe selon une limite fournie par l'utilisateur
* @param df : Pointeur vers le dataframe
* @param limite : Nombre de colonnes à afficher
*/
void afficher_colonnes(Dataframe *df, int limite) {
    if (df == NULL) {
        fprintf(stderr, "Le Dataframe est NULL\n");
    } else {
        // Implémenter la logique pour afficher les colonnes selon la limite
    }
}

/**
* Ajouter une nouvelle ligne de valeurs au dataframe
* @param df : Pointeur vers le dataframe
*/
void ajouter_ligne(Dataframe *df) {
    if (df == NULL) {
        fprintf(stderr, "Le Dataframe est NULL\n");
    } else {
        // Ajouter une valeur à chaque colonne
        for (int i = 0; i < (df->nombre_logique); i++) {
            int valeur = 0;
            printf("Veuillez saisir la valeur à ajouter à la colonne %s : ", (df->colonnes[i])->nom);
            scanf("%d", &valeur);
            getchar();
            ajouter_valeur(df->colonnes[i], valeur);
        }
    }
}

/**
* Supprimer la dernière ligne de valeurs du dataframe
* @param df : Pointeur vers le dataframe
*/
void enlever_ligne(Dataframe *df) {
    if (df == NULL) {
        fprintf(stderr, "Le Dataframe est NULL\n");
    } else {
        // Réduire la taille logique de chaque colonne pour supprimer la dernière ligne
        for (int i = 0; i < (df->nombre_logique); i++) {
            ((df->colonnes[i])->nombre_elements)--;
        }
    }
}

/**
* Ajouter une nouvelle colonne au dataframe
* @param df : Pointeur vers le dataframe
*/
void ajouter_colonne(Dataframe *df) {
    if (df == NULL) {
        fprintf(stderr, "Le Dataframe est NULL\n");
    } else {
        // Si la taille logique atteint la taille physique, augmenter la taille physique
        if (df->nombre_logique == df->capacite_physique) {
            df->capacite_physique += 256; // Augmenter la taille physique de 256
            // Réallouer de la mémoire pour les nouvelles colonnes
            COLONNE **nouveau_df = (COLONNE **)realloc(df->colonnes, (df->capacite_physique) * sizeof(COLONNE*));
            if (nouveau_df == NULL) {
                fprintf(stderr, "Erreur d'allocation de mémoire\n");
                return;
            }
            df->colonnes = nouveau_df;
        }

        char nom_colonne[256]; // Taille maximale du titre
        printf("Entrez le titre de la colonne que vous voulez ajouter : ");
        fgets(nom_colonne, sizeof(nom_colonne), stdin);
        nom_colonne[strcspn(nom_colonne, "\n")] = '\0'; // Enlever le retour à la ligne

        // Créer une nouvelle colonne avec le titre donné
        COLONNE *nouvelle_colonne = creer_colonne(nom_colonne);

        // Remplir la colonne avec les valeurs saisies par l'utilisateur
        for (int j = 0; j < (df->colonnes[0])->nombre_elements; j++) {
            int valeur = 0;
            printf("Veuillez saisir la valeur %d de la colonne %s : ", j, nouvelle_colonne->nom);
            scanf("%d", &valeur);
            getchar();
            ajouter_valeur(nouvelle_colonne, valeur);
        }

        // Ajouter la colonne au dataframe
        *(df->colonnes + df->nombre_logique) = nouvelle_colonne;
        df->nombre_logique++;
    }
}

/**
* Supprimer une colonne du dataframe
* @param df : Pointeur vers le dataframe
*/
void enlever_colonne(Dataframe *df) {
    if (df == NULL) {
        fprintf(stderr, "Le Dataframe est NULL\n");
    } else {
        char nom_colonne[256]; // Taille maximale du titre
        printf("Entrez le titre de la colonne que vous voulez supprimer : ");
        fgets(nom_colonne, sizeof(nom_colonne), stdin);
        nom_colonne[strcspn(nom_colonne, "\n")] = '\0'; // Enlever le retour à la ligne

        int trouve = 0; // Variable pour vérifier si la colonne a été trouvée

        // Parcourir les colonnes pour trouver celle à supprimer
        for (int i = 0; i < (df->nombre_logique); i++) {
            if (strcmp(nom_colonne, df->colonnes[i]->nom) == 0) {
                // Supprimer la colonne
                liberer_colonne(&(df->colonnes[i]));
                trouve = 1;

                // Réorganiser les colonnes restantes
                for (int j = i; j < (df->nombre_logique) - 1; j++) {
                    df->colonnes[j] = df->colonnes[j + 1];
                }
                df->nombre_logique--;
                break;
            }
        }

        if (!trouve) {
            printf("La colonne %s n'existe pas.\n", nom_colonne);
        }
    }
}

/**
* Renommer le titre d'une colonne du dataframe
* @param df : Pointeur vers le dataframe
*/
void renommer_colonne(Dataframe *df) {
    if (df == NULL) {
        fprintf(stderr, "Le Dataframe est NULL\n");
    } else {
        int trouve = 0;
        char ancien_titre[256]; // Taille maximale du titre
        printf("Quel est le titre de la colonne que vous voulez renommer : ");
        fgets(ancien_titre, sizeof(ancien_titre), stdin);
        ancien_titre[strcspn(ancien_titre, "\n")] = '\0'; // Enlever le retour à la ligne

        // Parcourir les colonnes pour trouver celle à renommer
        for (int i = 0; i < df->nombre_logique; i++) {
            if (strcmp(df->colonnes[i]->nom, ancien_titre) == 0) {
                trouve = 1;
                printf("Quel est le nouveau nom de la colonne : ");
                char nouveau_titre[256];
                fgets(nouveau_titre, sizeof(nouveau_titre), stdin);
                nouveau_titre[strcspn(nouveau_titre, "\n")] = '\0'; // Enlever le retour à la ligne
                free(df->colonnes[i]->nom); // Libérer l'ancien titre
                df->colonnes[i]->nom = (char*)malloc((strlen(nouveau_titre) + 1) * sizeof(char));
                strcpy(df->colonnes[i]->nom, nouveau_titre); // Copier le nouveau titre
                break;
            }
        }

        if (!trouve) {
            printf("La colonne %s n'existe pas.\n", ancien_titre);
        }
    }
}

/**
* Vérifier l'existence d'une valeur dans le dataframe
* @param df : Pointeur vers le dataframe
* @return : 1 si la valeur est trouvée, 0 sinon
*/
int verifier_valeur(Dataframe *df) {
    if (df == NULL) {
        fprintf(stderr, "Le Dataframe est NULL\n");
        return 0;
    } else {
        int trouve = 0;
        int valeur = 0;
        printf("Quelle valeur voulez-vous rechercher : ");
        scanf("%d", &valeur);
        getchar();

        // Parcourir toutes les colonnes et toutes les lignes pour trouver la valeur
        for (int i = 0; i < df->nombre_logique; i++) {
            for (int j = 0; j < df->colonnes[i]->nombre_elements; j++) {
                if (df->colonnes[i]->valeurs[j] == valeur) {
                    trouve = 1;
                    break;
                }
            }
            if (trouve) break;
        }

        return trouve;
    }
}

/**
* Remplacer la valeur se trouvant dans une cellule du dataframe
* @param df : Pointeur vers le dataframe
*/
void changer_valeur(Dataframe *df) {
    if (df == NULL) {
        fprintf(stderr, "Le Dataframe est NULL\n");
    } else {
        int colonne = 0, ligne = 0, nouvelle_valeur = 0;
        printf("Saisissez le numéro de colonne de la valeur que vous voulez changer : ");
        scanf("%d", &colonne);
        while (colonne >= df->nombre_logique) {
            printf("Vous avez saisi un numéro de colonne supérieur au nombre de colonnes.\n");
            printf("Resaisissez le numéro de colonne de la valeur que vous voulez changer : ");
            scanf("%d", &colonne);
        }

        printf("Saisissez le numéro de ligne de la valeur que vous voulez changer : ");
        scanf("%d", &ligne);
        while (ligne >= df->colonnes[colonne]->nombre_elements) {
            printf("Vous avez saisi un numéro de ligne supérieur au nombre de lignes.\n");
            printf("Resaisissez le numéro de ligne de la valeur que vous voulez changer : ");
            scanf("%d", &ligne);
        }

        printf("Saisissez la nouvelle valeur : ");
        scanf("%d", &nouvelle_valeur);
        df->colonnes[colonne]->valeurs[ligne] = nouvelle_valeur; // Remplacer la valeur
    }
}

/**
* Afficher les noms des colonnes du dataframe
* @param df : Pointeur vers le dataframe
*/
void afficher_noms_colonnes(Dataframe *df) {
    if (df == NULL) {
        fprintf(stderr, "Le Dataframe est NULL\n");
    } else {
        // Afficher le titre de chaque colonne
        for (int i = 0; i < df->nombre_logique; i++) {
            printf("Titre de la colonne %d : %s\n", i, df->colonnes[i]->nom);
        }
    }
}

/**
* Afficher le nombre de lignes du dataframe
* @param df : Pointeur vers le dataframe
*/
void nombre_lignes(Dataframe *df) {
    if (df == NULL) {
        fprintf(stderr, "Le Dataframe est NULL\n");
    } else {
        // Afficher le nombre de lignes en utilisant la taille logique de la première colonne
        printf("Le Dataframe contient %d ligne(s).\n", df->colonnes[0]->nombre_elements);
    }
}

/**
* Afficher le nombre de colonnes du dataframe
* @param df : Pointeur vers le dataframe
*/
void nombre_colonnes(Dataframe *df) {
    if (df == NULL) {
        fprintf(stderr, "Le Dataframe est NULL\n");
    } else {
        // Afficher le nombre de colonnes en utilisant la taille logique du dataframe
        printf("Le Dataframe contient %d colonne(s).\n", df->nombre_logique);
    }
}

/**
* Compter le nombre de cellules contenant une valeur égale à x
* @param df : Pointeur vers le dataframe
* @param valeur : Valeur à rechercher
* @return : Nombre de cellules contenant la valeur
*/
int nombre_valeurs_egales(Dataframe *df, int valeur) {
    if (df == NULL) {
        fprintf(stderr, "Le Dataframe est NULL\n");
        return -1;
    } else {
        int occurrences = 0;
        // Parcourir chaque colonne et compter les occurrences de la valeur
        for (int i = 0; i < df->nombre_logique; i++) {
            occurrences += compter_occurrences(df->colonnes[i], valeur);
        }
        return occurrences;
    }
}

/**
* Compter le nombre de cellules contenant une valeur supérieure à x
* @param df : Pointeur vers le dataframe
* @param valeur : Valeur de référence
* @return : Nombre de cellules contenant une valeur supérieure
*/
int nombre_valeurs_superieures(Dataframe *df, int valeur) {
    if (df == NULL) {
        fprintf(stderr, "Le Dataframe est NULL\n");
        return -1;
    } else {
        int superieures = 0;
        // Parcourir chaque colonne et compter les valeurs supérieures à la valeur donnée
        for (int i = 0; i < df->nombre_logique; i++) {
            superieures += compter_valeurs_superieures(df->colonnes[i], valeur);
        }
        return superieures;
    }
}

/**
* Compter le nombre de cellules contenant une valeur inférieure à x
* @param df : Pointeur vers le dataframe
* @param valeur : Valeur de référence
* @return : Nombre de cellules contenant une valeur inférieure
*/
int nombre_valeurs_inferieures(Dataframe *df, int valeur) {
    if (df == NULL) {
        fprintf(stderr, "Le Dataframe est NULL\n");
        return -1;
    } else {
        int inferieures = 0;
        // Parcourir chaque colonne et compter les valeurs inférieures à la valeur donnée
        for (int i = 0; i < df->nombre_logique; i++) {
            inferieures += compter_valeurs_inferieures(df->colonnes[i], valeur);
        }
        return inferieures;
    }
}
