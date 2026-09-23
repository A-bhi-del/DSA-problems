class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MIN;

        for(int i = 0; i < 32; i++){
            vector<int>temp;

            for(int j = 0; j < n; j++){
                if((nums[j] & (1 << i))){
                    temp.push_back(nums[j]);
                }
            }
            
            vector<int>temp1;
            for(int k = 0; k < temp.size(); k++){
                int val = temp[k];
                
                int l = 0;
                int h = temp1.size()-1;
                
                while(l <= h){
                    int mid = l + (h-l)/2;
                    
                    if(temp1[mid] < val){
                        l = mid + 1;
                    }else{
                        h = mid - 1;
                    }
                }
                
                if(l == temp1.size()){
                    temp1.push_back(val);
                }else{
                    temp1[l] = val;
                }
            }

            int sz = temp1.size();

            ans = max(ans, sz);
        }

        return ans;
    }
};


































/*

int longestSubsequence(vector<int>& nums) {
    int n=nums.size();
    
    vector<int> dp;
}

*/










