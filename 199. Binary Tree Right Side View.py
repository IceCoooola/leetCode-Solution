# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def rightSideView(self, root: Optional[TreeNode]) -> List[int]:
        ret = []
        if root == None:
            return ret
        cur = [root]
        while cur:
            ret += [cur[len(cur) - 1].val]
            tmp = []
            for rt in cur:
                if rt.left is not None:
                    tmp += [rt.left]
                if rt.right is not None:
                    tmp += [rt.right]
            cur = tmp
        return ret
