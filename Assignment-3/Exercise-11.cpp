// EXERCISE: 11

// You are given an array of integers nums (0-indexed) and an integer k.
// The score of a subarray (i, j) is defined as min(nums[i], nums[i+1], ..., nums[j]) * (j - i + 1). A good subarray is a subarray where i <= k <= j.
// Return the maximum possible score of a good subarray
// Constraints:

// 1 <= nums.length <= 105
// 1 <= nums[i] <= 2 * 104
// 0 <= k < nums.length

// Solution

#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int maximumScore(vector<int>& nums, int k) {
    int n = nums.size();
    int left = k, right = k;
    int min_val = nums[k];
    int max_score = min_val;

    while (left > 0 || right < n - 1) {
        if (left == 0) {
            right++;
        } else if (right == n - 1) {
            left--;
        } else if (nums[left - 1] > nums[right + 1]) {
            left--;
        } else {
            right++;
        }
        min_val = min(min_val, min(nums[left], nums[right]));
        max_score = max(max_score, min_val * (right - left + 1));
    }

    return max_score;
}

int main() {
    vector<int> nums = {1, 4, 3, 7, 4, 5};
    int k = 3;
    cout << maximumScore(nums, k) << endl;
    return 0;
}