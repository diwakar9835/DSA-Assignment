// EXERCISE: 15

// Given an array arr[] of N integers. Find the contiguous sub-array(containing at least one number) which has the minimum sum and return its sum
// Your Task:
// You don't need to read input or print anything. The task is to complete the function smallestSubarraySum() which takes arr[] and N as input parameters and returns the sum of subarray with minimum sum.
// Expected Time Complexity: O(N)
// Expected Auxiliary Space: O(1)
// Constraints:
// 1 ≤ N ≤ 106
// -107 ≤ A[i] ≤ 107

// Solution

#include <iostream>
using namespace std;

typedef long long ll;

ll smallestSubarraySum(ll arr[], int N) {
    ll minSum = arr[0], currentSum = arr[0];
    for (int i = 1; i < N; i++) {
        currentSum = min(arr[i], currentSum + arr[i]);
        minSum = min(minSum, currentSum);
    }
    return minSum;
}

int main() {
    int N;
    cin >> N;
    ll arr[N];
    for (int i = 0; i < N; i++) cin >> arr[i];
    cout << smallestSubarraySum(arr, N) << endl;
    return 0;
}
