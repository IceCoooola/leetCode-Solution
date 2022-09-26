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
    vector<int> preorderTraversal(TreeNode* root) {
        TreeNode* cur = root;
        vector<int> ret;
        stack<TreeNode*> st;
        while(cur || !st.empty())
        {
            while(cur)
            {
                st.push(cur);
                ret.push_back(cur->val);
                cur = cur->left;
            }
            cur = st.top()->right;
            st.pop();
        }
        return ret;
    }
};
