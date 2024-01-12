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
    int maxAncestorDiff(TreeNode* root) {
        int ret = 0;
        find_max_and_min(root, root->val, root->val, ret);
        return ret;
    }

    void find_max_and_min(TreeNode* root, int large, int small, int& ret) {
        if (!root) return;
        if (root->val < small) small = root->val;
        if (root->val > large) large = root->val;
        ret = max(large - small, ret);
        find_max_and_min(root->left, large, small, ret);
        find_max_and_min(root->right, large, small, ret);
    }
    
};
