/* ======= QUICK SORT =======
QuickSort is a sorting algorithm based on the Divide and Conquer algorithm that picks an element 
as a pivot and partitions the given array around the picked pivot by placing the pivot in its correct 
position in the sorted array.

The key process in quickSort is a partition() . The target of partitions is to place the pivot (any element 
can be chosen to be a pivot) at its correct position in the sorted array and put all smaller elements to the 
left of the pivot, and all greater elements to the right of the pivot.

Partition is done recursively on each side of the pivot after the pivot is placed in its correct position 
and this finally sorts the array.

There are many different choices for picking pivots:
    - Always pick the first element as a pivot .
    - Always pick the last element as a pivot (implemented below)
    - Pick a random element as a pivot .
    - Pick the middle as the pivot.

- Time complexity: Best Case Ω(N log N), Average case θ( N log N), worst case O(N2)
- Auxiliary space complexity: O(1) or O(N) if we consider the recursive stack space
- Not a stable sorting algorithm

It is efficient on large data sets and isn't a good choice for small data set.
It has a low overhead, as it only requires a small amount of memory to function.
*/

#include <stdio.h>

// Utility function to swap tp integers
void swap(int* p1, int* p2)
{
    int temp;
    temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

int partition(int arr[], int low, int high)
{
    // choose the pivot (the last element here)
    int pivot = arr[high];

    // To find the right position for the pivot, i is chosen to store the index of the last found
    // element which is inferior or equal to the pivot. If an element inferior or equal to the pivot
    // is found, increment i and swap the value of the element with the value of arr[i].

    // => all elements superior to the pivot are pushed to the right.
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        // If current element is smaller than the pivot
        if (arr[j] < pivot) {
            // Increment index of smaller element
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]); // Put the pivot on it's place
    return (i + 1); // Return the index of the pivot
}

void quickSort(int arr[], int low, int high)
{
    // when low is less than high
    if (low < high) {

        // partition() returns the position of the pivot it used
        int pi = partition(arr, low, high);

        // Here, all elements smaller (not sorted) than the pivot are on the left
        // and all elements bigger than the pivot are on the right

        // Treat bigger element recursively
        quickSort(arr, low, pi - 1);

        // Treat bigger element recursively
        quickSort(arr, pi + 1, high);
    }
}

int main()
{
    int arr[] = { 10, 7, 8, 9, 1, 5 };
    int n = sizeof(arr) / sizeof(arr[0]);
  
    // Function call
    quickSort(arr, 0, n - 1);
  
  // Print the sorted array
    printf("Sorted Array\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}

