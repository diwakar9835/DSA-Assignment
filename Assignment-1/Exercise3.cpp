// EXERCISE: 3
// Given two sorted arrays a[] and b[], where each array may contain duplicate elements , the task is to return the elements in the union of the two arrays in sorted order. 
// Union of two arrays can be defined as the set containing distinct common elements that are present in either of the arrays.

// Solution

#include <iostream>
using namespace std;

void findUnion(int a[], int n, int b[], int m) {
    int i = 0, j = 0;

    while (i < n && j < m) {
        if (i > 0 && a[i] == a[i - 1]) {
            i++;
            continue;
        }
        if (j > 0 && b[j] == b[j - 1]) {
            j++;
            continue;
        }

        if (a[i] < b[j]) {
            cout << a[i] << " ";
            i++;
        } else if (a[i] > b[j]) {
            cout << b[j] << " ";
            j++;
        } else {
            cout << a[i] << " ";
            i++;
            j++;
        }
    }

    while (i < n) {
        if (i == 0 || a[i] != a[i - 1]) {
            cout << a[i] << " ";
        }
        i++;
    }

    while (j < m) {
        if (j == 0 || b[j] != b[j - 1]) {
            cout << b[j] << " ";
        }
        j++;
    }
}

int main() {
    int a[] = {1, 2, 2, 3, 4, 5};
    int b[] = {2, 3, 5, 6};
    int n = sizeof(a) / sizeof(a[0]);
    int m = sizeof(b) / sizeof(b[0]);

    cout << "Union of the arrays: ";
    findUnion(a, n, b, m);
    cout << endl;

    return 0;
}
