class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        n = len(nums)

        l = 0
        h = n-1
        idx = -1

        while l <= h:
            m = l + (h - l) // 2
            if nums[m] <= target:
                idx = m
                l = m + 1
            else:
                h = m - 1

        if idx == -1 or nums[idx] != target:
            return idx + 1
    
        return idx