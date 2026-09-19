# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def __init__(self):
        self.st = set()

    def solve(self, root, s):
        if root is None:
            return

        s += str(root.val)

        if root.left is None and root.right is None:
            self.st.add(s)
            return
        
        s += "->"

        self.solve(root.left, s)
        self.solve(root.right, s)

    def binaryTreePaths(self, root):
        self.solve(root, "")

        ans = []
        for x in self.st:
            ans.append(x)

        return ans
        