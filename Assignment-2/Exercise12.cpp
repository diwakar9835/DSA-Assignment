// EXERCISE: 12
// Given an array arr[] of integers and another integer target. Find all unique quadruples from the given array that sums up to target. 7 marks
// Note: All the quadruples should be internally sorted, ie for any quadruple [q1, q2, q3, q4] it should be : q1 <= q2 <= q3 <= q4.

// Solution

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> fourSum(vector<int>& arr, int target) {
    vector<vector<int>> result;
    sort(arr.begin(), arr.end());
    
    for (int i = 0; i < arr.size() - 3; i++) {
        if (i > 0 && arr[i] == arr[i - 1]) continue;
        for (int j = i + 1; j < arr.size() - 2; j++) {
            if (j > i + 1 && arr[j] == arr[j - 1]) continue;
            
            int left = j + 1, right = arr.size() - 1;
            while (left < right) {
                int sum = arr[i] + arr[j] + arr[left] + arr[right];
                if (sum == target) {
                    result.push_back({arr[i], arr[j], arr[left], arr[right]});
                    while (left < right && arr[left] == arr[left + 1]) left++;
                    while (left < right && arr[right] == arr[right - 1]) right--;
                    left++;
                    right--;
                } else if (sum < target) {
                    left++;
                } else {
                    right--;
                }
            }
        }
    }
    return result;
}

int main() {
    vector<int> arr = {1, 0, -1, 0, -2, 2};
    int target = 0;
    vector<vector<int>> res = fourSum(arr, target);
    
    for (const auto& quad : res) {
        for (int num : quad) {
            cout << num << " ";
        }
        cout << endl;
    }
}
