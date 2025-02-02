// HANDS-ON EXERCISE: 1

// Given an array arr[] and an integer k where k is smaller than the size of the array, the task is to find the kth smallest element in the given array. 

// Note: Don't solve it using the inbuilt sort function.


//Solution

#include <iostream>
using namespace std;

int partition(int arr[], int left, int right) {
    int pivot = arr[right];
    int i = left;

    for (int j = left; j < right; j++) {
        if (arr[j] <= pivot) {
            swap(arr[i], arr[j]);
            i++;
        }
    }
    swap(arr[i], arr[right]);
    return i;
}

int quickSelect(int arr[], int left, int right, int k) {
    if (left <= right) {
        int pivotIndex = partition(arr, left, right);

        if (pivotIndex == k)
            return arr[pivotIndex];
        else if (pivotIndex > k)
            return quickSelect(arr, left, pivotIndex - 1, k);
        else
            return quickSelect(arr, pivotIndex + 1, right, k);
    }
    return -1;
}

int kthSmallest(int arr[], int size, int k) {
    return quickSelect(arr, 0, size - 1, k - 1);
}

int main() {
    int arr[] = {7, 10, 4, 3, 20, 15};
    int size = sizeof(arr) / sizeof(arr[0]);
    int k = 3;

    cout << "Kth smallest element is: " << kthSmallest(arr, size, k) << endl;
    return 0;
}
