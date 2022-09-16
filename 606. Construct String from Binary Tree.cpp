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
    void  _tree2str(TreeNode* root, string& ss)
    {
        if(root == nullptr)
            return;
        ss+=to_string(root->val);
        if(root->left == nullptr && root->right == nullptr)
            return;
        ss+="(";
        _tree2str(root->left, ss);
        ss+=")";
        if(root->right)
        {
        ss+="(";
        _tree2str(root->right, ss);
        ss+=")";   
        }          
    }
    string tree2str(TreeNode* root) {
        string ss;
        _tree2str(root, ss);
        return ss;
    }
};
