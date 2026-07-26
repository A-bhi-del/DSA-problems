class Solution {
public:
    int minMaxGame(vector<int>& nums) {
        int len = nums.size();

        while(len > 1){
            int j = 0;
            for(int i = 0; i < len; i+=2){
                if(j % 2 == 0){
                    if(i+1 >= len){
                        nums[j++] = nums[i];  
                    }else{
                        nums[j++] = min(nums[i], nums[i+1]);
                    }
                }else{
                    if(i+1 >= len){
                        nums[j++] = nums[i];  
                    }else{
                        nums[j++] = max(nums[i], nums[i+1]);
                    }
                }
            }

            j = 0;
            len = len / 2;
        }

        return nums[0];
    }
};