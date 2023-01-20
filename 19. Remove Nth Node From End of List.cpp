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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        int sz = 0;
        ListNode* cur = head;
        while(cur)
        {
            cur = cur->next;
            ++sz;
        }
        sz -= n;
        ListNode* prev = nullptr;
        cur = head;
        while(sz)
        {
            prev = cur;
            cur = cur->next;
            sz--;
        }
        if(prev)
        {
            prev->next = cur->next;
            delete cur;
        }
        else
        {
            head = cur -> next;
            delete cur;
        }
        return head;
    }
};
