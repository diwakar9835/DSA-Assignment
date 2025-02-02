// EXERCISE: 5
// Given an array arr[]. Rotate the array to the left (counter-clockwise direction) by d steps, where d is a positive integer. Do the mentioned change in the array in place. 
// Note: Consider the array as circular.

// Solution

#include <iostream>
using namespace std;

void reverseArray(int arr[], int start, int end) {
    while (start < end) {
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
}

void rotateLeft(int arr[], int n, int d) {
    d = d % n;
    if (d == 0) return;

    reverseArray(arr, 0, d - 1);

    reverseArray(arr, d, n - 1);

    reverseArray(arr, 0, n - 1);
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    int d = 3;

    cout << "Original array: ";
    printArray(arr, n);

    rotateLeft(arr, n, d);

    cout << "Array after " << d << " left rotations: ";
    printArray(arr, n);

    return 0;
}
