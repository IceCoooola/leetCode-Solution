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
    TreeNode* _buildTree(vector<int>& inorder,vector<int>& postorder,int inleft,int inright,int postleft,int postright)
    {
        if(inleft > inright || postleft > postright)
            return nullptr;
        TreeNode* root = new TreeNode(postorder[postright]);
        int i = 0;
        for(i; i <= (inright - inleft); i++)
        {
            if(inorder[inleft + i] == postorder[postright])
                break;            
        }
        root->left = _buildTree(inorder, postorder, inleft, inleft + i - 1, postleft, postleft + i - 1);
        root->right = _buildTree(inorder, postorder, inleft + i + 1, inright, postleft + i, postright - 1);
        return root;    
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int inleft = 0;
        int inright = inorder.size()-1;
        int postleft = 0;
        int postright = postorder.size()-1;
        return _buildTree(inorder, postorder, inleft, inright, postleft, postright);
        
    }
};
