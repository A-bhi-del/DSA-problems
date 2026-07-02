class Solution:
    def leaders(self, arr):
        ans = []
        max_right = arr[-1]

        ans.append(max_right)

        for i in range(len(arr) - 2, -1, -1):
            if arr[i] >= max_right:
                ans.append(arr[i])
                max_right = arr[i]

        return ans[::-1]