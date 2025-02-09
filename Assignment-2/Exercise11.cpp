// EXERCISE: 11
// Given a step array arr[], its step value k, and a key x, we need to find the index of key x in the array arr[]. If multiple occurrences of key x exist, return the first occurrence of the key. In case of no occurrence of key x exists return -1.
// Note: A step array is an array of integers where the difference between adjacent elements is at most k. For example: arr[] = [4, 6, 7, 9] and k = 2 is a step array as the difference between the adjacent elements in the arr[] is at most 2.

// Solution

#include <iostream>
#include <vector>

using namespace std;

int findInStepArray(vector<int>& arr, int k, int x) {
    int i = 0;
    while (i < arr.size()) {
        if (arr[i] == x) return i;
        i += max(1, abs(arr[i] - x) / k);
    }
    return -1;
}

int main() {
    vector<int> arr = {4, 6, 7, 9, 11, 13};
    int k = 2, x = 9;
    cout << findInStepArray(arr, k, x);
}
