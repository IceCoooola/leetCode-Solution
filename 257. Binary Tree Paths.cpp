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


void _binaryTreePaths(TreeNode* root,string tmp, vector<string>& ret)
{
    if(root == nullptr)
        return;
    if(root->left == nullptr && root->right == nullptr)
    {
        tmp+=to_string(root->val);
        ret.push_back(tmp);        
    }
    tmp+=to_string(root->val);
    tmp+="->";
    _binaryTreePaths(root->left, tmp, ret);
    _binaryTreePaths(root->right, tmp, ret);
}

class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        string tmp;
        vector<string> ret;
        _binaryTreePaths(root, tmp, ret);
        return ret;
    }
};
