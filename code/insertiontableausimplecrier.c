#include<stdio.h>
#include<stdlib.h>
//definir la structure du noeud
 typedef struct Node {
   int data;
   struct Node*next;
 } Node;
//Fonction pour creer un nouveau noed
 Node* createNode(int value){
   Node*newNode=(Node*)malloc(sizeof(Node));
    if (!newNode){
      printf("Erreur d'allocation memoire\n");
      exit(1);
    }
   newNode->data=value;
   newNode->next=NULL;
   return newNode;
}
//Fonction pour insere un element dans la liste triee
void insertSorted(Node** head, int value){
     Node* newNode = createNode(value);
     //cas 1: liste vide ou insertion en tete
      if(*head==NULL || (*head)->data >= value){
        newNode->next=*head;
        *head=newNode;
      }
      //cas 2 : Trouver la position d'insertion
      Node*current=*head;
      while(current->next!=NULL && current->next->data < value){
        current=current->next;
      }
      //Inserer apres current
      newNode->next=current->next;
      current->next=newNode;
}
//Foction pour afficher la liste
void printListe(Node* head){
     Node*current=head;
     while(current != NULL){
          printf("%d->",current->data);
          current = current->next;
     }
     printf("NULL\n");
}
//programme principale
  int main(){
      Node*head=NULL;
      int n,val,newVal;
       //insertion dans une liste criee
      printf("Combien d'elements voulez-vous entrer?");
      scanf("%d",n);
      printf("Entrer les %d elements(ils sont entrer dans l'ordre crier):\n",n);
        for(int i=0;i<n;i++){
          scanf("%d",&val);
          insertSorted(&head,val);
        }
      printf("\nListe actuelle:\n");
      printListe(head);
      printf("\nEntrez l'element a inserer:");
      scanf("%d",&newVal);
      insertSorted(&head,newVal);
      //Affichage de la liste triee
      printf("\nListe apres insertio triee:\n");
      printListe(head);
      return 0;
  }
