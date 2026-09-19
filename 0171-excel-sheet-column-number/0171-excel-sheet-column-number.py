class Solution(object):
    def titleToNumber(self, columnTitle):
        n = len(columnTitle)
        ans = ord(columnTitle[0]) - ord('A') + 1

        for i in range(1, n):
            ans = ans * 26 + ord(columnTitle[i]) - ord('A') + 1
        
        return ans