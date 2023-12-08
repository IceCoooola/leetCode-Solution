# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def averageOfLevels(self, root: Optional[TreeNode]) -> List[float]:
        ret = []
        if root == None:
            return ret
        curLevel = [root]
        while curLevel:
            total = 0
            tmp = []
            sz = len(curLevel)
            for rt in curLevel:
                total += rt.val
                if rt.left:
                    tmp += [rt.left]
                if rt.right:
                    tmp += [rt.right]
            ret += [total / sz]
            curLevel = tmp
        return ret
