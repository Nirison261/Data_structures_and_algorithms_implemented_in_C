/* ======== INSERTION SORT =======
Insertion sort is a simple sorting algorithm that works by iteratively inserting each element 
of an unsorted list into its correct position in a sorted portion of the list.

Insertion sort is like sorting playing cards in your hands. You split the cards into two groups: 
the sorted cards and the unsorted cards. Then, you pick a card from the unsorted group and put it 
in the right place in the sorted group.

- Time complexity: Best Case Ω(N), Average case θ(N^2), worst case O(N^2)
- Auxiliary space complexity: O(1)
- Stable sorting algorithm

- Efficient for small lists and nearly sorted lists.
- Space-efficient.
- Faster comparing to bubble sort (potentially less swap)
- Not as efficient as other sorting algorithms (e.g., merge sort, quick sort) for most cases.

Use insertion sorting when:
- The list is small or nearly sorted.
- Simplicity and stability are important
*/

#include <stdio.h>

/*
In summary,
1. If key is less than element on it's left, swap them, retest key with it's new neighbor on the
   left, and so on...
2. If key is greater or equal to it's left, set the right element as the new key, and test the new key, and
   so on...
*/
void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        /* Move elements of arr[0..i-1], that are
          greater than key, to one position ahead
          of their current position */
        while (j >= 0 && key < arr[j]) {
            arr[j + 1] = arr[j]; // Part of the swap process
            j--;
        }
        arr[j + 1] = key; // Finish the swap process (key the temporary storage)
    }
}

// A utility function to print an array of size n
void printArray(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

/* Driver program to test insertion sort */
int main()
{
    int arr[] = { 12, 11, 13, 5, 6 };
    int n = sizeof(arr) / sizeof(arr[0]);

    insertionSort(arr, n);
    printArray(arr, n);

    return 0;
}