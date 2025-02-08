// EXERCISE: 5

// Given an array of integers arr[]. Find the Inversion Count in the array.
// Two elements arr[i] and arr[j] form an inversion if arr[ i ] > arr[ j ] and i < j.  
// Inversion Count: For an array, inversion count indicates how far (or close) the array is from being sorted. If the array is already sorted then the inversion count is 0.
// If an array is sorted in the reverse order then the inversion count is the maximum.

// Solution

#include <iostream>
#include <vector>

using namespace std;

int merge(vector<int>& arr, int low, int mid, int high) {
    int count = 0, i = low, j = mid + 1, k = 0;
    vector<int> temp(high - low + 1);
    while (i <= mid && j <= high) {
        if (arr[i] <= arr[j]) temp[k++] = arr[i++];
        else {
            temp[k++] = arr[j++];
            count += (mid - i + 1);
        }
    }
    while (i <= mid) temp[k++] = arr[i++];
    while (j <= high) temp[k++] = arr[j++];
    for (i = low, k = 0; i <= high; i++, k++) arr[i] = temp[k];
    return count;
}

int mergeSort(vector<int>& arr, int low, int high) {
    if (low >= high) return 0;
    int mid = (low + high) / 2;
    return mergeSort(arr, low, mid) + mergeSort(arr, mid + 1, high) + merge(arr, low, mid, high);
}

int countInversions(vector<int>& arr) {
    return mergeSort(arr, 0, arr.size() - 1);
}

int main() {
    vector<int> arr = {2, 4, 1, 3, 5};
    cout << countInversions(arr);
}
