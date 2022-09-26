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
    TreeNode* _buildTree(const vector<int>& preorder, int& pi,const vector<int>& inorder, int left, int right)
    {
        if(right < left)
            return nullptr;
        int mid = 0;
        while(inorder[mid] != preorder[pi])
        {
            mid++;    
        }
        TreeNode* root = new TreeNode(preorder[pi++]);
        root->left = _buildTree(preorder, pi, inorder, left, mid-1);
        root->right = _buildTree(preorder, pi, inorder, mid+1, right);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int i = 0;
        return _buildTree(preorder, i, inorder, 0, inorder.size()-1);
    }
};
