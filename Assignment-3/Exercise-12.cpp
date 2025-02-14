// EXERCISE: 12

// You are given an integer array nums. The range of a subarray of nums is the difference between the largest and smallest element in the subarray.
// Return the sum of all subarray ranges of nums.
// A subarray is a contiguous non-empty sequence of elements within an array.  
// Constraints:
// 1 <= nums.length <= 1000
// -109 <= nums[i] <= 109

// Solution

#include <iostream>
#include <vector>
using namespace std;

long long subArrayRanges(vector<int>& nums) {
    int n = nums.size();
    long long sum = 0;
    
    for (int i = 0; i < n; i++) {
        int minVal = nums[i], maxVal = nums[i];
        
        for (int j = i; j < n; j++) {
            minVal = min(minVal, nums[j]);
            maxVal = max(maxVal, nums[j]);
            sum += (maxVal - minVal);
        }
    }
    
    return sum;
}

int main() {
    vector<int> nums = {1, 2, 3};
    cout << subArrayRanges(nums) << endl;
    return 0;
}