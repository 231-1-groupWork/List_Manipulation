#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Définition d'un nœud
typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

// Fonction pour créer un nœud
Node* creerNode(int valeur) {
    Node* nouveau = (Node*)malloc(sizeof(Node));
    if (nouveau == NULL) {
        printf("Erreur d'allocation mémoire\n");
        exit(1);
    }
    nouveau->data = valeur;
    nouveau->next = nouveau; // circulaire
    nouveau->prev = nouveau;
    return nouveau;
}

// Insertion en queue
Node* insererQueue(Node* head, int valeur) {
    Node* nouveau = creerNode(valeur);

    if (head == NULL) { // liste vide
        return nouveau;
    }

    Node* tail = head->prev;   // dernier élément
    tail->next = nouveau;
    nouveau->prev = tail;
    nouveau->next = head;
    head->prev = nouveau;

    return head; // head ne change pas
}

// Insertion en tête
Node* insererTete(Node* head, int valeur) {
    Node* nouveau = creerNode(valeur);

    if (head == NULL) { // liste vide
        return nouveau;
    }

    Node* tail = head->prev;   // dernier élément
    nouveau->next = head;
    nouveau->prev = tail;
    tail->next = nouveau;
    head->prev = nouveau;

    return nouveau; // le nouveau devient la tête
}

// Fonction d'affichage
void afficher(Node* head) {
    if (head == NULL) {
        printf("Liste vide\n");
        return;
    }

    Node* temp = head;
    printf("Liste : ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

// Lecture sécurisée d'un entier
int lireEntier(const char *message) {
    char buffer[100];
    int valeur;
    char extra;

    while (1) {
        printf("%s", message);

        if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
            printf("Erreur de lecture. Reessayez.\n");
            continue;
        }

        // Vérifier que l'entrée contient un entier valide sans caractères parasites
        if (sscanf(buffer, "%d %c", &valeur, &extra) == 1) {
            return valeur;
        } else {
            printf("Entree invalide. Veuillez entrer un nombre entier.\n");
        }
    }
}

int main() {
    Node* head = NULL;

    // Création de la liste initiale : 3, 4, 5, 6
    head = insererQueue(head, 3);
    head = insererQueue(head, 4);
    head = insererQueue(head, 5);
    head = insererQueue(head, 6);

    printf("Liste initiale :\n");
    afficher(head);

    int valeur, choix;

    // Lecture sécurisée de la valeur à ajouter
    valeur = lireEntier("Entrez le nombre a ajouter : ");

    // Lecture sécurisée du choix (1 ou 2 seulement)
    while (1) {
        choix = lireEntier("Ou voulez-vous inserer ? (1 - Tete, 2 - Queue) : ");
        if (choix == 1 || choix == 2) break;
        printf("Choix invalide. Veuillez entrer 1 ou 2.\n");
    }

    if (choix == 1) {
        head = insererTete(head, valeur);
    } else {
        head = insererQueue(head, valeur);
    }

    printf("Liste apres insertion :\n");
    afficher(head);

    return 0;
}
