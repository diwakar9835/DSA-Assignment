// EXERCISE: 1
// As the ruler of a kingdom, you have an army of wizards at your command.
// You are given a 0-indexed integer array strength, where strength[i] denotes the strength of the ith wizard. For a contiguous group of wizards (i.e. the wizards' strengths form a subarray of strength), the total strength is defined as the product of the following two values:
// The strength of the weakest wizard in the group.
// The total of all the individual strengths of the wizards in the group.
// Return the sum of the total strengths of all contiguous groups of wizards. Since the answer may be very large, return it modulo 109 + 7.
// A subarray is a contiguous non-empty sequence of elements within an array.

// Constraints:
// 1 <= strength.length <= 105
// 1 <= strength[i] <= 109


// Solution

#include <vector>
#include <stack>
#include <algorithm>
#include <iostream>
using namespace std;

const int MOD = 1e9 + 7;

int totalStrength(vector<int>& strength) {
    int n = strength.size();
    vector<long long> prefix(n + 1, 0), prefixPrefix(n + 2, 0);
    for (int i = 0; i < n; ++i) {
        prefix[i + 1] = (prefix[i] + strength[i]) % MOD;
    }
    for (int i = 0; i <= n; ++i) {
        prefixPrefix[i + 1] = (prefixPrefix[i] + prefix[i]) % MOD;
    }

    stack<int> st;
    vector<int> left(n, -1), right(n, n);
    for (int i = 0; i < n; ++i) {
        while (!st.empty() && strength[st.top()] >= strength[i]) {
            st.pop();
        }
        if (!st.empty()) {
            left[i] = st.top();
        }
        st.push(i);
    }

    st = stack<int>();
    for (int i = n - 1; i >= 0; --i) {
        while (!st.empty() && strength[st.top()] > strength[i]) {
            st.pop();
        }
        if (!st.empty()) {
            right[i] = st.top();
        }
        st.push(i);
    }

    long long result = 0;
    for (int i = 0; i < n; ++i) {
        int l = left[i] + 1, r = right[i] - 1;
        long long total = (prefixPrefix[r + 2] - prefixPrefix[i + 1]) * (i - l + 1) % MOD;
        total = (total - (prefixPrefix[i + 1] - prefixPrefix[l]) * (r - i + 1) % MOD + MOD) % MOD;
        result = (result + strength[i] * total) % MOD;
    }

    return result;
}

int main() {
    vector<int> strength = {1, 3, 1, 2};

    int result = totalStrength(strength);

    cout << "Sum of total strengths: " << result << endl;

    return 0;
}