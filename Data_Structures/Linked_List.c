// Paxton Proctor
// 11/1/2021
/* This program creates a simple linked list*/
// malloc is used to allocate a block of memory in the heap
#include <stdio.h>
#include <stdlib.h>

// struct node
struct Node {
  int data;
  // pointer Node pointing to next
  struct Node *next;
};

// prints list
void printList(struct Node* n) {
  while (n != NULL) {
    printf(" %d ", n->data);
    n = n->next;
  }
}
/* This function has a pointer to pointer and a new data
That will be inserted in the front of the list
*/
void push(struct Node** head_ref, int new_data) {
  // Allocate node
  struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));

  // put in the data
  // pointer new_node to data and new node have new data
  new_node->data = new_data;

  // make next of new node as head
  // head pointer will point to the next
  new_node->next = (*head_ref);

  // move the head to point to the new node
  (*head_ref) = new_node;

}
/* This function has a previous node passed and the new data
It takes the previous node and inserts a node after it.
*/
void insertAfter(struct Node* prev_node, int new_data) {
  // checks if the given node is equal to NULL
  if (prev_node == NULL) {
    printf("The given node cannot be equal to NULL");
    return;
  }

  // allocate new node
  struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));

  // put in the data
  new_node->data = new_data;

  // make the new node the next of the previous node
  new_node->next = prev_node->next;

  // set the next equal to that of new node
  prev_node->next = new_node;
}

/* This function has a pointer to pointer to the head of the list
and an integer new data. it appends the new nodes at the end.
*/
void append(struct Node** head_ref, int new_data) {
  // allocate node
  struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));

  // pointer last points is equal to the pointer header reference
  struct Node *last = *head_ref;

  // put in the data
  new_node->data = new_data;

  //The new node will be the last of the nodes so we need it
  // to point to NULL
  new_node->next = NULL;

  // if link list is empty make new node as head
  if (*head_ref == NULL) {
    *head_ref = new_node;
    return;
  }
  else {
    // else traverse list till last node
    while (last->next != NULL) {
      last = last->next;
    }

    // change the next of last node
    last->next = new_node;
  }
  return;
}

// main driver
int main(void) {
  /*
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

    headptr
      ||
      \/
      12NODE1 -> 21NODE2 -> 3NODE3 -> NULL
  printList(head);*/
  /* Start with the empty list */
  struct Node* head = NULL;
 
  // Insert 6.  So linked list becomes 6->NULL
  append(&head, 6);
 
  // Insert 7 at the beginning. So linked list becomes 7->6->NULL
  push(&head, 7);
 
  // Insert 1 at the beginning. So linked list becomes 1->7->6->NULL
  push(&head, 1);
 
  // Insert 4 at the end. So linked list becomes 1->7->6->4->NULL
  append(&head, 4);
 
  // Insert 8, after 7. So linked list becomes 1->7->8->6->4->NULL
  insertAfter(head->next, 8);
 
  printf("\n Created Linked list is: ");
  printList(head);
  return 0;
}
