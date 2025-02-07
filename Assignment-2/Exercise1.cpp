// EXERCISE: 1
// Given two arrays arr1[], arr2[], and an integer k. The task is to check if after permuting both arrays in such a way, we get the sum of their corresponding element greater than or equal to k i.e. arr1i + arr2i >= k for all i (from 0 to n-1). Return true if possible, else false.

// Solution

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isPossible(vector<int>& arr1, vector<int>& arr2, int k) {
    sort(arr1.begin(), arr1.end());
    sort(arr2.rbegin(), arr2.rend());

    for (int i = 0; i < arr1.size(); i++) {
        if (arr1[i] + arr2[i] < k)
            return false;
    }
    return true;
}

int main() {
    vector<int> arr1 = {2, 1, 3};
    vector<int> arr2 = {7, 8, 9};
    int k = 10;

    if (isPossible(arr1, arr2, k))
        cout << "True";
    else
        cout << "False";

    return 0;
}
