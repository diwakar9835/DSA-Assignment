// EXERCISE: 7
// Given an integer array nums and an integer k, return the number of non-empty subarrays that have a sum divisible by k.  

// Constraints:
// 1 <= nums.length <= 3 * 104
// -104 <= nums[i] <= 104
// 2 <= k <= 104

// Solution

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int subarraysDivByK(vector<int>& nums, int k) {
    unordered_map<int, int> remainderCount;
    remainderCount[0] = 1;
    int sum = 0, count = 0;
    for (int num : nums) {
        sum += num;
        int remainder = sum % k;
        if (remainder < 0) remainder += k;
        count += remainderCount[remainder];
        remainderCount[remainder]++;
    }
    return count;
}

int main() {
    vector<int> nums = {4, 5, 0, -2, -3, 1};
    int k = 5;
    cout << subarraysDivByK(nums, k) << endl;
    return 0;
}
