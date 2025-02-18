// EXERCISE: 14

// You are given n identical eggs and you have access to a k-floored building from 1 to k.
// There exists a floor f where 0 <= f <= k such that any egg dropped from a floor higher than f will break, and any egg dropped from or below floor f will not break.
// There are few rules given below. 
// An egg that survives a fall can be used again.
// A broken egg must be discarded.
// The effect of a fall is the same for all eggs.
// If the egg doesn't break at a certain floor, it will not break at any floor below.
// If the egg breaks on a certain floor, it will break on any floor above.
// Return the minimum number of moves you need to determine the value of f with certainty. 
// Constraints:
// 1<= n <=100
// 1<= k <=100

// Solution

#include <iostream>
using namespace std;

int eggDrop(int n, int k) {
    int dp[n + 1][k + 1];
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= k; j++) {
            if (j == 0 || j == 1) {
                dp[i][j] = j;
            } else if (i == 1) {
                dp[i][j] = j;
            } else {
                int minAttempts = k;
                for (int x = 1; x <= j; x++) {
                    int attempts = 1 + max(dp[i - 1][x - 1], dp[i][j - x]);
                    if (attempts < minAttempts) {
                        minAttempts = attempts;
                    }
                }
                dp[i][j] = minAttempts;
            }
        }
    }
    return dp[n][k];
}

int main() {
    int n, k;
    cin >> n >> k;
    cout << eggDrop(n, k) << endl;
    return 0;
}
