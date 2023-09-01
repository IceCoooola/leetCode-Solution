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
    int getMinimumDifference(TreeNode* root) {
        int minDiff = INT_MAX;
        int t = -0x7F7F7F;
        _getMinimumDifference(root, minDiff, t);
        return minDiff;
    }

    void _getMinimumDifference(TreeNode* root, int& minDiff, int& parentVal)
    {
        if(!root)
            return;
        _getMinimumDifference(root->left, minDiff, parentVal);
            minDiff = min(minDiff,root->val - parentVal);
        parentVal = root->val;
        _getMinimumDifference(root->right, minDiff, parentVal);
    }
};
