class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int>even;
        unordered_map<int,int>odd;

        for(int i = 0; i < n; i++){
            if(i % 2 == 0){
                even[nums[i]]++;
            }else{
                odd[nums[i]]++;
            }
        }

        int max_e = INT_MIN;
        int first_e_num = -1;
        int max_o = INT_MIN;
        int first_o_num = -1;
        int smax_e = INT_MIN;
        int smax_o = INT_MIN;
        int second_e_num = -1;
        int second_o_num = -1;

        for(auto it : even){
            if(max_e < it.second){
                max_e = it.second;
                first_e_num = it.first;
            }
        }

        for(auto it : even){
            if(it.first == first_e_num) continue;
            if(smax_e < it.second){
                smax_e = it.second;
                second_e_num = it.first;
            }
        }

        for(auto it : odd){
            if(max_o < it.second){
                max_o = it.second;
                first_o_num = it.first;
            }
        }

        for(auto it : odd){
            if(it.first == first_o_num) continue;
            if(smax_o < it.second){
                smax_o = it.second;
                second_o_num = it.first;
            }
        }

        if(even.size() == 1 && odd.size() == 1 && first_e_num == first_o_num){
            return min(even[first_e_num], odd[first_o_num]);
        }

        if(even.size() == 1){
            int ans1 = INT_MAX;
            if(first_e_num == first_o_num){
                ans1 = n/2;
            }else{
                ans1 = n/2 - odd[first_o_num];
            }

            int ans2 = INT_MAX;
            if(first_e_num == second_o_num){
                ans2 = n/2;
            }else{
                ans2 = n/2 - odd[second_o_num];
            }

            return min(ans1, ans2);
        }

        if(odd.size() == 1){
            int ans1 = INT_MAX;
            if(first_o_num == first_e_num){
                ans1 = (n+1)/2;
            }else{
                ans1 = (n+1)/2 - even[first_e_num];
            }

            int ans2 = INT_MAX;
            if(first_o_num == second_e_num){
                ans2 = (n+1)/2;
            }else{
                ans2 = (n+1)/2 - even[second_e_num];
            }
            // cout<<even[second_e_num]<<endl;

            // cout<<ans1<<" "<<ans2<<endl;

            return min(ans1, ans2);
        }

        int ans1 = INT_MAX;
        int ans2 = INT_MAX;
        int ans3 = INT_MAX;
        int ans4 = INT_MAX;

        if(first_e_num == first_o_num){
            ans1 = min(n - even[first_e_num], n - odd[first_o_num]);
        }else{
            ans1 = n - even[first_e_num] - odd[first_o_num];
        }

        if(first_e_num == second_o_num){
            ans2 = min(n - even[first_e_num], n - odd[second_o_num]);
        }else{
            ans2 = n - even[first_e_num] - odd[second_o_num];
        }

        if(second_o_num == second_e_num){
            ans3 = min(n - even[second_e_num], n - odd[second_o_num]);
        }else{
            ans3 = n - even[second_e_num] - odd[second_o_num];
        }

        if(first_o_num == second_e_num){
            ans4 = min(n - even[second_e_num], n - odd[first_o_num]);
        }else{
            ans4 = n - even[second_e_num] - odd[first_o_num];
        }

        return min({ans1, ans2, ans3, ans4});
    }
};

// 1 2 1 1 2 1 
