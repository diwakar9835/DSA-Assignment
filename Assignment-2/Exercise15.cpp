// EXERCISE: 15
// Given three integers M, N and K. Consider a grid of M * N, where mat[i][j] = i * j (1 based index). The task is to return the Kth smallest element in the M * N multiplication table.


// Solution

#include <iostream>
#include <algorithm>

using namespace std;

int countLessEqual(int M, int N, int X) {
    int count = 0;
    for (int i = 1; i <= M; ++i) {
        count += min(X / i, N);
    }
    return count;
}

int findKthSmallest(int M, int N, int K) {
    int left = 1, right = M * N;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (countLessEqual(M, N, mid) < K) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return left;
}

int main() {
    int M = 3, N = 3, K = 5;
    cout << "The " << K << "th smallest element is: " << findKthSmallest(M, N, K) << endl;
    return 0;
}
