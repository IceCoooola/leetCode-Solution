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
    TreeNode* invertTree(TreeNode* root) {
        
        if(!root)
            return nullptr;
        TreeNode* tmpLeft = root->left;
        root->left = invertTree(root->right);
        root->right = invertTree(tmpLeft);
        return root;
    }
};

// /**
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     struct TreeNode *left;
//  *     struct TreeNode *right;
//  * };
//  */

// void _invertTree(struct TreeNode* root)
//  {
//     if(root == NULL)
//         return;
//     if(root->left == NULL && root->right == NULL)
//         return;
//     struct TreeNode* temp = root->left;
//     root->left = root->right;
//     root->right = temp;
//     _invertTree(root->left);
//     _invertTree(root->right);
//  }

// struct TreeNode* invertTree(struct TreeNode* root){
//     _invertTree(root);
//     return root;
// }
