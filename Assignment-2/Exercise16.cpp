// EXERCISE: 16
// Given a positive number n and a number d.  Find the count of positive numbers smaller or equal to  n such that the difference between the number and sum of its digits is greater than or equal to given specific value d.  

// Solution

#include <iostream>

using namespace std;

int sumOfDigits(int num) {
    int sum = 0;
    while (num > 0) {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

int countNumbers(int n, int d) {
    int count = 0;
    for (int i = 1; i <= n; ++i) {
        if (i - sumOfDigits(i) >= d) {
            ++count;
        }
    }
    return count;
}

int main() {
    int n = 20, d = 10;
    cout << "Count of numbers satisfying the condition: " << countNumbers(n, d) << endl;
    return 0;
}
