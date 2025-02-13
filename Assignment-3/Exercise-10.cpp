// EXERCISE: 10

// Given an input stream s consisting only of lowercase alphabets. While reading characters from the stream, you have to tell which character has appeared only once in the stream upto that point. If there are many characters that have appeared only once, you have to tell which one of them was the first one to appear. If there is no such character then append '#' to the answer.  								
// NOTE:
// 1. You need to find the answer for every i (0 <= i < n)
// 2. In order to find the solution for every you need to consider the string from starting position till the ith position.

// Constraints:
// 1 <= s.size()<= 105
// 'a' <= s[i] <= 'z'

// Solution

#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

string firstUniqueCharacter(string s) {
    unordered_map<char, int> freq;
    queue<char> q;
    string result = "";
    
    for (char ch : s) {
        freq[ch]++;
        if (freq[ch] == 1) q.push(ch);
        
        while (!q.empty() && freq[q.front()] > 1) q.pop();
        
        result += q.empty() ? '#' : q.front();
    }
    return result;
}

int main() {
    string s;
    cin >> s;
    cout << firstUniqueCharacter(s) << endl;
    return 0;
}
