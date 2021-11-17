/* Paxton Proctor
   11/17/2021
   This program creates a binary search tree
*/

#include<stdio.h>
#include<stdlib.h>

// Struct defines a node
struct node {
  // pointer left and right
  int key;
  struct node *left, *right;
};

/* This function takes in a int item
and creates a new BST node */
struct node* newNode(int item) {
  // pointer node to temp gets memory for node
  struct node* temp = (struct node*)malloc(sizeof(struct node));
  // points the temp to data
  temp->key = item;
  // points temp to left and right and sets them to null
  temp->left = temp->right = NULL;
  return temp;
};

/* This function takes in the root node
and traverses down the tree and orders them
*/
void inorder(struct node* root) {
  if (root != NULL) {
    inorder(root->left);
    printf("%d \n", root->key);
    inorder(root->right);
  }
}

/* this function takes in the struct ptr node and int key
to insert a new node with given key in Binary Search Tree*/
struct node* insert(struct node* node, int key) {
  // if the tree is empty, return a new node
  if (node == NULL) {
    return newNode(key);
  }

  // Otherwise recursion down the the tree
  if (key < node->key) {
    node->left = insert(node->left, key);
  }
  else if (key > node->key) {
    node->right = insert(node->right, key);
  }
  return node;
}

int main(void) {
  struct node* root = NULL;
  root = insert(root, 50);
  insert(root, 30);
  insert(root, 33);
  insert(root, 60);
  insert(root, 40);
  insert(root, 45);
  insert(root, 10);

  inorder(root);
  return 0;
}
