// Paxton Proctor
// 10/31/2021
/* This program takes in a input of numbers and uses merge sort
to sort the numbers in order*/

#include <stdio.h>
#include <stdlib.h>
#define MAX 10
// function prototype
void merge(int arr[], int l, int m, int r);
void mergeSort(int arr[], int l, int r);
void printArray(int A[], int size);

// main program
int main(void) {
  // declarations
  int arr[MAX] = {0};
  int idx = 0;
  int n = sizeof(arr) / sizeof(arr[0]);

  // do ask the user to fill the array and increase the index
  // while it checks to see if it hits the max number and the integer -1 //is entered.
  do {
        printf("\nEnter elements to fill array, -1 to finish:\n");
        scanf("%d", &arr[idx]);
        idx++;
  } while(arr[idx-1] != -1 && idx < MAX);

  printf("Given array is \n");
    printArray(arr, n);
  
  mergeSort(arr, 0, n - 1);

  printf("\nSorted array is \n");
    printArray(arr, n);
  return 0;
}

void merge(int arr[], int l, int m, int r) {
  int i, j, k;
  int n1 = m - l + 1;
  int n2 = r - m;
  
  /* create temp arrays */
 int L[n1], R[n2];
  
 /* Copy data to temp arrays L[] and R[] */
 for (i = 0; i < n1; i++) {
   L[i] = arr[l + i];
 }
 for (j = 0; j < n2; j++) {
   R[j] = arr[m + 1 + j];
 }
  
  /* Merge the temp arrays back into arr[l..r]*/
  i = 0; // Initial index of first subarray
  j = 0; // Initial index of second subarray
  k = l; // Initial index of merged subarray
  while (i < n1 && j < n2) {
    if (L[i] <= R[j]) {
      arr[k] = L[i];
      i++;
    }
    else {
      arr[k] = R[j];
      j++;
    }
      k++;
  }
  
  /* Copy the remaining elements of L[], if there
  are any */
  while (i < n1) {
    arr[k] = L[i];
      i++;
      k++;
  }
  
  /* Copy the remaining elements of R[], if there
  are any */
  while (j < n2) {
    arr[k] = R[j];
    j++;
    k++;
  }
}
  
/* l is for left index and r is right index of the
sub-array of arr to be sorted */
void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l + (r - l) / 2;
  
        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
  
        merge(arr, l, m, r);
    }
}
  
/* UTILITY FUNCTIONS */
/* Function to print an array */
void printArray(int A[], int size) {
  int i;
  for (i = 0; i < size; i++){
    printf("%d ", A[i]);
  }
  printf("\n");
}


/* Time Complexity: Sorting arrays on different machines.
Merge Sort is a recursive algorithm and time complexity can be expressed as following recurrence relation. 
T(n) = 2T(n/2) + θ(n)

The above recurrence can be solved either using the Recurrence 
Tree method or the Master method. It falls in case II of Master Method
and the solution of the recurrence is θ(nLogn). Time complexity of Merge Sort is
θ(nLogn) in all 3 cases (worst, average and best) as merge sort always 
divides the array into two halves and takes linear time to merge two halves.
Auxiliary Space: O(n)
Algorithmic Paradigm: Divide and Conquer
Sorting In Place: No in a typical implementation
Stable: Yes

Drawbacks of Merge Sort
Slower comparative to the other sort algorithms for smaller tasks.
Merge sort algorithm requires an additional memory space of 0(n) for the temporary array.
It goes through the whole process even if the array is sorted.
