// Paxton Proctor
// 10/28/2021
/* C program to find an element x in a
unsorted array that will be sorted using selection sort then using Exponential search.*/

#include <stdio.h>
#include <time.h>
#include <math.h>
#define min
// max amount of elements that can be held in array
#define MAX 255
// function prototype
int binarysearch(int arr[], int l, int r, int x);
void selectionSort(int arr[], int n);
void swap(int *xp, int *yp);
void printArray(int arr[], int size);
int exponentialSearch(int arr[], int n, int x);

// main program
int main(void) {
  // declarations
  int arr[MAX] = {0};
  int c;
  int n;
  int x;

  // ask user for n ele and integers for ele. also ask the val they want to find
  printf("Enter number of elements:\n");
  scanf("%d",&n); 
  printf("Enter %d integers:\n", n);
  for (c = 0; c < n; c++)
    scanf("%d",&arr[c]); 
  printf("Enter the value to find:\n");
  scanf("%d", &x);

  // Function call
  selectionSort(arr, n);
  printf("Sorted array: \n");
    printArray(arr, n);
  int result = exponentialSearch(arr, n, x);

  // if result is -1 print ele not in array else print result
  if (result == -1) {
    printf("Element is not present in array");
  }
  else {
    printf("Element is present at index %d", result);
  }
  return 0;
}
// end of main

/* Function to print an array */
void printArray(int arr[], int size) {
  int i;
  for (i=0; i < size; i++)
    printf("%d ", arr[i]);
  printf("\n");
}
/* passes pointers that point to the min ele and the first ele
this function takes the min ele and swaps it with the first ele
*/
void swap(int *xp, int *yp) {
  // set temp equal to pointer that points to address arr min ele
  int temp = *xp;
  // set pointer arr min equal to pointer first ele which was the original location to first ele
  *xp = *yp;
  // set pointer first ele equal to the temp which was the orignial location to min ele
  *yp = temp;
}
 /* passes array and sizeofarray
 since binarysearch requires that the array be in order
 we must use a sort we chose selection sort
 have a for loop that will go till array is sorted
 find the minimum ele then swap min ele with first ele.
 */
void selectionSort(int arr[], int n){
  // declarations
  int i, j, min_idx;
 
  // One by one move boundary of unsorted subarray
  for (i = 0; i < n-1; i++)
  {
    // Find the minimum element in unsorted array
    min_idx = i;
    // go through each element in array
    for (j = i+1; j < n; j++)
      //if array ele is smaller than the min
      if (arr[j] < arr[min_idx])
        // set min to that ele
        min_idx = j;
 
      // Swap the found minimum element with the first element
      swap(&arr[min_idx], &arr[i]);
    }
}

// Returns position of first occurrence of
// x in array
int exponentialSearch(int arr[], int n, int x) {
  // If x is present at first location itself
  if (arr[0] == x)
    return 0;
 
    // Find range for binary search by
    // repeated doubling
  int i = 1;
  while (i < n && arr[i] <= x)
    i = i*2;
 
  //  Call binary search for the found range.
  return binarysearch(arr, i/2, min(i, n-1), x);
}
/* passes the array, left, right and desired number to find
will compare left and right and see if the ele is equal to x
or less than x. if less than increase middle by l and set it equal to left.
if more than subtract x from m and set it to right side. either we find the
desired number or we exit the loop and return with -1
*/ 
int binarysearch(int arr[], int l, int r, int x) {
  // comparing left to right
  while (l <= r) {
    // initializing middle
		int m = l + (r - l) / 2;

		// Check if x is present at mid
		if (arr[m] == x) {
      // return middle
			return m;
		}
		// If x greater, ignore l half  
		else if (arr[m] < x) {
      // add 1 to middle set it equal to left
			l = m + 1;
		}

		// If x is smaller, ignore r half 
		else {
      // sub 1 to middle set it equal to right
			r = m - 1;
		}
	}
	return -1;
}

/*
Time Complexity : O(Log n) 
Auxiliary Space : The above implementation of 
Binary Search is recursive and requires O(Log n) space.
With iterative Binary Search, we need only O(1) space.
Applications of Exponential Search: 

Exponential Binary Search is particularly 
useful for unbounded searches, 
where size of array is infinite. 
Please refer Unbounded Binary Search for an example.
It works better than Binary Search for bounded arrays,
and also when the element to be searched
is closer to the first element.

Time Complexity: O(n2) as there are two nested loops.
Auxiliary Space: O(1) 
The good thing about selection sort is it never makes more
than O(n) swaps and can be useful when
memory write is a costly operation.*/
