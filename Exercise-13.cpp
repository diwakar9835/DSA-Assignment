// EXERCISE: 13

// You are given a string s and an integer k, a k duplicate removal consists of choosing k adjacent and equal letters from s and removing them, causing the left and the right side of the deleted substring to concatenate together.
// We repeatedly make k duplicate removals on s until we no longer can.
// Return the final string after all such duplicate removals have been made. It is guaranteed that the answer is unique.
// Constraints:
// 1 <= s.length <= 105
// 2 <= k <= 104
// s only contains lowercase English letters.

// Solution

#include <iostream>
#include <string>
#include <stack>
using namespace std;

string removeDuplicates(string s, int k) {
    stack<pair<char, int>> st;
    for (char c : s) {
        if (!st.empty() && st.top().first == c) {
            st.top().second++;
            if (st.top().second == k) {
                st.pop();
            }
        } else {
            st.push({c, 1});
        }
    }
    string result = "";
    while (!st.empty()) {
        result = string(st.top().second, st.top().first) + result;
        st.pop();
    }
    return result;
}

int main() {
    string s;
    int k;
    cin >> s >> k;
    cout << removeDuplicates(s, k) << endl;
    return 0;
}
