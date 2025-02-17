// EXERCISE: 11

// Given an encoded string, return its decoded string.
// The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is being repeated exactly k times. Note that k is guaranteed to be a positive integer.
// You may assume that the input string is always valid; there are no extra white spaces, square brackets are well-formed, etc. Furthermore, you may assume that the original data does not contain any digits and that digits are only for those repeat numbers, k. For example, there will not be input like 3a or 2[4].
// The test cases are generated so that the length of the output will never exceed 105.
// Constraints:
// 1 <= s.length <= 30
// s consists of lowercase English letters, digits, and square brackets '[]'.
// s is guaranteed to be a valid input.
// All the integers in s are in the range [1, 300].

// Solution

#include <iostream>
#include <stack>
using namespace std;

string decodeString(string s) {
    stack<string> strStack;
    stack<int> numStack;
    string currStr = "";
    int num = 0;
    
    for (int i = 0; i < s.length(); i++) {
        if (s[i] >= '0' && s[i] <= '9') {
            num = num * 10 + (s[i] - '0');
        } else if (s[i] == '[') {
            numStack.push(num);
            strStack.push(currStr);
            num = 0;
            currStr = "";
        } else if (s[i] == ']') {
            int repeat = numStack.top(); numStack.pop();
            string temp = "";
            for (int j = 0; j < repeat; j++) {
                temp += currStr;
            }
            currStr = strStack.top() + temp; strStack.pop();
        } else {
            currStr += s[i];
        }
    }
    return currStr;
}

int main() {
    string s;
    cout << "Enter encoded string: ";
    cin >> s;
    cout << "Decoded string: " << decodeString(s) << endl;
    return 0;
}
