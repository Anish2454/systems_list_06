#include <stdio.h>
#include <stdlib.h>

//Declare Struct my_node
struct my_node {
  int data;
  char* name;
  //Pointer to the next node
  struct my_node* next;
};

//size of node = 24 bytes
size_t size = sizeof(struct my_node);

//Prints out data in a list
void print_list(struct my_node* node){
  if(!node){
    printf("NULL");
    return;
  }
  //Use "->" to access data from a struct pointer
  printf("%d -> ", node->data);
  return print_list(node->next);
}

//Takes a pointer to an existing list and the data to be created
//Creates a new node with that data and puts it at the beginning
//of the list. Returns a pointer to the beginning of the list.
struct my_node * insert_front(struct my_node* node, int i, char* name){
  //Declare the pointer to our new node
  struct my_node* p;

  //Since the memory associated with this function will
  //dissappear once it's done, we need to malloc space
  //for our node.
  p = (struct my_node*) malloc(size);

  //Create the new node
  struct my_node new;
  new.data = i;
  new.name = name;
  new.next = node; //places at beginning
  *p = new;
  return p;
}

//Takes a pointer to a list
//Frees each node in the list
struct my_node * free_list(struct my_node* node){
  //If the node is null, we're done
  if(!node) return node;

  //Create a pointer to the next node
  struct my_node* next = node -> next;

  //Free the current node
  free(node);

  //move onto the next node
  return free_list(next);
}
