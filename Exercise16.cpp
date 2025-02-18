// EXERCISE: 16
// Given a string s, which may contain duplicate characters, your task is to generate and return an array of all unique permutations of the string. You can return your answer in any order. 
// Constraints:
// 1 <= s.size() <= 9
// s contains only Uppercase english alphabets

// Solution

#include <iostream>
#include <vector>
#include <set>
using namespace std;

void permute(string &s, int l, int r, set<string> &unique_perms) {
    if (l == r) {
        unique_perms.insert(s);
        return;
    }
    for (int i = l; i <= r; i++) {
        swap(s[l], s[i]);
        permute(s, l + 1, r, unique_perms);
        swap(s[l], s[i]);
    }
}

vector<string> getUniquePermutations(string s) {
    set<string> unique_perms;
    permute(s, 0, s.size() - 1, unique_perms);
    return vector<string>(unique_perms.begin(), unique_perms.end());
}

int main() {
    string s;
    cin >> s;
    vector<string> result = getUniquePermutations(s);
    for (string &perm : result) {
        cout << perm << "\n";
    }
    return 0;
}