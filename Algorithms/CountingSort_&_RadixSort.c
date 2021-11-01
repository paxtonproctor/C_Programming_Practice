// Paxton Proctor
// 10/31/2021
/* This program takes in a input of numbers and uses radix sort
to sort the numbers in order*/

#include <stdio.h>

// function prototypes
int getMax(int arr[], int n);
void countSort(int arr[], int n, int exp);
void radixsort(int arr[], int n);
void print(int arr[], int n);

// main driver
int main(void) {
  int arr[] = { 190, 34, 45, 87, 801, 23, 2, 77};
  int n = sizeof(arr) / sizeof(arr[0]);

  // functioncall
  radixsort(arr, n);
  print(arr, n);
  return 0;
}

/* This function passes the array 
and size of array to find a max value
from the array. 
*/
int getMax(int arr[], int n) {
  // initialization
  int max = arr[0];
  
  // goes through the array and compares
  // the index to max then will set the
  // max to the index till its highest
  // number fails.
  for (int i = 1; i < n; i++) {
    if (arr[i] > max) {
      max = arr[i];
    }
  }
  return max;
}
/* Radix function requires a counting sort
it passes in the array, sizeofarray, and
the digits that put 0's in
*/
void countSort(int arr[], int n, int exp) {
  // initialization
  int output[n];
  int i, count[10] = {0};

  // store count of occurrences in count[]
  for (i = 0; i < n; i++) {
    count[(arr[i] / exp) % 10]++;
  }

  /* Change count[i] so that count[i] now 
  contains actual pos of this digit in output[]
  */
  for ( i = 1; i < 10; i++) {
    count[i] += count[i - 1];
  } 

  // Build the output array
  for (i = n - 1; i >= 0; i--) {
    output[count[(arr[i] / exp) % 10] - 1] = arr[i];
    count[(arr[i] / exp) % 10]--;
  }

  // Copy the output array to arr[], so that arr[] now contains
  // sorted numbers according to current digit
  for (i = 0; i < n; i++) {
    arr[i] = output[i];
  }
}

/* This function passes in array and array sizeofarray
This function sorts array of sizeofarray using radix sort
*/
void radixsort(int arr[], int n) {
  // Find the max
  int m = getMax(arr, n);

  /* Do counting sort for every digit. Note that exp is passed
  exp is 10 ^ i where i is current digit number
  */
  for (int exp = 1; m / exp > 0; exp *= 10) {
    countSort(arr, n, exp);
  }
}

// print function
void print(int arr[], int n) {
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}
