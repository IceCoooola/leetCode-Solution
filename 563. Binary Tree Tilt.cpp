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
         int ttl = 0;
    int findTilt(TreeNode* root) {
        findttl(root);
        return ttl;
    }
    int findttl(TreeNode* root)
    {
        if(!root)
            return 0;
        int left = findttl(root->left);
        int right = findttl(root->right);
        ttl += abs(right - left);
        return left + right + root->val;
    }
};
