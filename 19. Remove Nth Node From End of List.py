# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        fast = head
        slow = head
        prev = None
        ret = head

        while n != 0:
            fast = fast.next
            n -= 1
        if not fast:
            return head.next
        
        while fast != None:
            fast = fast.next
            prev = slow
            slow = slow.next
        
        if prev:
            prev.next = slow.next
            return ret
        else:
            return None
