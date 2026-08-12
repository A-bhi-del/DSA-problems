class Solution:
    def maxSubarrayLength(self, nums: List[int], k: int) -> int:
        mp = {}
        n = len(nums)
        max_len = 0
        j = 0

        for i in range(0, n):
            mp[nums[i]] = mp.get(nums[i], 0) + 1
            while mp[nums[i]] > k:
                mp[nums[j]] = mp.get(nums[j], 0) - 1
                if mp.get(nums[j], 0) == 0:
                    del mp[nums[j]]
                j += 1
            max_len = max(max_len, i - j + 1)

        return max_len