class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        sort(nums1.begin(), nums1.end());
        int n = nums1.size();

        if(nums1[0] % 2) return true;

        for(int i = 1; i < n; i++){
            if(nums1[i] % 2) return false;
        }
        
        return true;
    }
};
