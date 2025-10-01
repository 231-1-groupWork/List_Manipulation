#include <stdio.h>
#include <stdlib.h>

// etape 1 : Structure du nœud avec un pointeur "precedent" en plus
struct NoeudDouble {
    int donnee;
    struct NoeudDouble* suivant;
    struct NoeudDouble* precedent;
};

// Fonction pour inserer un nœud dans une liste doublement chainee triee
void insererTriDouble(struct NoeudDouble** pointeur_tete, int nouvelle_donnee) {
    
    // etape 2 : Creer le nouveau nœud
    struct NoeudDouble* nouveau_noeud = (struct NoeudDouble*)malloc(sizeof(struct NoeudDouble));
    nouveau_noeud->donnee = nouvelle_donnee;
    nouveau_noeud->precedent = NULL;
    nouveau_noeud->suivant = NULL;
    
    // etape 3 : Cas où la liste est vide ou l'insertion se fait au debut
    if (*pointeur_tete == NULL || (*pointeur_tete)->donnee >= nouvelle_donnee) {
        nouveau_noeud->suivant = *pointeur_tete;
        if (*pointeur_tete != NULL) {
            (*pointeur_tete)->precedent = nouveau_noeud;
        }
        *pointeur_tete = nouveau_noeud;
        return;
    }
    
    // etape 4 : Parcourir la liste pour trouver l'emplacement
    struct NoeudDouble* actuel = *pointeur_tete;
    while (actuel->suivant != NULL && actuel->suivant->donnee < nouvelle_donnee) {
        actuel = actuel->suivant;
    }
    
    // etape 5 : Relier le nouveau nœud avec ses voisins
    nouveau_noeud->suivant = actuel->suivant; 

    if (actuel->suivant != NULL) {
        actuel->suivant->precedent = nouveau_noeud;
    }

    actuel->suivant = nouveau_noeud;
    nouveau_noeud->precedent = actuel;
}

// Fonction pour afficher la liste
void afficherListeDouble(struct NoeudDouble* noeud) {
    while (noeud != NULL) {
        printf("%d <-> ", noeud->donnee);
        noeud = noeud->suivant;
    }
    printf("NULL\n");
}

// Programme principal pour tester
int main() {
    struct NoeudDouble* tete = NULL;

    printf("insertion de 20...\n");
    insererTriDouble(&tete, 20);
    afficherListeDouble(tete);
    
    printf("insertion de 10...\n");
    insererTriDouble(&tete, 10);
    afficherListeDouble(tete);

    printf("insertion de 30...\n");
    insererTriDouble(&tete, 30);
    afficherListeDouble(tete);

    printf("insertion de 5...\n");
    insererTriDouble(&tete, 5);
    afficherListeDouble(tete);
    
    printf("insertion de 25...\n");
    insererTriDouble(&tete, 25);
    afficherListeDouble(tete);
    
    printf("\nVoici la liste doublement chainee finale triee !\n");
    
    return 0;
}