// EXERCISE: 7
// Given an array arr[] of distinct elements. Find the minimum number of swaps required to sort the array in strictly increasing order.

// Solution

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int minSwaps(vector<int>& arr) {
    vector<pair<int, int>> sortedArr;
    for (int i = 0; i < arr.size(); i++) sortedArr.push_back({arr[i], i});
    sort(sortedArr.begin(), sortedArr.end());
    vector<bool> visited(arr.size(), false);
    int swaps = 0;
    for (int i = 0; i < arr.size(); i++) {
        if (visited[i] || sortedArr[i].second == i) continue;
        int cycle = 0, j = i;
        while (!visited[j]) {
            visited[j] = true;
            j = sortedArr[j].second;
            cycle++;
        }
        swaps += (cycle - 1);
    }
    return swaps;
}

int main() {
    vector<int> arr = {4, 3, 2, 1};
    cout << minSwaps(arr);
}
