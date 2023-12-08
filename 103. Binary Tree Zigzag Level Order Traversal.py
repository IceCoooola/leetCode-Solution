# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def zigzagLevelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        if root == None:
            return []
        levelNode = [root]
        ret = []
        reversed = False
        while levelNode:
            nextLevel = []
            levelVal = []
            start, end = -1, - len(levelNode) - 1
            for i in range(start, end, -1):
                if reversed: 
                    if levelNode[i].right:
                        nextLevel.append(levelNode[i].right)
                    if levelNode[i].left:
                        nextLevel.append(levelNode[i].left)
                else:
                    if levelNode[i].left:
                        nextLevel.append(levelNode[i].left)
                    if levelNode[i].right:
                        nextLevel.append(levelNode[i].right)
                levelVal.append(levelNode[i].val)
            ret.append(levelVal)
            levelNode = nextLevel
            reversed = not reversed
        return ret
