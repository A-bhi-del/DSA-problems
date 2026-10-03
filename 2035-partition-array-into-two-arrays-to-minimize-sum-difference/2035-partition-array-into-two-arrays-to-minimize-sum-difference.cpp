class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int n = nums.size();
        int m1 = n/2;
        int sum = 0;

        for(int num : nums){
            sum += num;
        }

        unordered_map<int, vector<int>>left;
        for(int i = 0; i < pow(2, m1); i++){
            int count = 0;
            int s = 0;

            for(int j = 0; j < m1; j++){
                if((i & (1 << j))){
                    s += nums[j];
                    count++;
                }
            }

            left[count].push_back(s);
        }

        unordered_map<int, vector<int>>right;
        for(int i = 0; i < pow(2, m1); i++){
            int count = 0;
            int s = 0;

            for(int j = 0; j < m1; j++){
                if((i & (1 << j))){
                    s += nums[j+m1];
                    count++;
                }
            }

            right[count].push_back(s);
        }

        for(int count = 0; count <= m1; count++){
            sort(right[count].begin(), right[count].end());
        }

        int ans = INT_MAX;

        for(int count = 0; count <= m1; count++){
            int leftcount = count;
            int rightcount = m1 - count;
            vector<int>temp = right[rightcount];

            for(int i = 0; i < left[leftcount].size(); i++){
                int leftsum = left[leftcount][i];
                int need = (sum - (2 * leftsum))/2;

                int l = 0;
                int h = temp.size()-1;
                int idx = 0;

                while(l <= h){
                    int mid = l + (h - l)/2;

                    if(temp[mid] >= need){
                        idx = mid;
                        h = mid - 1;
                    }else{
                        l = mid + 1;
                    }
                }

                if(idx < temp.size()){
                    int rightsum = temp[idx];
                    // cout<<count<<endl;
                    ans = min(ans, abs(2 * (rightsum + leftsum) - sum));
                }

                if(idx - 1 >= 0){
                    int rightsum = temp[idx-1];
                    ans = min(ans, abs(2 * (rightsum + leftsum) - sum));
                }
            }
        }

        return ans;
    }
};