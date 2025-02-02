//  EXERCISE: 6

// Given an array arr containing both positive and negative integers, the task is to compute the length of the largest subarray that has a sum of 0. 7 marks

// Solution

#include <iostream>
#include <unordered_map>
using namespace std;

int largestSubarrayWithSumZero(int arr[], int n) {
    unordered_map<int, int> sum_map;
    int max_len = 0;
    int prefix_sum = 0;

    for (int i = 0; i < n; i++) {
        prefix_sum += arr[i];

        if (prefix_sum == 0) {
            max_len = i + 1;
        }

        if (sum_map.find(prefix_sum) != sum_map.end()) {
            max_len = max(max_len, i - sum_map[prefix_sum]);
        } else {
            sum_map[prefix_sum] = i;
        }
    }

    return max_len;
}

int main() {
    int arr[] = {15, -2, 2, -8, 1, 7, 10, 23};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    int result = largestSubarrayWithSumZero(arr, n);
    cout << "Length of the largest subarray with sum 0 is: " << result << endl;

    return 0;
}
