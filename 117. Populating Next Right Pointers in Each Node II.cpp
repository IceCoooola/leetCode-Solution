/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if (root == nullptr) {
            return root;
        }
        queue<Node*> st;
        Node* prev = nullptr;
        st.push(root);
        int level = 1;
        while (!st.empty()) {
            Node* front = st.front();
            st.pop();

            --level;

            if (front->left) st.push(front->left);
            if (front->right) st.push(front->right);

            if (prev) { 
                prev->next = front; 
                prev = front;
            }
            if (level == 0) {
                level = st.size(); 
                prev = nullptr;   
            } else {
                prev = front;
            }
        }
        return root;
    }
};
