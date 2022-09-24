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
    vector<int> inorderTraversal(TreeNode* root) {
        TreeNode* cur  = root;
        stack<TreeNode*> st;
        vector<int> ret;
        while(cur || !st.empty())
        {
            while(cur)
            {
                st.push(cur);
                cur = cur->left;
            }
            ret.push_back(st.top()->val);
            cur = st.top()->right;
            st.pop();
        }
        return ret;
    }
};
