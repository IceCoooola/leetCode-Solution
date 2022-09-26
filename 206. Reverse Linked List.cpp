/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head)
            return nullptr;
        stack<int> st;
        while(head != nullptr)
        {
            st.push(head->val);
            head = head->next;
        }
        ListNode* newhead = new ListNode(st.top());
        st.pop();
        ListNode* cur = newhead;
        while(!st.empty())
        {
            ListNode* newnode = new ListNode(st.top());
            cur->next = newnode;
            cur = cur->next;
            st.pop();
        }
        return newhead;
    }
};
