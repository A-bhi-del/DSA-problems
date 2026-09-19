class Solution(object):
    def solve(self, n, seen):
        if n == 1:
            return True
        elif n in seen:
            return False

        seen.add(n)
        
        nn = 0
        while(n > 0):
            temp = n % 10
            nn += temp * temp
            n = n // 10
        
        return self.solve(nn, seen)

    def isHappy(self, n):
        return self.solve(n, set())
        