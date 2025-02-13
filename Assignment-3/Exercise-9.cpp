//EXERCISE: 9

// Given an array of strings (all lowercase letters), the task is to group them in such a way that all strings in a group are shifted versions of each other. 		
// Two strings s1 and s2 are called shifted if the following conditions are satisfied:
// s1.length = s2.length
// s1[i] = s2[i] + m for 1 <= i <= s1.length  for a constant integer m
// Constraints:
// 1 ≤ arr.size() ≤ 105
// 1 ≤ arr[i].size() ≤ 5

// Solution

#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

string getKey(string s) {
    string key = "";
    for (int i = 1; i < s.size(); i++) {
        int diff = (s[i] - s[i - 1] + 26) % 26;
        key += to_string(diff) + ",";
    }
    return key;
}

vector<vector<string>> groupShiftedStrings(vector<string>& arr) {
    unordered_map<string, vector<string>> groups;
    for (string s : arr) {
        groups[getKey(s)].push_back(s);
    }
    vector<vector<string>> result;
    for (auto it : groups) {
        result.push_back(it.second);
    }
    return result;
}

int main() {
    vector<string> arr = {"abc", "bcd", "xyz", "yza", "ace", "bdf"};
    vector<vector<string>> result = groupShiftedStrings(arr);
    for (auto group : result) {
        for (string s : group) {
            cout << s << " ";
        }
        cout << endl;
    }
    return 0;
}
