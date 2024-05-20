#include "CDataframe.h"

int main() {
    // Créer un nouveau dataframe vide
    Dataframe *mon_dataframe = creer_dataframe();

    // Remplir le dataframe avec des valeurs prédéfinies
    remplir_dataframe_predefini(mon_dataframe);

    // Afficher le contenu complet du dataframe
    afficher_dataframe(mon_dataframe);

    // Afficher les noms des colonnes du dataframe
    afficher_noms_colonnes(mon_dataframe);

    /*
    // Remplacer une valeur spécifique dans le dataframe
    changer_valeur(mon_dataframe);
    // Afficher le dataframe après avoir changé la valeur
    afficher_dataframe(mon_dataframe);

    // Renommer une colonne du dataframe
    renommer_colonne(mon_dataframe);
    // Afficher le dataframe après avoir renommé la colonne
    afficher_dataframe(mon_dataframe);

    // Ajouter une nouvelle ligne de valeurs au dataframe
    ajouter_ligne(mon_dataframe);
    // Afficher le dataframe après avoir ajouté une ligne
    afficher_dataframe(mon_dataframe);

    // Supprimer la dernière ligne de valeurs du dataframe
    enlever_ligne(mon_dataframe);
    // Afficher le dataframe après avoir supprimé une ligne
    afficher_dataframe(mon_dataframe);

    // Supprimer une colonne du dataframe
    enlever_colonne(mon_dataframe);
    // Afficher le dataframe après avoir supprimé une colonne
    afficher_dataframe(mon_dataframe);

    // Ajouter une nouvelle colonne au dataframe
    ajouter_colonne(mon_dataframe);
    // Afficher le dataframe après avoir ajouté une colonne
    afficher_dataframe(mon_dataframe);
    */

    // Fin du programme principal
    return 0;
}
