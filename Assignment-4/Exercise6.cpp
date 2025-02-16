// EXERCISE: 6

// Given a Binary Search Tree (with all values unique) and two nodes n1 and n2 (n1 != n2). You may assume that both nodes exist in the tree. Find the Lowest Common Ancestor (LCA) of the given two nodes in the BST. 
// LCA between two nodes n1 and n2 is defined as the lowest node that has both n1 and n2 as descendants (where we allow a node to be a descendant of itself).
// Constraints:
// 1 <= number of nodes <= 105
// 1 <= node->data <= 105
// 1 <= n1, n2 <= 105

// Solution

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(NULL), right(NULL) {}
};

Node* insert(Node* root, int val) {
    if (!root) return new Node(val);
    if (val < root->data) root->left = insert(root->left, val);
    else root->right = insert(root->right, val);
    return root;
}

Node* LCA(Node* root, int n1, int n2) {
    while (root) {
        if (root->data > n1 && root->data > n2) root = root->left;
        else if (root->data < n1 && root->data < n2) root = root->right;
        else return root;
    }
    return NULL;
}

int main() {
    Node* root = NULL;
    root = insert(root, 20);
    insert(root, 10);
    insert(root, 30);
    insert(root, 5);
    insert(root, 15);
    insert(root, 25);
    insert(root, 35);
    
    int n1 = 5, n2 = 15;
    Node* lca = LCA(root, n1, n2);
    if (lca) cout << "LCA: " << lca->data << endl;
    
    return 0;
}
