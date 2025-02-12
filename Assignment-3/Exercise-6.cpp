// EXERCISE: 6
// Given a string str of length N which consists of only 0, 1 or 2s, count the number of substring which have equal number of 0s, 1s and 2s. 

// Constraints:
// 1 ≤ N ≤ 105

// Solution

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int countSubstrings(string str) {
    int n = str.length();
    unordered_map<string, int> freq;
    int count = 0, diff0 = 0, diff1 = 0;
    freq["0,0"] = 1;
    for (int i = 0; i < n; i++) {
        if (str[i] == '0') diff0++;
        else if (str[i] == '1') diff1++;
        else diff0--, diff1--;
        string key = to_string(diff0) + "," + to_string(diff1);
        count += freq[key];
        freq[key]++;
    }
    return count;
}

int main() {
    string str;
    cin >> str;
    cout << countSubstrings(str) << endl;
    return 0;
}