// EXERCISE: 2
// Given an array arr[] of positive integers, where each value represents the number of chocolates in a packet. Each packet can have a variable number of chocolates. There are m students, the task is to distribute chocolate packets among m students such that -
// i. Each student gets exactly one packet.
// ii. The difference between maximum number of chocolates given to a student and minimum number of chocolates given to a student is minimum and return that minimum possible difference. 

// Solution

#include <iostream>
#include <climits>
using namespace std;

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int findMinDifference(int arr[], int n, int m) {
    if (m == 0 || n == 0 || m > n)
        return -1;

    bubbleSort(arr, n);

    int minDiff = INT_MAX;

    for (int i = 0; i + m - 1 < n; i++) {
        int diff = arr[i + m - 1] - arr[i];
        if (diff < minDiff)
            minDiff = diff;
    }

    return minDiff;
}

int main() {
    int arr[] = {12, 4, 7, 9, 2, 23, 25, 41, 30, 40, 28, 42, 30, 44, 48, 43, 50};
    int n = sizeof(arr) / sizeof(arr[0]);
    int m = 7;

    int result = findMinDifference(arr, n, m);
    if (result != -1)
        cout << "Minimum difference is: " << result << endl;
    else
        cout << "Invalid input" << endl;

    return 0;
}
