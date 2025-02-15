// EXERCISE: 2

// Given an array of strings, return all groups of strings that are anagrams. The strings in each group must be arranged in the order of their appearance in the original array. Refer to the sample case for clarification. 	
// Constraints:
// 1<= arr.size() <=100
// 1<= arr[i].size() <=10


// Solution

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& arr) {
    unordered_map<string, vector<string>> anagramGroups;
    vector<vector<string>> result;
    
    for (string& str : arr) {
        string sortedStr = str;
        sort(sortedStr.begin(), sortedStr.end());
        anagramGroups[sortedStr].push_back(str);
    }
    
    for (auto& group : arr) {
        string sortedStr = group;
        sort(sortedStr.begin(), sortedStr.end());
        if (anagramGroups.count(sortedStr)) {
            result.push_back(anagramGroups[sortedStr]);
            anagramGroups.erase(sortedStr);
        }
    }
    
    return result;
}

int main() {
    vector<string> arr = {"cat", "dog", "tac", "god", "act"};
    vector<vector<string>> anagrams = groupAnagrams(arr);
    
    for (auto& group : anagrams) {
        for (auto& word : group) {
            cout << word << " ";
        }
        cout << endl;
    }
    
    return 0;
}
