// EXERCISE: 13
// Given the head a linked list, the task is to reverse every k node in the linked list. If the number of nodes is not a multiple of k then the left-out nodes in the end, should be considered as a group and must be reversed.

// Solution

#include <iostream>
using namespace std;

struct Node {
    int val;
    Node* next;
    Node(int x) : val(x), next(nullptr) {}
};

Node* reverseList(Node* head) {
    Node* prev = nullptr;
    Node* curr = head;
    while (curr) {
        Node* nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }
    return prev;
}

Node* reverseKGroup(Node* head, int k) {
    if (!head || k == 1) return head;

    Node* dummy = new Node(0);
    dummy->next = head;
    Node* prevGroupEnd = dummy;
    Node* groupStart = head;
    Node* groupEnd = head;

    int length = 0;
    while (groupEnd) {
        length++;
        groupEnd = groupEnd->next;
    }

    while (length >= k) {
        groupEnd = groupStart;
        for (int i = 1; i < k; ++i) groupEnd = groupEnd->next;

        Node* nextGroupStart = groupEnd->next;
        groupEnd->next = nullptr;

        prevGroupEnd->next = reverseList(groupStart);
        groupStart->next = nextGroupStart;
        prevGroupEnd = groupStart;
        groupStart = nextGroupStart;
        length -= k;
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
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    int k = 3;
    Node* result = reverseKGroup(head, k);
    printList(result);

    return 0;
}
