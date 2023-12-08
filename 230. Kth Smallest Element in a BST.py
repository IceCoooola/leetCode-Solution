# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    n = 0
    ret = -1
    def kthSmallest(self, root: Optional[TreeNode], k: int) -> int:
        def traverse(root):
            if root == None:
                return
            traverse(root.left)
            self.n += 1
            if self.n == k:
                print(root.val)
                self.ret = root.val
                return
            traverse(root.right)
        traverse(root)
        return self.ret
