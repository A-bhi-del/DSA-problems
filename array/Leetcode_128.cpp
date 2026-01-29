// Longest Consecutive Sequence

// Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.
// You must write an algorithm that runs in O(n) time.


// O(n) solution with extra space O(n)
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int>mp;

        for(int i = 0; i < nums.size(); i++){
            mp[nums[i]]++;
        }

        int result = 0;
        for(int i = 0; i < nums.size(); i++){
            int val = nums[i];
            int ans = 0;

            if(mp.find(val-1) != mp.end()){
                continue;
            }

            while(mp.find(val) != mp.end()){
                ans++;
                mp.erase(val);
                val = val + 1;
            }

            result = max(result, ans);
        }

        return result;
    }
};