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
    int maxPathSum(TreeNode* root) {
        int ret = INT_MIN;
        _maxPathSum(root, ret);
        return ret;
    }

    int _maxPathSum(TreeNode* root, int& ret) {
        if (!root) return 0;
        int left = _maxPathSum(root->left, ret);
        int right = _maxPathSum(root->right, ret);
        int onePath = max(root->val + max(left, right), root->val);
        int tmp = max(onePath, root->val + left + right);
        ret = max(tmp, ret);
        return onePath;
    }

};
