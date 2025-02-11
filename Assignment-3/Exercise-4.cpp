// EXERCISE: 4
// You are given an array heights of n integers representing the number of bricks in n consecutive towers. Your task is to remove some bricks to form a mountain-shaped tower arrangement. In this arrangement, the tower heights are non-decreasing, reaching a maximum peak value with one or multiple consecutive towers and then non-increasing. 	
// Return the maximum possible sum of heights of a mountain-shaped tower arrangement.

// Constraints:
// 1 <= n == heights.length <= 103
// 1 <= heights[i] <= 109

// Solution

#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int maxMountainSum(vector<int>& heights) {
    int n = heights.size();
    vector<int> left(n, 0), right(n, 0);

    for (int i = 1; i < n; i++) {
        if (heights[i] >= heights[i-1]) {
            left[i] = left[i-1] + heights[i];
        } else {
            left[i] = heights[i];
        }
    }

    for (int i = n-2; i >= 0; i--) {
        if (heights[i] >= heights[i+1]) {
            right[i] = right[i+1] + heights[i];
        } else {
            right[i] = heights[i];
        }
    }

    int maxSum = 0;
    for (int i = 0; i < n; i++) {
        maxSum = max(maxSum, left[i] + right[i] - heights[i]);
    }

    return maxSum;
}

int main() {
    vector<int> heights = {2, 3, 5, 4, 6, 7, 5, 4, 3};
    int result = maxMountainSum(heights);
    cout << "Maximum mountain sum: " << result << endl;
    return 0;
}