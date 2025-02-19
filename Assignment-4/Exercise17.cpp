// EXERCISE: 17

// Given an array arr[] and a target, your task is to find all unique combinations in the array where the sum is equal to target. The same number may be chosen from the array any number of times to make target. 
// You can return your answer in any order.
// Constraints:
// 1 <= arr.size() <= 30
// 2 <= arr[i] <= 40
// 2 <= target <= 40
// All arr[i] are distinct.

// Solution

#include <iostream>
#include <vector>
using namespace std;

void findCombinations(vector<int> &arr, int target, int index, vector<int> &current, vector<vector<int>> &result) {
    if (target == 0) {
        result.push_back(current);
        return;
    }
    for (int i = index; i < arr.size(); i++) {
        if (arr[i] <= target) {
            current.push_back(arr[i]);
            findCombinations(arr, target - arr[i], i, current, result);
            current.pop_back();
        }
    }
}

vector<vector<int>> combinationSum(vector<int> &arr, int target) {
    vector<vector<int>> result;
    vector<int> current;
    findCombinations(arr, target, 0, current, result);
    return result;
}

int main() {
    int n, target;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cin >> target;
    vector<vector<int>> result = combinationSum(arr, target);
    for (auto &comb : result) {
        for (int num : comb) {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}
