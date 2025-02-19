// EXERCISE: 18

// Given a String S, Find all possible Palindromic partitions of the given String.
// Your Task:
// You don't need to read input or print anything. Your task is to complete the function allPalindromicPerms() which takes a String S as input parameter and returns a list of lists denoting all the possible palindromic partitions in the order of their appearance in the original string.
// Expected Time Complexity: O(N*2N)
// Expected Auxiliary Space: O(N2), where N is the length of the String
// Constraints:
// 1 <= |S| <= 20

// Solution

#include <iostream>
#include <vector>
using namespace std;

bool isPalindrome(string s, int start, int end) {
    while (start < end) {
        if (s[start] != s[end]) return false;
        start++;
        end--;
    }
    return true;
}

void findPartitions(string &s, int index, vector<string> &current, vector<vector<string>> &result) {
    if (index == s.length()) {
        result.push_back(current);
        return;
    }
    for (int i = index; i < s.length(); i++) {
        if (isPalindrome(s, index, i)) {
            current.push_back(s.substr(index, i - index + 1));
            findPartitions(s, i + 1, current, result);
            current.pop_back();
        }
    }
}

vector<vector<string>> allPalindromicPerms(string S) {
    vector<vector<string>> result;
    vector<string> current;
    findPartitions(S, 0, current, result);
    return result;
}

int main() {
    string S;
    cin >> S;
    vector<vector<string>> partitions = allPalindromicPerms(S);
    for (auto &partition : partitions) {
        for (auto &p : partition) {
            cout << p << " ";
        }
        cout << endl;
    }
    return 0;
}
