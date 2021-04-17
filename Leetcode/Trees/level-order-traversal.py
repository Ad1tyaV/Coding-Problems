# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
# https://leetcode.com/problems/binary-tree-level-order-traversal

class Solution:
    
    sol = []
    
    def traverse(self, root, track):
        
        if root is not None:        
            if track == 0:
                self.sol.append([root.val])
            else:
                if len(self.sol) == track :
                    self.sol.append([root.val])
                else:
                    self.sol[track].append(root.val)                


            self.traverse(root.left, track+1)
            self.traverse(root.right, track+1)
        
    
    def levelOrder(self, root: TreeNode) -> List[List[int]]:
        
        self.sol = []
        self.traverse(root, 0)        
        return self.sol
