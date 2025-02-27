// EXERCISE: 1

// Given two strings A and B. Find the minimum number of steps required to transform string A into string B. The only allowed operation for the transformation is selecting a character from string A and inserting it in the beginning of string A.
// Your Task: 
// You dont need to read input or print anything. Complete the function transform() which takes two strings A and B as input parameters and returns the minimum number of steps required to transform A into B. If transformation is not possible return -1.
// Expected Time Complexity: O(N) where N is max(length of A, length of B) 
// Expected Auxiliary Space: O(1)  
// Constraints:
// 1<= A.length(), B.length() <= 104

// Solution

#include <bits/stdc++.h>
using namespace std;

int transform(string A, string B) {
    int n = A.length(), m = B.length();
    if (n != m) return -1;
    vector<int> freq(256, 0);
    for (char c : A) freq[c]++;
    for (char c : B) freq[c]--;
    for (int i : freq) if (i != 0) return -1;
    int i = n - 1, j = n - 1, moves = 0;
    while (i >= 0) {
        if (A[i] == B[j]) j--;
        else moves++;
        i--;
    }
    return moves;
}

int main() {
    string A = "abcd", B = "bcda";
    cout << transform(A, B) << endl;
    return 0;
}
