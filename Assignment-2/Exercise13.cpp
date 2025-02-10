// EXERCISE: 13
// Given three integers  'a' denotes the first term of an arithmetic sequence, 'c' denotes the common difference of an arithmetic sequence and an integer 'b'. you need to tell whether 'b' exists in the arithmetic sequence or not. Return 1 if b is present in the sequence. Otherwise, returns 0. 

// Solution

#include <iostream>

using namespace std;

int checkIfBExistsInSequence(int a, int c, int b) {
    if (c == 0) {
        return a == b ? 1 : 0;
    }
    
    int diff = b - a;
    
    if (diff % c == 0 && diff / c >= 0) {
        return 1;
    }
    
    return 0;
}

int main() {
    int a = 3, c = 5, b = 13;
    cout << checkIfBExistsInSequence(a, c, b);
}
