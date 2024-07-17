/* ========= SELECTION SORT =========
In the begining, all elements are considered as unsorted.
Repeatedly selects the smallest (or largest) element from the unsorted portion of the list and swaps 
it with the first element of the unsorted part (on far left after the last sorted element if we want 
non-decreasing sort and on far right just before the last sorted element if we want decreasing sort).
This process is repeated for the remaining unsorted portion until the entire list is sorted.

- Time complexity: Both O(N^2)
- Space complexity: O()

Advantages:
    - Simple and easy to understand.
    - Works well with small datasets.
    - Usually faster than bubble sort.

Disadvantages:
    - Does not work well on large datasets.
    - Not stable
*/

#include <stdio.h>

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void selectionSort(int arr[], int n)
{
    int i, j, min_idx;

    // One by one move boundary of unsorted subarray
    for (i = 0; i < n-1; i++)
    {
        // Find the minimum element in unsorted array
        min_idx = i;
        for (j = i+1; j < n; j++)
          if (arr[j] < arr[min_idx])
            min_idx = j;

        // Swap the found minimum element with the first element
           if(min_idx != i)
            swap(&arr[min_idx], &arr[i]);
    }
}

/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Driver program to test above functions
int main()
{
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr)/sizeof(arr[0]);
    selectionSort(arr, n);
    printf("Sorted array: \n");
    printArray(arr, n);
    return 0;
}



