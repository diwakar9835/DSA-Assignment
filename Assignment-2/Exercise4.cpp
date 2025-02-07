// EXERCISE: 4

// You are given an array arr[] of integers, where each element arr[i] represents the number of pages in the ith book. You also have an integer k representing the number of students. The task is to allocate books to each student such that: 

// Each student receives atleast one book.
// Each student is assigned a contiguous sequence of books.
// No book is assigned to more than one student.
// The objective is to minimize the maximum number of pages assigned to any student. In other words, out of all possible allocations, find the arrangement where the student who receives the most pages still has the smallest possible maximum.
// Note: Return -1 if a valid assignment is not possible, and allotment should be in contiguous order (see the explanation for better understanding).

// Solution

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

bool isPossible(vector<int>& books, int students, int maxPages) {
    int count = 1, sum = 0;
    for (int pages : books) {
        if (sum + pages > maxPages) {
            count++;
            sum = pages;
            if (count > students) return false;
        } else sum += pages;
    }
    return true;
}

int allocateBooks(vector<int>& books, int students) {
    if (books.size() < students) return -1;
    int low = *max_element(books.begin(), books.end());
    int high = accumulate(books.begin(), books.end(), 0);
    int result = -1;
    
    while (low <= high) {
        int mid = (low + high) / 2;
        if (isPossible(books, students, mid)) {
            result = mid;
            high = mid - 1;
        } else low = mid + 1;
    }
    return result;
}

int main() {
    vector<int> books = {12, 34, 67, 90};
    int students = 2;
    cout << allocateBooks(books, students);
}
