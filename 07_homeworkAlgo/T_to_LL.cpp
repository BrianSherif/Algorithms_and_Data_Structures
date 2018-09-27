#include <stdio.h>
#include <stdlib.h>
/*Please note that functions TreeElements & createListbfs
can be found online. I used the following resource to find and understand the code
https://www.sanfoundry.com/c-program-tree-bfs-singly-linked-list/ */

struct tree{
  int data;
  struct tree *L;
  struct tree *R;
};

struct Queue{
  struct tree *ptr;
  struct Queue *next;
};

struct List{
  int data;
  struct List *next;
};

//creating the tree
void get_tree(struct tree **root){
  struct tree *tree;
  struct tree  *p;
  struct tree  *q;

  for(int i = 1; i <= 20; i++){
    tree = (struct tree *)malloc(sizeof(struct tree));
    tree->data = i;
    tree->L = NULL;
    tree->R = NULL;
    p = q = *root;
    if (*root == NULL){
      *root = tree;
    }else{
      while (1){
        q = p;
        if (p->data >= tree->data){
          p = p->L;
        }else{
          p = p->R;
        }
        if (p == NULL){
          break;
        }
      }
      if (q->data >= tree->data){
        q->L = tree;
      }else{
        q->R = tree;
      }
    }
  }
}

void createListbfs(struct tree *root, struct List **head)
{
  struct Queue *qhead;
  struct Queue *qrear;
  struct Queue *qtree;
  struct Queue *qrelease;
  struct List *tree;
  struct List *rear;

  if (root == NULL){
    return;
  }
  qhead = (struct Queue *)malloc(sizeof(struct Queue));
  qhead->ptr = root;
  qhead->next = NULL;
  qrear = qhead;
  while (qhead != NULL){
    tree = (struct List *)malloc(sizeof(struct List));
    tree->data = qhead->ptr->data;
    tree->next = NULL;
    if (*head == NULL){
      *head = tree;
    }else{
      rear->next = tree;
    }
    rear = tree;
    if (qhead->ptr->L != NULL){
      qtree = (struct Queue *)malloc(sizeof(struct Queue));
      qtree->ptr = qhead->ptr->L;
      qtree->next = NULL;
      qrear->next = qtree;
      qrear = qtree;
    }
    if (qhead->ptr->R != NULL){
      qtree = (struct Queue *)malloc(sizeof(struct Queue));
      qtree->ptr = qhead->ptr->R;
      qtree->next = NULL;
      qrear->next = qtree;
      qrear = qtree;
    }
    qrelease = qhead;
    qhead = qhead->next;
    free(qrelease);
  }
}


void printList(struct List *head){
  while (head != NULL){
    printf("%d  ", head->data);
    head = head->next;
  }
}

int main(){
  struct tree *root = NULL;
  struct List *head = NULL;

  get_tree(&root);
  createListbfs(root, &head);
  printf("Linked List Conversion: ");
  printList(head);

  return 0;
}
