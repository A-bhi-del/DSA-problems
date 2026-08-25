class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int n = nums.size();

        bool one = false;
        for(int i = 0; i < n; i++){
            if(nums[i] % k == 0){
                nums[i] = nums[i]/k;
                if(nums[i] == 1){
                    one = true;
                }
            }else{
                nums[i] = 1;
            }
        }

        if(!one){
            return k;
        }

        for(int i = 0; i < n; i++){
            if(nums[i] > n){
                nums[i] = 1;
            }
        }

        // for(int i = 0; i < n; i++){
        //     cout<<nums[i]<<endl;
        // }

        for(int i = 0; i < n; i++){
            int idx = abs(nums[i]) - 1;
            if(nums[idx] > 0){
                nums[idx] = -nums[idx];
            }
        }

        // cout<<" i am working "<<endl;

        for(int i = 0; i < n; i++){
            if(nums[i] > 0){
                return k * (i + 1);
            }
        }

        return k * (n + 1);
    }
};