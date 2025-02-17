// EXERCISE: 12

// A digit string is good if the digits (0-indexed) at even indices are even and the digits at odd indices are prime (2, 3, 5, or 7).  
// For example, "2582" is good because the digits (2 and 8) at even positions are even and the digits (5 and 2) at odd positions are prime. However, "3245" is not good because 3 is at an even index but is not even.
// Given an integer n, return the total number of good digit strings of length n. Since the answer may be large, return it modulo 109 + 7.
// A digit string is a string consisting of digits 0 through 9 that may contain leading zeros.
// Constraints:
// 1 <= n <= 1015

// Solution

#include <iostream>
using namespace std;

const int MOD = 1e9 + 7;

long long modPow(long long base, long long exp, long long mod) {
    long long result = 1;
    base = base % mod;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp = exp / 2;
    }
    return result;
}

int countGoodStrings(long long n) {
    long long evenChoices = 5;
    long long oddChoices = 4;

    long long evenCount = (n + 1) / 2;
    long long oddCount = n / 2;

    long long total = (modPow(evenChoices, evenCount, MOD) * modPow(oddChoices, oddCount, MOD)) % MOD;
    return total;
}

int main() {
    long long n;
    cout << "Enter the length of the digit string: ";
    cin >> n;

    int result = countGoodStrings(n);
    cout << "Total number of good digit strings of length " << n << " is: " << result << endl;

    return 0;
}