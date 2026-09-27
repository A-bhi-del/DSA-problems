class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        int zero = 0;
        int one = 0;

        for(int i = 0; i < n; i++){
            nums[i] = nums[i] % 2;

            if(nums[i] == 0){
                zero++;
            }else{
                one++;
            }
        }

        if(n % 2 == 1){
            if(zero > one && zero != one + 1){
                return -1;
            }else if(one > zero && one != zero + 1){
                return -1;
            }
        }else{
            if(zero != one){
                return -1;
            }
        }

        int swaps_z = 0;
        if(zero >= one){
            vector<int>one;

            for(int i = 0; i < n; i++){
                if(nums[i] == 1 && i % 2 == 0){
                    one.push_back(i);
                }
            }

            int j = 0;
            for(int i = 0; i < n; i++){
                if(nums[i] == 0 && i % 2 == 1){
                    if(j < n){
                        swaps_z += abs(i - one[j++]);
                    }
                }
            }            
        }

        int swaps_o = 0;

        if(one >= zero){
            vector<int>zero;

            for(int i = 0; i < n; i++){
                if(nums[i] == 0 && i % 2 == 0){
                    zero.push_back(i);
                }
            }

            // for(int i = 0; i < zero.size(); i++){
            //     cout<<zero[i]<<" ";
            // }
            // cout<<endl;

            int j = 0;
            for(int i = 0; i < n; i++){
                if(nums[i] == 1 && i % 2 == 1){
                    if(j < n){
                        // cout<<i<<" "<<zero[j]<<endl;
                        swaps_o += abs(i - zero[j++]);
                    }else{
                        break;
                    }
                }
            }
        }

        if(zero > one){
            return swaps_z;
        }else if(zero < one){
            // cout<<"i am";
            return swaps_o;
        }

        return min(swaps_z, swaps_o);
    }
};

// 0 0 0 1 1
// 1 0 0 0 1
// 0 1 0 1 1