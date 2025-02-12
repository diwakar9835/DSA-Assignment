// EXERCISE: 5
// You are given an array of positive integers nums.
// Return the number of subarrays of nums, where the first and the last elements of the subarray are equal to the largest element in the subarray. 		

// Constraints:
// 1 <= nums.length <= 105
// 1 <= nums[i] <= 109

// Solution

#include <vector>
#include <stack>
#include <iostream>

using namespace std;

long long countSubarrays(vector<int>& nums) {
    long long result = 0;
    stack<int> st;
    for (int i = 0; i < nums.size(); ++i) {
        while (!st.empty() && nums[st.top()] < nums[i]) {
            st.pop();
        }
        if (!st.empty() && nums[st.top()] == nums[i]) {
            result += st.size();
        }
        st.push(i);
    }
    return result + nums.size();
}

int main() {
    vector<int> nums = {1, 2, 1, 3, 2, 1};
    long long ans = countSubarrays(nums);
    cout << "Number of valid subarrays: " << ans << endl;
    return 0;
}