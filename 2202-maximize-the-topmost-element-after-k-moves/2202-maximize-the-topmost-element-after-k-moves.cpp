class Solution {
public:
    int maximumTop(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<int, vector<int>>max_heap;

        if(k == 0){
            return nums[0];
        }

        if(k % 2 == 1 && n == 1){
            return -1;
        }

        if(k == 1){
            return nums[1];
        }

        if(k <= n){
            int i = 0;
            while(k > 1){
                max_heap.push(nums[i]);
                i++;
                k--;
            }

            if(i+1 < n){
                if(nums[i+1] < max_heap.top()){
                    return max_heap.top();
                }else{
                    return nums[i+1];
                }
            }else{
                return max_heap.top();
            }
        }

        
        int max_ele = 0;

        for(int i = 0; i < n; i++){
            max_ele = max(max_ele, nums[i]);
        }

        return max_ele;
    }
};