/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
    bool _findSameRoot(TreeNode* root, TreeNode* key)
    {
        if(root == nullptr)
            return false;
        if(root == key)
            return true;
        return _findSameRoot(root->left, key) || _findSameRoot(root->right, key);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == p)
            return p;
        if(root == q)
            return q;
        bool pisInLeftTree = _findSameRoot(root->left, p);
        bool pisInRightTree = !pisInLeftTree;
        bool qisInLeftTree = _findSameRoot(root->left, q);
        bool qisInRightTree = !qisInLeftTree;
        if((pisInLeftTree && qisInRightTree) || (pisInRightTree && qisInLeftTree))
            return root;
        else if (pisInLeftTree && qisInLeftTree)
        {
            return lowestCommonAncestor(root->left, p, q);
        }
        else
        {
            return lowestCommonAncestor(root->right, p, q);
        }
    }
};
