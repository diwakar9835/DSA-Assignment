// EXERCISE: 3
// Given two sorted arrays a[] and b[] and an element k, the task is to find the element that would be at the kth position of the combined sorted array.

// Solution

#include <iostream>
#include <vector>

using namespace std;

int kthElement(vector<int>& a, vector<int>& b, int k) {
    int i = 0, j = 0, count = 0, result = 0;
    while (i < a.size() && j < b.size()) {
        if (a[i] < b[j]) result = a[i++];
        else result = b[j++];
        if (++count == k) return result;
    }
    while (i < a.size()) {
        result = a[i++];
        if (++count == k) return result;
    }
    while (j < b.size()) {
        result = b[j++];
        if (++count == k) return result;
    }
    return -1;
}

int main() {
    vector<int> a = {2, 3, 6, 7};
    vector<int> b = {1, 4, 8, 10};
    int k = 5;
    cout << kthElement(a, b, k);
}
