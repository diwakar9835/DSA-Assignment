// EXERCISE: 7

// Given the root of a binary search tree, and an integer k, return the kth smallest value (1-indexed) of all the values of the nodes in the tree. 
// Constraints:
// The number of nodes in the tree is n.
// 1 <= k <= n <= 104
// 0 <= Node.val <= 104

// Solution

#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        int count = 0, result = 0;
        inorder(root, k, count, result);
        return result;
    }
    
    void inorder(TreeNode* node, int k, int& count, int& result) {
        if (!node) return;
        inorder(node->left, k, count, result);
        count++;
        if (count == k) {
            result = node->val;
            return;
        }
        inorder(node->right, k, count, result);
    }
};

int main() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->left->right = new TreeNode(2);
    root->right = new TreeNode(4);
    
    Solution sol;
    int k = 2;
    cout << sol.kthSmallest(root, k) << endl;
    
    return 0;
}
