class Solution {
public:
    bool splitArraySameAverage(vector<int>& nums) {
        int N = nums.size();
        int n = N/2;
        int n1 = n;
        int n2 = N - n1;

        unordered_map<int, vector<int>>left;
        for(int mask = 0; mask < pow(2, n1); mask++){
            int sum = 0;
            int count = 0;

            for(int i = 0; i < n1; i++){
                if((mask & (1 << i))){
                    sum += nums[i];
                    count++;
                }
            }

            left[count].push_back(sum);
        }

        unordered_map<int, vector<int>>right;
        for(int mask = 0; mask < pow(2, n2); mask++){
            int sum = 0;
            int count = 0;

            for(int i = 0; i < n2; i++){
                if((mask & (1 << i))){
                    sum += nums[i + n1];
                    count++;
                }
            }

            right[count].push_back(sum);
        }
   
        for(int count = 0; count <= n2; count++){
            sort(right[count].begin(), right[count].end());
        }
    
        int sum = 0;

        for(int num : nums){
            sum += num;
        }

        for(int count = 0; count <= n1; count++){
            int leftcount = count;

            for(int s : left[leftcount]){
                int leftsumA = s;

                for(int c = 0; c <= n2; c++){
                    int rightcount = c;
                    int nA = leftcount + rightcount;

                    if(nA == 0 || nA == N) continue;          
                    if((sum * nA) % N != 0) continue;         

                    int need = (sum * nA) / N - leftsumA;

                    vector<int>& temp = right[rightcount];   

                    int l = 0;
                    int h = (int)temp.size() - 1;

                    while(l <= h){
                        int mid = l + (h-l)/2;

                        if(temp[mid] == need){
                            return true;
                        }else if(temp[mid] < need){
                            l = mid + 1;
                        }else{
                            h = mid - 1;
                        }
                    }
                }
            }
        }

        return false;
    }
};