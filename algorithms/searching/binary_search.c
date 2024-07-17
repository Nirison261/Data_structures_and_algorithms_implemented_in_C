/*
- Time complexity: Best Case Ω(1), Average case θ(logN), worst case O(logN)
- Space complexity: Auxiliary O(1)

Disadvantage:
    - Efficient than linear search but the elements to be search into must be sorted first.
*/

#include <math.h>

int binarySearch(int arr[], int size, int target) {
    int left = 0;
    int right = size - 1;

    while(left <= right) {
        int m = floor((left + right) / 2);
        if(arr[m] > target) {
            right = m - 1
        } else if(arr[m] < target) {
            left = m + 1;
        } else {
            return m;
        }
    }

    return -1;
}