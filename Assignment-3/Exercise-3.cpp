// EXERCISE: 3
// You are given a 0-indexed integer array nums. In one step, remove all elements nums[i] where nums[i - 1] > nums[i] for all 0 < i < nums.length. 				
// Return the number of steps performed until nums becomes a non-decreasing array. 

// Constraints:
// 1 <= nums.length <= 105
// 1 <= nums[i] <= 109

// Solution

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int totalSteps(vector<int>& nums) {
    stack<pair<int, int>> st;
    int max_steps = 0;
    
    for (int i = nums.size() - 1; i >= 0; --i) {
        int count = 0;
        while (!st.empty() && st.top().first < nums[i]) {
            count = max(count + 1, st.top().second);
            st.pop();
        }
        st.push({nums[i], count});
        max_steps = max(max_steps, count);
    }
    
    return max_steps;
}

int main() {
    vector<int> nums = {5, 3, 4, 6, 2, 7};
    cout << totalSteps(nums) << endl;
    return 0;
}
