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
    int maxDepth(TreeNode* root) {
        return _maxDepth(root, 0);
    }
    int _maxDepth(TreeNode* root, int depth)
    {
        if(!root)
            return depth;
        return max(_maxDepth(root->left, depth + 1), _maxDepth(root->right, depth + 1));
        
    }
};
