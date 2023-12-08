# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        ret = []
        if root == None:
            return []
        levelNode = [root]
        while levelNode:
            nextLevel = []
            levelVal = []
            for node in levelNode:
                if node.left:
                    nextLevel.append(node.left)
                if node.right:
                    nextLevel.append(node.right)
                levelVal.append(node.val)
            levelNode = nextLevel
            ret.append(levelVal)
        return ret
        
