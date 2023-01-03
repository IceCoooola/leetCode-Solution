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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root)
            return false;
        return _hasPathSum(root, 0, targetSum);
    }
    bool _hasPathSum(TreeNode* root,int ttlSum, int targetSum)
    {
        ttlSum += root->val;
        if(root->left == nullptr && root->right == nullptr)
        {
            if(ttlSum == targetSum)
            return true;
            else
            return false;
        }
        bool left = false;
        bool right = false;
        if(root->left)
        {
            left = _hasPathSum(root->left,ttlSum,targetSum);
        }
        if(root->right)
        {
            right = _hasPathSum(root->right,ttlSum,targetSum);
        }
        return left || right;
    }
};
