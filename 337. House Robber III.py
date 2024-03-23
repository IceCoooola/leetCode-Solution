# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
from functools import lru_cache 
class Solution:
    def rob(self, root: Optional[TreeNode]) -> int:
        @lru_cache
        def max_amount_rob_curr_house(root):
            if not root:
                return 0
            return root.val + max_amount_not_rob_curr_house(root.left) + max_amount_not_rob_curr_house(root.right)
        
        @lru_cache
        def max_amount_not_rob_curr_house(root):
            if not root:
                return 0
            rob_left = max_amount_rob_curr_house(root.left)
            rob_right = max_amount_rob_curr_house(root.right)
            no_rob_left = max_amount_not_rob_curr_house(root.left)
            no_rob_right = max_amount_not_rob_curr_house(root.right)

            rob_both = rob_left + rob_right
            rob_left = rob_left + no_rob_right
            rob_right = no_rob_left + rob_right
            no_rob = no_rob_right + no_rob_left
            return max(rob_both,rob_left,rob_right,no_rob)
        return max(max_amount_rob_curr_house(root), max_amount_not_rob_curr_house(root))
