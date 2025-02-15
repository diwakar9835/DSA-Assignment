// EXERCISE: 4

// Given a Binary Tree, return the diagonal traversal of the binary tree.
// Consider lines of slope -1 passing between nodes. Given a Binary Tree, return a single list containing all diagonal elements in a binary tree belonging to same line.
// If the diagonal element are present in two different subtrees then left subtree diagonal element should be taken first and then right subtree.
// Constraints: 
// 1 <= number of nodes<= 105 1 <= node->data <= 105	

// Solution

#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

vector<int> diagonalTraversal(Node* root) {
    vector<int> result;
    if (!root) return result;
    map<int, vector<int>> diagonalMap;
    queue<pair<Node*, int>> q;
    q.push({root, 0});
    while (!q.empty()) {
        auto it = q.front();
        q.pop();
        Node* node = it.first;
        int d = it.second;
        diagonalMap[d].push_back(node->data);
        if (node->left) q.push({node->left, d + 1});
        if (node->right) q.push({node->right, d});
    }
    for (auto& entry : diagonalMap) {
        for (int val : entry.second) {
            result.push_back(val);
        }
    }
    return result;
}

int main() {
    Node* root = new Node(8);
    root->left = new Node(3);
    root->right = new Node(10);
    root->left->left = new Node(1);
    root->left->right = new Node(6);
    root->right->right = new Node(14);
    root->right->right->left = new Node(13);
    root->left->right->left = new Node(4);
    root->left->right->right = new Node(7);
    vector<int> result = diagonalTraversal(root);
    for (int val : result) {
        cout << val << " ";
    }
    return 0;
}