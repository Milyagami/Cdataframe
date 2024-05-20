/*
COLONNE *ma_colonne = creer_colonne("Ma super colonne");
// Affiche le titre de la colonne
printf("Nom de la colonne: %s\n", ma_colonne->nom);
// Affiche le nombre d'éléments dans la colonne
printf("Nombre d'éléments: %d\n", ma_colonne->nombre_elements);
// Affiche la capacité maximale de la colonne
printf("Capacité maximale: %d\n", ma_colonne->capacite);

int valeur = 25; // Valeur à ajouter
// Ajoute la valeur à la colonne et vérifie si l'ajout a réussi
if (ajouter_valeur(ma_colonne, valeur))
    printf("Valeur ajoutée avec succès à la colonne\n");
else
    printf("Échec de l'ajout de la valeur à la colonne\n");

// Ajoute d'autres valeurs à la colonne
ajouter_valeur(ma_colonne, 35);
ajouter_valeur(ma_colonne, 45);
ajouter_valeur(ma_colonne, 55);

// Affiche toutes les valeurs de la colonne
afficher_colonne(ma_colonne);

// Affiche le titre de la colonne
printf("Nom de la colonne: %s\n", ma_colonne->nom);
// Affiche le nombre d'éléments dans la colonne
printf("Nombre d'éléments: %d\n", ma_colonne->nombre_elements);
// Affiche la capacité maximale de la colonne
printf("Capacité maximale: %d\n", ma_colonne->capacite);

// Affiche le nombre d'occurrences d'une valeur spécifique dans la colonne
printf("Le nombre d'occurrences de %d est %d\n", 35, compter_occurrences(ma_colonne, 35));

// Affiche la valeur à un indice spécifique dans la colonne
printf("La valeur à l'indice %d est %d\n", 1, rechercher_valeur(ma_colonne, 1));

// Affiche le nombre de valeurs supérieures à une valeur spécifique dans la colonne
printf("Le nombre de valeurs supérieures à %d est %d\n", 30, compter_valeurs_superieures(ma_colonne, 30));

// Affiche le nombre de valeurs inférieures à une valeur spécifique dans la colonne
printf("Le nombre de valeurs inférieures à %d est %d\n", 50, compter_valeurs_inferieures(ma_colonne, 50));

// Affiche le nombre de valeurs égales à une valeur spécifique dans la colonne
printf("Le nombre de valeurs égales à %d est %d\n", 45, compter_valeurs_egales(ma_colonne, 45));

// Libère la mémoire allouée pour la colonne
liberer_colonne(&ma_colonne);

*/
