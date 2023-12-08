# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    n = None
    def isValidBST(self, root: Optional[TreeNode]) -> bool:

        def traverse(root):
            if root == None:
                return True
            left = traverse(root.left)
            if self.n != None and self.n >= root.val:
                return False
            self.n = root.val
            right = traverse(root.right)
            return left and right
        return traverse(root)
