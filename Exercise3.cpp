// EXERCISE: 3

// Given a binary tree, your task is to find all duplicate subtrees from the given binary tree.
// Duplicate Subtree: Two trees are duplicates if they have the same structure with the same node values.
// Note:  Return the root of each tree in the form of a list array & the driver code will print the tree in pre-order tree traversal in lexicographically increasing order. 
// Expected Time Complexity: O(n)
// Expected Space Complexity: O(n)
// Constraints:
// 1<= height of binary tree <=103

// Solution
\\\


#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

unordered_map<string, pair<TreeNode*, int>> mp;
vector<TreeNode*> res;

string serialize(TreeNode* root) {
    if (!root) return "#";
    string s = to_string(root->val) + "," + serialize(root->left) + "," + serialize(root->right);
    if (mp[s].second == 1) res.push_back(root);
    mp[s].first = root;
    mp[s].second++;
    return s;
}

vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
    mp.clear();
    res.clear();
    serialize(root);
    sort(res.begin(), res.end(), [](TreeNode* a, TreeNode* b) { return a->val < b->val; });
    return res;
}

void preorder(TreeNode* root) {
    if (!root) return;
    cout << root->val << " ";
    preorder(root->left);
    preorder(root->right);
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->right->left = new TreeNode(2);
    root->right->right = new TreeNode(4);
    root->right->left->left = new TreeNode(4);

    vector<TreeNode*> duplicates = findDuplicateSubtrees(root);
    for (auto node : duplicates) {
        preorder(node);
        cout << endl;
    }
    return 0;
}
