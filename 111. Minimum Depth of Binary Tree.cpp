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
    int minDepth(TreeNode* root) {
        int ret = 0;
        TreeNode* cur = root;
        while(cur)
        {
            ret += 1;
            if(cur->left)
              cur = cur->left;
            else if(cur->right)
              cur = cur->right;
            else
            {
                ret +=1;
                break;
            }
        }
        _minDepth(root, 0, ret);
        return ret;
    }
    
    void _minDepth(TreeNode* root, int depth, int& mDepth)
    {
        if(!root)
            return;
        if(root->left == nullptr && root->right == nullptr)
        {
            depth += 1;
            if(mDepth > depth)
            mDepth = depth;
            return;
        }
        _minDepth(root->left, depth + 1, mDepth);
        _minDepth(root->right, depth + 1, mDepth);
    }
};
