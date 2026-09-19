class Solution(object):
    def summaryRanges(self, nums):
        ans = []
        n = len(nums)

        if n == 0:
            return ans

        mini = 0
        maxi = 0
        for i in range(1, n):
            if nums[i] == nums[i-1] + 1:
                maxi = i
            else:
                if mini != maxi:
                    st = str(nums[mini]) + "->" + str(nums[maxi])
                    ans.append(st)
                else :
                    st = str(nums[mini])
                    ans.append(st)
                mini = i
                maxi = i

        if mini != maxi:
            st = str(nums[mini]) + "->" + str(nums[maxi])
            ans.append(st)
        else :
            st = str(nums[mini])
            ans.append(st)

        return ans

        