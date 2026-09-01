#include <stdio.h>

int binarySearch(int arr[], int start, int end, int target) {
    if (start > end) {
        return -1;
    }

    int mid = (start + end) / 2;

    if (arr[mid] == target) {
        return mid;
    }
    else if (target > arr[mid]) {
        return binarySearch(arr, mid + 1, end, target);
    }
    else {
        return binarySearch(arr, start, mid - 1, target);
    }
}

int main() {
    int arr[] = {10, 20, 30, 40, 50, 60, 70};
    int n = 7;
    int target = 60;

    int result = binarySearch(arr, 0, n - 1, target);

    if (result != -1)
        printf("Found at position %d", result + 1);
    else
        printf("Not found");

    return 0;
}