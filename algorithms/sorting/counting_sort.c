/*
Counting Sort is a non-comparison-based sorting algorithm that works well when there is limited range of 
input values. 
It is particularly efficient when the range of input values is small compared to the number of elements to 
be sorted. 
The basic idea behind Counting Sort is to count the frequency of each distinct element in the input array 
and use that information to place the elements in their correct sorted positions.

- Time complexity: Both O(N+M) where N and M are respectively space taken by outputArray[] and countArray[]
- Space complexity: O(N+M)

Advantages:
    - generally performs faster than all comparison-based sorting algorithms, such as merge sort and 
    quicksort, if the range of input is of the order of the number of input.
    - Counting sort is a stable algorithm.
Disadvantages:
    - Counting sort doesn’t work on decimal values.
    - Counting sort is inefficient if the range of values to be sorted is very large.
    - Counting sort is not an In-place sorting algorithm, It uses extra space for sorting the array elements.

Use it when:
    - the range of values to be sorted is not large
    - elements to be sorted are integers
    - the space is not a problem
*/

#include <stdio.h>
#include <string.h>
#define RANGE 255
 
// The main function that sort the given string arr[] in
// alphabetical order
void countSort(char arr[])
{
    // The output character array that will have sorted arr
    char output[strlen(arr)];
 
    // Create a count array to store count of individual
    // characters and initialize count array as 0
    int count[RANGE + 1], i;
    memset(count, 0, sizeof(count));
 
    // Store count of each character
    for(i = 0; arr[i]; ++i)
        ++count[arr[i]];
 
    // Change count[i] so that count[i] now contains actual
    // position of this character in output array
    for (i = 1; i <= RANGE; ++i)
        count[i] += count[i-1];
 
    // Build the output character array
    for (i = 0; arr[i]; ++i)
    {
        output[count[arr[i]]-1] = arr[i];
        --count[arr[i]];
    }
 
    // Copy the output array to arr, so that arr now
    // contains sorted characters
    for (i = 0; arr[i]; ++i)
        arr[i] = output[i];
}
 
// Driver program to test above function
int main()
{
    char arr[] = "geeksforgeeks";//"applepp";
 
    countSort(arr);
 
    printf("Sorted character array is %sn", arr);
    return 0;
}