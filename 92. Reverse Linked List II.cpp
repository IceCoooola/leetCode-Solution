# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseBetween(self, head: Optional[ListNode], left: int, right: int) -> Optional[ListNode]:
        if left == right or head == None:
            return head
        
        is_head = False
        head_left = None
        head_right = None
        tail_left = None
        tail_right = None
        is_tail = False
        if left == 1:
            is_head = True
            head_right = head
        ret = head
        cur = head
        while cur != None:
            if left == 2:
                head_left = cur
                head_right = cur.next
            if right == 1:
                tail_left = cur
                tail_right = cur.next
            cur = cur.next
            left -= 1
            right -= 1


        if tail_right == None:
            is_tail = True
        tail_left.next = None
        if not is_head:
            head_left.next = None
        cur = head_right
        prev = None
        while cur != None:
            next = cur.next
            cur.next = prev
            prev = cur
            cur = next
        if not is_tail:
            head_right.next = tail_right
        if is_head:
            return tail_left
        else:
            head_left.next = tail_left
            return ret
