class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        int maxi = *max_element(nums.begin(), nums.end());

        int len = 1;

        while(len <= maxi){
            len = len << 1;
        }

        vector<bool>arr(len+1, false);
        arr[0] = true;

        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                int res = nums[i] ^ nums[j];
                if(arr[res] == true){
                    continue;
                }
                arr[res] = true;
            }
        }

        vector<bool>res(len+1, false);

        for(int i = 0; i < n; i++){
            for(int j = 0; j < arr.size(); j++){
                if(arr[j] == true){
                    int ans = nums[i] ^ j;
                    if(res[ans] == true){
                        continue;
                    }
                    res[ans] = true;
                }
            }
        }

        int count = 0;
        for(int i = 0; i < res.size(); i++){
            if(res[i] == true){
                count++;
            }
        }


        return count;
    }
};