// EXERCISE: 8

// Given the root of a binary search tree, return a balanced binary search tree with the same node values. If there is more than one answer, return any of them.
// A binary search tree is balanced if the depth of the two subtrees of every node never differs by more than 1.
// Constraints:
// The number of nodes in the tree is in the range [1, 104].
// 1 <= Node.val <= 105

// Solution

#include <vector>
#include <iostream>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void inorder(TreeNode* root, std::vector<int>& nodes) {
    if (!root) return;
    inorder(root->left, nodes);
    nodes.push_back(root->val);
    inorder(root->right, nodes);
}

TreeNode* buildBalancedTree(std::vector<int>& nodes, int start, int end) {
    if (start > end) return nullptr;
    int mid = start + (end - start) / 2;
    TreeNode* root = new TreeNode(nodes[mid]);
    root->left = buildBalancedTree(nodes, start, mid - 1);
    root->right = buildBalancedTree(nodes, mid + 1, end);
    return root;
}

TreeNode* balanceBST(TreeNode* root) {
    std::vector<int> nodes;
    inorder(root, nodes);
    return buildBalancedTree(nodes, 0, nodes.size() - 1);
}

void printInorder(TreeNode* root) {
    if (!root) return;
    printInorder(root->left);
    std::cout << root->val << " ";
    printInorder(root->right);
}

int main() {
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(15);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(7);

    TreeNode* balancedRoot = balanceBST(root);
    std::cout << "Balanced BST Inorder: ";
    printInorder(balancedRoot);
    std::cout << std::endl;
    return 0;
}
