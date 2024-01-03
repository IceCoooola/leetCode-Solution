/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int sumNumbers(TreeNode* root) {
        return _sumNumbers(root, 0);
    }

    int _sumNumbers(TreeNode* root, int num) {
        int total = num * 10 + root->val;
        if (is_leaf(root)) return total;
        int sum = 0;
        if (root->left) sum += _sumNumbers(root->left, total);
        if (root->right) sum += _sumNumbers(root->right, total);
        return sum;
    }

    bool is_leaf(TreeNode* root) {
        return root->left == nullptr && root->right == nullptr;
    }
};
