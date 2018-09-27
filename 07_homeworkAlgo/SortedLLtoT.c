
#include<stdio.h>
#include<stdlib.h>

/*Please note that functions can be found online.
I used the following resource to find and understand the code
https://www.geeksforgeeks.org/sorted-linked-list-to-balanced-bst/
*/
struct List{
  int data;
  struct List *next;
};

struct Tree{
  int data;
  struct Tree *L;
  struct Tree *R;
};

struct Tree* tree(int data);
struct Tree* sortedListToBST(struct List **my_list1, int n);

//counts the number of nodes in Linked List
int countLists(struct List *my_list){
  int count = 0;
  struct List *temp = my_list;
  while(temp){
    temp = temp->next;
    count++;
  }
  return count;
}


struct Tree* toTree(struct List *my_list){
  int n = countLists(my_list);
  return sortedListToBST(&my_list, n);
}

//function resposnsible for the creation of the tree and returing its root.
struct Tree* sortedListToBST(struct List **my_list1, int n){
  if (n <= 0){
    return NULL;
  }
  struct Tree *L = sortedListToBST(my_list1, n/2);
  struct Tree *root = tree((*my_list1)->data);
  root->L = L;
  *my_list1 = (*my_list1)->next;
  root->R = sortedListToBST(my_list1, n-n/2-1);
  return root;
}

//insert node at the start of the list
void push(struct List** my_list1, int new_data){
  struct List* new_node = (struct List*) malloc(sizeof(struct List));
  new_node->data  = new_data;
  new_node->next = (*my_list1);
  (*my_list1) = new_node;
}

//print function linked list
void printlist(struct List *node){
  while(node!=NULL){
    printf("%d ", node->data);
    node = node->next;
  }
}

//initialize tree
struct Tree* tree(int data){
  struct Tree* node = (struct Tree*)malloc(sizeof(struct Tree));
  node->data = data;
  node->L = NULL;
  node->R = NULL;
  return node;
}

//print Binary tree after conversion
void printtree(struct Tree* node)
{
  if (node == NULL){
    return;
  }
  printf("%d ", node->data);
  printtree(node->L);
  printtree(node->R);
}


int main()
{
  struct List* my_list = NULL;
  int array[10];
  for(int i = 10; i>=1; i--){
    push(&my_list, i);
  }
  printf("Sorted Linked List: ");
  printlist(my_list);
  printf("\n");

  //Binary tree conversion
  struct Tree *root = toTree(my_list);
  printf("Binary tree Conversion: ");
  printtree(root);

  return 0;
}
