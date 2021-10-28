// Paxton Proctor
// 10/28/2021
/* This program takes in a input of numbers and uses linear search
to find a secific value that the user is looking for */

#include <stdio.h>
// max amount of elements that can be held in array
#define MAX 255
// function prototype
int search(int arr[], int n, int x);

// main program
int main(void) {
  // declarations
  int arr[MAX] = {0};
  int idx = 0;
  int n = sizeof(arr) / sizeof(arr[0]);
  int x;

  // Ask the user to enter the element they want to find
  printf("Enter an integer: ");
  scanf("%d", &x);
  printf("You entered: %d", x);

  // do ask the user to fill the array and increase the index
  // while it checks to see if it hits the max number and the integer -1 //is entered.
  do {
        printf("\nEnter elements to fill array, -1 to finish:\n");
        scanf("%d", &arr[idx]);
        idx++;
  } while(arr[idx-1] != -1 && idx < MAX);
  
  // Function call
  int result = search(arr, n, x);
  // if result is -1 orint ele not in array else print result
  if (result == -1){
    printf("Element is not present in array");
  }
  else {
    printf("Element is present at index %d", result);
  }
  return 0;
}
// end of main

/* passes the array, sizeof array n, and the number the user is looking for x.
will return the integer x else it will return -1
*/ 
int search(int arr[], int n, int x) {
  // initialize iterator
  int i;
  // for loop till end of array
  for(i = 0; i < n; i++) {
    // if array index is equal to number return that number 
    if (arr[i] == x) {
      return i;
    }
    // otherwise return -1
  }
  return -1;
}

/*The time complexity of the above algorithm is O(n). 
Linear search is rarely used practically because other
search algorithms such as the binary search algorithm 
and hash tables allow significantly faster-searching comparison to Linear search.
Improve Linear Search Worst-Case Complexity
if element Found at last  O(n) to O(1)
It is the same as previous method because here 
we are performing 2 ‘if’ operations in one iteration 
of the loop and in previous method we performed only 1 ‘if’ operation.
This makes both the time complexities same.*/
