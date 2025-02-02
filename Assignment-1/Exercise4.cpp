// EXERCISE: 4
// Given an unsorted array arr[]. Find the subarray arr[s...e] such that sorting this subarray makes the whole array sorted. 
// Note: If the given array is already sorted then return [0, 0].

// Solution

#include <iostream>
#include <climits>
using namespace std;

void findSubarrayToSort(int arr[], int n) {
    int left = -1, right = -1;
    int min_val = INT_MAX, max_val = INT_MIN;

    for (int i = 0; i < n - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            left = i;
            break;
        }
    }

    if (left == -1) {
        cout << "[0, 0]" << endl;
        return;
    }

    for (int i = n - 1; i > 0; i--) {
        if (arr[i] < arr[i - 1]) {
            right = i;
            break;
        }
    }

    for (int i = left; i <= right; i++) {
        min_val = min(min_val, arr[i]);
        max_val = max(max_val, arr[i]);
    }

    while (left >= 0 && arr[left] > min_val) {
        left--;
    }

    while (right < n && arr[right] < max_val) {
        right++;
    }

    cout << "[" << left + 1 << ", " << right - 1 << "]" << endl;
}

int main() {
    int arr[] = {1, 3, 5, 2, 6, 4, 8, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    findSubarrayToSort(arr, n);

    return 0;
}
