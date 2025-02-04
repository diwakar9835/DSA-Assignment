// EXERCISE: 11
// Given the head of two singly linked lists num1 and num2 representing two non-negative integers. The task is to return the head of the linked list representing the sum of these two numbers.

// Solution

#include <iostream>
using namespace std;

struct Node {
    int val;
    Node* next;
    Node(int x) : val(x), next(nullptr) {}
};

Node* addTwoLists(Node* num1, Node* num2) {
    Node* dummy = new Node(0);
    Node* current = dummy;
    int carry = 0;

    while (num1 || num2 || carry) {
        int sum = carry;
        if (num1) {
            sum += num1->val;
            num1 = num1->next;
        }
        if (num2) {
            sum += num2->val;
            num2 = num2->next;
        }
        carry = sum / 10;
        current->next = new Node(sum % 10);
        current = current->next;
    }

    return dummy->next;
}

void printList(Node* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Node* num1 = new Node(2);
    num1->next = new Node(4);
    num1->next->next = new Node(3);

    Node* num2 = new Node(5);
    num2->next = new Node(6);
    num2->next->next = new Node(4);

    Node* result = addTwoLists(num1, num2);
    printList(result);

    return 0;
}
