// Paxton Proctor
// 10/28/2021
/* This program creates a simple linked list*/

#include <stdio.h>
#include <stdlib.h>

// Function Prototype
void PrintList(struct Node* N);

// struct node
struct Node {
  int data;
  // pointer Node pointing to next
  struct Node* next;
};

// main driver
int main(void) {

  // pointers to pointing to NULL;
  struct Node* head = NULL;
  struct Node* second = NULL;
  struct Node* third = NULL;

  // allocate 3 Nodes in the heap
  head = (struct Node*)malloc(sizeof(struct Node));
  second = (struct Node*)malloc(sizeof(struct Node));
  third = (struct Node*)malloc(sizeof(struct Node));

  head->data = 1; // assign data in first node
  head->next = second; // Link first node with second node

  second->data = 2; // assign data in second node

  second->next = third; // Link second node with third node

  third->data = 3; // assign data in third and final node

  third->next = NULL; // point to null

  /*
    headptr
      ||
      \/
      12NODE1 -> 21NODE2 -> 3NODE3 -> NULL
  */
  PrintList(head);
  return 0;
}


void PrintList(struct Node* n) {
  while (n != NULL) {
    printf(" %d ", n->data);
    n = n->next;
  }
}
