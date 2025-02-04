// EXERCISE: 8
// Given the head of a linked list, rotate the list to the right by k places.
// -----------------------------------------------------------------------------------------------

// Solution

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* rotateRight(ListNode* head, int k) {
    if (!head || !head->next || k == 0) return head;

    int len = 1;
    ListNode* tail = head;
    while (tail->next) {
        len++;
        tail = tail->next;
    }

    tail->next = head;

    k = k % len;
    if (k == 0) {
        tail->next = nullptr;
        return head;
    }

    ListNode* newTail = head;
    for (int i = 1; i < len - k; i++) {
        newTail = newTail->next;
    }

    ListNode* newHead = newTail->next;
    newTail->next = nullptr;

    return newHead;
}

void printList(ListNode* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    int k = 2;

    head = rotateRight(head, k);
    printList(head);

    return 0;
}
