// EXERCISE: 13

// Given a string s and a dictionary of n words dictionary, find out if "s" can be segmented into a space-separated sequence of dictionary words.
// Return 1 if it is possible to break the s into a sequence of dictionary words, else return 0. 
// Note: From the dictionary,  dictionary each word can be taken any number of times and in any order. 		
// Constraints:
// 1 ≤ n ≤ 12
// 1 ≤ len(s) ≤ 1100

// Solution

#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

int wordBreak(string s, vector<string>& dictionary) {
    unordered_set<string> dict(dictionary.begin(), dictionary.end());
    int n = s.length();
    vector<bool> dp(n + 1, false);
    dp[0] = true;

    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (dp[j] && dict.find(s.substr(j, i - j)) != dict.end()) {
                dp[i] = true;
                break;
            }
        }
    }

    return dp[n] ? 1 : 0;
}

int main() {
    string s = "leetcode";
    vector<string> dictionary = {"leet", "code"};
    cout << wordBreak(s, dictionary) << endl;
    return 0;
}