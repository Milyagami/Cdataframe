/*
COLONNE *ma_colonne = creer_colonne("Ma colonne");
// Affiche le titre de la colonne
printf("Titre de la colonne: %s\n", ma_colonne->nom);
// Affiche le nombre d'éléments dans la colonne
printf("Taille logique: %d\n", ma_colonne->nombre_elements);
// Affiche la capacité maximale de la colonne
printf("Capacité physique: %d\n", ma_colonne->capacite);

int valeur = 10; // Valeur à ajouter
// Ajoute la valeur à la colonne et vérifie si l'ajout a réussi
if (ajouter_valeur(ma_colonne, valeur))
    printf("Valeur ajoutée avec succès à ma colonne\n");
else
    printf("Erreur lors de l'ajout de la valeur à ma colonne\n");

// Ajoute d'autres valeurs à la colonne
ajouter_valeur(ma_colonne, 25);
ajouter_valeur(ma_colonne, 38);
ajouter_valeur(ma_colonne, 38);
ajouter_valeur(ma_colonne, 7);

// Affiche toutes les valeurs de la colonne
afficher_colonne(ma_colonne);

// Affiche le titre de la colonne
printf("Titre de la colonne: %s\n", ma_colonne->nom);
// Affiche le nombre d'éléments dans la colonne
printf("Taille logique: %d\n", ma_colonne->nombre_elements);
// Affiche la capacité maximale de la colonne
printf("Capacité physique: %d\n", ma_colonne->capacite);

// Affiche le nombre d'occurrences d'une valeur spécifique dans la colonne
printf("Le nombre d'occurrences de %d est %d\n", 38, compter_occurrences(ma_colonne, 38));
printf("Le nombre d'occurrences de %d est %d\n", 7, compter_occurrences(ma_colonne, 7));
printf("Le nombre d'occurrences de %d est %d\n", 3, compter_occurrences(ma_colonne, 3));

// Affiche la valeur à un indice spécifique dans la colonne
printf("La valeur à l'indice %d est %d\n", 1, rechercher_valeur(ma_colonne, 1));
printf("La valeur à l'indice %d est %d\n", 3, rechercher_valeur(ma_colonne, 3));
printf("La valeur à l'indice %d est %d\n", 10, rechercher_valeur(ma_colonne, 10));

// Affiche le nombre de valeurs supérieures à une valeur spécifique dans la colonne
printf("Le nombre de valeurs supérieures à %d est %d\n", 20, compter_valeurs_superieures(ma_colonne, 20));
printf("Le nombre de valeurs supérieures à %d est %d\n", 35, compter_valeurs_superieures(ma_colonne, 35));

// Affiche le nombre de valeurs inférieures à une valeur spécifique dans la colonne
printf("Le nombre de valeurs inférieures à %d est %d\n", 20, compter_valeurs_inferieures(ma_colonne, 20));
printf("Le nombre de valeurs inférieures à %d est %d\n", 40, compter_valeurs_inferieures(ma_colonne, 40));

// Affiche le nombre de valeurs égales à une valeur spécifique dans la colonne
printf("Le nombre de valeurs égales à %d est %d\n", 20, compter_valeurs_egales(ma_colonne, 20));
printf("Le nombre de valeurs égales à %d est %d\n", 10, compter_valeurs_egales(ma_colonne, 10));
printf("Le nombre de valeurs égales à %d est %d\n", 38, compter_valeurs_egales(ma_colonne, 38));

// Libère la mémoire allouée pour la colonne
liberer_colonne(&ma_colonne);
*/
