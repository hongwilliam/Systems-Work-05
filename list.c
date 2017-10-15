#include <stdio.h>
#include <stdlib.h>

struct node{
  int i;
  struct node *next;
};

void print_list(struct node *n){

  //while each node has a non-null next 
  while (n){
    printf("element: %d \n", n->i);
    n = n->next; }
}

struct node * insert_front(struct node *n, int value){

  //use heap memory because stack memory will get popped off!

  //calloc provides zeroed memory
  struct node *new_node = calloc(1, sizeof(struct node));

  //set new_node as a copy of original n
  new_node->i = n->i;
  new_node->next = n->next;

  //just change value of n with the new value
  //n will be the "inserted node" in the beginning
  n->i = value;
  n->next = new_node; 

  //new_node->i = value;
  //new_node->next = n;
  
  return new_node; //return pointer to beginning of the list, which is now modified
}

struct node *free_list(struct node *n){

  struct node *copy = n;
  struct node *previous = calloc(1,sizeof(struct node));
  while(copy){
    previous = copy->next;
    free(copy);
    copy = previous; //eliminate the preceding node, while preserving n
  }

  n->next = 0;
  return n;
}

int main(){

  //testing print_list
  printf("\ntesting print_list on a linked list of 1, 2, 3 \n");
  
  //make sure to calloc or else segmentation fault
  struct node *s1 = calloc(1,sizeof(struct node));
  struct node *s2 = calloc(1,sizeof(struct node));
  struct node *s3 = calloc(1,sizeof(struct node));
  
  //note: reference type 'struct node *' is a pointer, so use the -> operator
  s1->i = 1;
  s1->next = s2;
  s2->i = 2;
  s2->next = s3;
  s3->i = 3;
  print_list(s1); //should print 1, 2, 3

  //testing insert_front
  printf("\nadding 4 to the beginning of the list we made earlier\n");
  insert_front(s1, 4);
  print_list(s1); //should print 4, 1, 2, 3

  //testing free_list
  printf("\ntesting free_list using s1 which we already made earlier\n");
  free_list(s1);
  print_list(s1); //should print 0
  
}

