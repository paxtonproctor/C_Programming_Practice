// Paxton Proctor
// 11/4/2021
/* This Program creates a stack*/
// malloc is used to allocate a block of memory in the heap
// free is used to deallocate memory blocks in the heap

#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

// function prototypes
struct StackNode* newNode(int data);

// A structure to represent a stack
struct StackNode {
  // initialization of data
  int data;

  // Node ptr points to next
  struct StackNode* next;
};

/* This function takes in data and creates
a new node and returns the node back to the stack*/
struct StackNode* newNode(int data) {
  // struct Node points to allocated memory in the heap
  struct StackNode* stackNode = (struct StackNode*)malloc(sizeof(struct StackNode));

  // Node points to address of data and sets it to data
  stackNode->data = data;
  // Node points to address of next and sets it to NULL
  stackNode->next = NULL;
  // return the node
  return stackNode;
}

/* This function takes in the root of the stack and will return if the stack is not empty */
int isEmpty(struct StackNode* root) {
  return !root;
}

/* This function takes in a pointer to a pointer root and data and will push
a new node onto the stack. */
void push(struct StackNode** root, int data) {
  // creates a new node
  struct StackNode* stackNode = newNode(data);

  // node points to next which will go to root
  stackNode->next = *root;
  // root will equal the Node
  *root = stackNode;
  // print notify that you pushed onto the stack
  printf("%d pushed to stack\n", data);
}

/* This function takes in a pointer to a pointer root and will pop a node out of the stack */
int pop(struct StackNode** root) {
  // if isempty return -2147483648 else
  if (isEmpty(*root)) {
    return INT_MIN;
  }
  else {
    // set Temp pointer to Node which is equal to root
    struct StackNode* temp = *root;
    // set root equal to next
    *root = (*root)->next;
    // pop the pointer temps data
    int popped = temp->data;

    // free the block temp
    free(temp);

    // returned the data that was popped
    return popped;
  }
}

/**/

int main(void) {
  printf("Hello World\n");
  return 0;
}
