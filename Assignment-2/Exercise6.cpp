// EXERCISE: 6
// Farmer John has built a new long barn, with N (2 <= N <= 100,000) stalls. The stalls are located along a straight line at positions x1 ... xN (0 <= xi <= 1,000,000,000).   
// His C (2 <= C <= N) cows don't like this barn layout and become aggressive towards each other once put into a stall. To prevent the cows from hurting each other, FJ wants to assign the cows to the stalls, such that the minimum distance between any two of them is as large as possible. What is the largest minimum distance
// Input:
// t – the number of test cases, then t test cases follows.
// * Line 1: Two space-separated integers: N and C
// * Lines 2..N+1: Line i+1 contains an integer stall location, xi
// Output: For each test case output one integer: the largest minimum distance.

// Solution

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isPossible(vector<int>& stalls, int cows, int dist) {
    int count = 1, lastPos = stalls[0];
    for (int i = 1; i < stalls.size(); i++) {
        if (stalls[i] - lastPos >= dist) {
            count++;
            lastPos = stalls[i];
            if (count == cows) return true;
        }
    }
    return false;
}

int maxMinDistance(vector<int>& stalls, int cows) {
    sort(stalls.begin(), stalls.end());
    int low = 1, high = stalls.back() - stalls[0], res = -1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (isPossible(stalls, cows, mid)) {
            res = mid;
            low = mid + 1;
        } else high = mid - 1;
    }
    return res;
}

int main() {
    vector<int> stalls = {1, 2, 8, 4, 9};
    int cows = 3;
    cout << maxMinDistance(stalls, cows);
}
