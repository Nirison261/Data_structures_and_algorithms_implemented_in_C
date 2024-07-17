/* ========= BUBBLE SORT =========
This algorithm is not suitable for large data sets as its average and worst-case 
time complexity is quite high.

- Time complexity: Best Case Ω(N), Average case θ(N^2), worst case O(N^2)
- Space complexity: Total O(N), Auxiliary O(1) 
- It is a stable sorting algorithm

Simple to implement but has the worst efficiency.

Below is an optimized version of Bubble Sort
*/
void bubbleSort(int arr[], int n)
{
    int i, j;
    bool swapped;
    for (i = 0; i < n - 1; i++) {
        swapped = false;
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
                swapped = true;
            }
        }

        // Stop the iteration if no two element where swapped
        if (swapped == false)
            break;
    }
}
