// EXERCISE: 9

// Given an integer array nums, return true if there exists a triple of indices (i, j, k) such that i < j < k and nums[i] < nums[j] < nums[k]. If no such indices exists, return false. 		
// Constraints:
// 1 <= nums.length <= 5 * 105
// -231 <= nums[i] <= 231 - 1

// Solution

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

bool increasingTriplet(vector<int>& nums) {
    int first = INT_MAX, second = INT_MAX;
    
    for (int num : nums) {
        if (num <= first) {
            first = num;
        } else if (num <= second) {
            second = num;
        } else {
            return true;
        }
    }
    return false;
}

int main() {
    vector<int> nums = {1, 2, 3, 4, 5};
    cout << (increasingTriplet(nums) ? "true" : "false") << endl;
    
    vector<int> nums2 = {5, 4, 3, 2, 1};
    cout << (increasingTriplet(nums2) ? "true" : "false") << endl;
    
    vector<int> nums3 = {2, 1, 5, 0, 4, 6};
    cout << (increasingTriplet(nums3) ? "true" : "false") << endl;
    
    return 0;
}
