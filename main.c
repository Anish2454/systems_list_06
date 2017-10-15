#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

int main(){
  printf("\nStructure: loo(15) -> boo(10) -> foo(5) -> NULL\n");

  printf("\n***insert_front/print_list test***\n\n");
  printf("insert_front(NULL, 5, 'foo'):\n");
  struct my_node* foo = insert_front(NULL, 5, "foo");
  print_list(foo);
  printf("\ninsert_front(foo, 10, 'boo'):\n");
  struct my_node* boo = insert_front(foo, 10, "boo");
  print_list(boo);
  printf("\ninsert_front(boo, 15, 'loo'):\n");
  struct my_node* loo = insert_front(boo, 15, "loo");
  print_list(loo);
  printf("\n\n*******************\n");

  //free_list() test:
  free_list(loo);
  //realloc(loo, 5) Should return an error if free_list() worked
  //It does :)
}
