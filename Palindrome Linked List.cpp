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
    bool isPalindrome(ListNode* head) {
        
    ListNode* fast = head;
    ListNode* slow = head;
    while(fast&&fast->next)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    ListNode* tail = NULL;
    ListNode* newNode = NULL;
    while(slow)
    {
        newNode = slow;
        slow = slow->next;
        newNode->next = tail;
        tail = newNode;
    }
    while(newNode)
    {
        if(head->val == newNode->val)
        {
            head = head->next;
            newNode = newNode->next;
        }
        else
        {
            return false;
        }
    }
    return true;

    
    }
};
