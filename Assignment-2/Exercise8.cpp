// EXERCISE: 8
// Given an array of integers, sort the array (in descending order) according to count of set bits in binary representation of array elements.
// Note: For integers having same number of set bits in their binary representation, sort according to their position in the original array i.e., a stable sort.

// Solution

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int countSetBits(int n) {
    return __builtin_popcount(n);
}

bool compare(int a, int b) {
    int countA = countSetBits(a);
    int countB = countSetBits(b);
    return countA > countB;
}

void sortBySetBits(vector<int>& arr) {
    stable_sort(arr.begin(), arr.end(), compare);
}

int main() {
    vector<int> arr = {5, 3, 7, 10, 14};
    sortBySetBits(arr);
    for (int num : arr) cout << num << " ";
}
