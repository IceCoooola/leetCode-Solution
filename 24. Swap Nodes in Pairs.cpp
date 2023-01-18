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
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next)
            return head;
        ListNode* first = head;
        ListNode* prev = nullptr;
        ListNode* second = first->next;
        ListNode* newHead = first->next;
        while(second)
        {
            ListNode* next = second->next;
            first->next = next;
            if(prev)
            {
                prev->next = second;
            }
            second->next = first;
            prev = first;
            first = next;
            if(first)
                second = first->next;
            else
                second = nullptr;
        }
        return newHead;
    }
};
