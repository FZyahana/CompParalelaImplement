#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define COUNT 10

struct node{
    int value;
    struct node *leftN;
    struct node *rightN;
};

struct node* nodeCreate (int value) {
    struct node* nodeNew = malloc(sizeof(struct node));
    nodeNew -> value = value;
    nodeNew -> leftN = NULL;
    nodeNew -> rightN = NULL;

    return nodeNew;
}

struct node* insertLeft (struct node* father, int value) {
    father -> leftN = nodeCreate(value);
    return father;
}

struct node* insertRight (struct node* father, int value) {
    father -> rightN = nodeCreate(value);
    return father;
}

struct node* fillTree(int max, int min, int count, struct node* father){
    int i;
    struct node* aux = father;
    for (i = 0; i < count; i++) {
        int num = (rand() % (max - min + 1)) + min;
        bool disponivel = false;
        while (!disponivel){
            if(num > aux->value){
                if(aux->rightN == NULL) {
                    insertRight(aux,num);
                    disponivel = true;
                    break;
                } else {
                    aux = aux ->rightN;
                }
            } else {
                if(aux->leftN == NULL) {
                    insertLeft(aux,num);
                    disponivel = true;
                    break;
                } else {

                    aux = aux ->leftN;
                }
            }
        }
        aux = father;
    }
    return aux;
}

void inorderTraversal(struct node* father) {
  if (father == NULL) return;
  inorderTraversal(father->leftN);
  printf("%d ->", father->value);
  inorderTraversal(father->rightN);
}

void preorderTraversal(struct node* father) {
  if (father == NULL) return;
  printf("%d ->", father->value);
  preorderTraversal(father->leftN);
  preorderTraversal(father->rightN);
}

void postorderTraversal(struct node* father) {
  if (father == NULL) return;
  postorderTraversal(father->leftN);
  postorderTraversal(father->rightN);
  printf("%d ->", father->value);
}

void printTree(struct node* father, int space){
   if (father == NULL)
      return;
   space += COUNT;
   printTree(father->rightN, space);
   for (int i = COUNT; i < space; i++)
      printf("\t");
   printf("%d\n", father->value);
   printTree(father->leftN, space);
}

int main(){
    struct node* teste = nodeCreate(5);
    teste = fillTree(100,0,5,teste);
    printf("\nInorder: \n");
    inorderTraversal(teste);
    printf("\nPreorder: \n");
    preorderTraversal(teste);
    printf("\nPostorder: \n");
    postorderTraversal(teste);
    printf("\TestPrint: \n");
    printTree(teste,0);
    return 0;
}