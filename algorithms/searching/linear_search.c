/*
- Time complexity: Best Case Ω(1), Average case θ(N), worst case O(N)
- Space complexity: Total O(N), Auxiliary O(1)
*/

int linearSearch(int arr[], int size, int target) {
    int i;
    for(i = 0; i < size; i++) {
        if(arr[i] == target)
            return i;
    }

    return -1;
}