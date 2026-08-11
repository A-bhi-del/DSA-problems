class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        n = len(nums)
        unique = 0
        i = 0
        j = 0

        while i < n:
            nums[j] = nums[i]
            unique += 1
            while i < n:
                if nums[j] == nums[i]:
                    i += 1
                else:
                    break
            j += 1

        return unique