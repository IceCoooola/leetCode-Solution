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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(!l2)
        return l1;
        if(!l1)
        return l2;
        ListNode* head = new ListNode(0);
        int carry = 0;
        ListNode* cur = head;
        while(l1 && l2)
        {
            int sum = l1->val + l2->val + carry;
            carry = sum / 10;
            ListNode* newNode = new ListNode(sum%10);
            cur->next = newNode;
            cur = cur->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1)
        {
            ListNode* newNode = new ListNode((l1->val + carry)%10);
            carry = (l1->val + carry) / 10;
            l1 = l1->next;
            cur->next = newNode;
            cur = cur->next;
        }
        while(l2)
        {
            ListNode* newNode = new ListNode((l2->val + carry) % 10);
            carry = (l2->val + carry) / 10;
            l2 = l2->next;
            cur->next = newNode;
            cur = cur->next;
        }
        if(carry)
        {
            ListNode* newNode = new ListNode(carry);
            cur->next = newNode;
        }
        return head->next;
}
};
