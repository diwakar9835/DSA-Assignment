#include <iostream>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
class Solution {
public:

    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (root == nullptr) {
            return new TreeNode(val);
        }
if (val < root->val) {
            root->left = insertIntoBST(root->left, val);
        } else {
            root->right = insertIntoBST(root->right, val);
        }
        return root;
    }
};

void inorderTraversal(TreeNode* root) {
    if (root == nullptr) {
        return;
        
    }

    inorderTraversal(root->left);
    cout << root->val << " ";
    inorderTraversal(root->right);
}

int main() {
    Solution solution;

    // Example 1
    TreeNode* root1 = new TreeNode(4);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(7);
    root1->left->left = new TreeNode(1);
    root1->left->right = new TreeNode(3);
    root1 = solution.insertIntoBST(root1, 5);
    cout << "Inorder traversal after insertion (Example 1): ";
    inorderTraversal(root1);
    cout << endl;

    // Example 2
    TreeNode* root2 = new TreeNode(40);
    root2->left = new TreeNode(20);
    root2->right = new TreeNode(60);
    root2->left->left = new TreeNode(10);
    root2->left->right = new TreeNode(30);
    root2->right->left = new TreeNode(50);
    root2->right->right = new TreeNode(70);
    root2 = solution.insertIntoBST(root2, 25);
    cout << "Inorder traversal after insertion (Example 2): ";
    inorderTraversal(root2);
    cout << endl;
// Example 3
    TreeNode* root3 = new TreeNode(4);
    root3->left = new TreeNode(2);
    root3->right = new TreeNode(7);
    root3->left->left = new TreeNode(1);
    root3->left->right = new TreeNode(3);
    root3 = solution.insertIntoBST(root3, 5);
    cout << "Inorder traversal after insertion (Example 3): ";
    inorderTraversal(root3);
    cout << endl;
    return 0;
}


