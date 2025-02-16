// EXERCISE: 5

// You're given a binary tree. Your task is to find the size of the largest subtree within this binary tree that also satisfies the properties of a Binary Search Tree (BST). The size of a subtree is defined as the number of nodes it contains.
// Note: A subtree of the binary tree is considered a BST if for every node in that subtree, the left child is less than the node, and the right child is greater than the node, without any duplicate values in the subtree.
// Constraints:
// 1 ≤ number of nodes ≤ 105
// 1 ≤ node->data ≤ 105

// Solution

#include <iostream>
#include <climits>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct BSTInfo {
    int size;
    int minVal;
    int maxVal;
    bool isBST;
};

BSTInfo findLargestBST(TreeNode* root, int& maxSize) {
    if (!root) return {0, INT_MAX, INT_MIN, true};
    BSTInfo left = findLargestBST(root->left, maxSize);
    BSTInfo right = findLargestBST(root->right, maxSize);
    if (left.isBST && right.isBST && root->val > left.maxVal && root->val < right.minVal) {
        int currSize = left.size + right.size + 1;
        maxSize = max(maxSize, currSize);
        return {currSize, min(root->val, left.minVal), max(root->val, right.maxVal), true};
    }
    return {0, 0, 0, false};
}

int largestBSTSubtree(TreeNode* root) {
    int maxSize = 0;
    findLargestBST(root, maxSize);
    return maxSize;
}

int main() {
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(15);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(8);
    root->right->right = new TreeNode(7);
    cout << largestBSTSubtree(root) << endl;
    return 0;
}
