class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        unordered_map<int,int>mp;
        vector<vector<int>>interval;

        mp[0] = -1;
        int sum = 0;

        for(int i = 0; i < n; i++){
            sum += arr[i];
            if(mp.count(sum - target)){
                interval.push_back({mp[sum-target] + 1, i});
            }
            mp[sum] = i;
        }


        sort(interval.begin(), interval.end(), [](vector<int>& a, vector<int>& b){
            return a[0] < b[0];
        });

        if(interval.size() <= 1){
            return -1;
        }


        for(int i = 0; i < interval.size(); i++){
            int a2 = interval[i][0];
            int b2 = interval[i][1];

            interval[i].push_back(b2 - a2 + 1);
        }

        vector<int>mini(interval.size(), -1);
        mini[interval.size()-1] = interval[interval.size()-1][2];

        for(int i = interval.size() - 2; i >= 0; i--){
            mini[i] = min(interval[i][2], mini[i+1]);
        }

        int res = INT_MAX;

        for(int i = 0; i < interval.size(); i++){
            int second = interval[i][1];
            int val = interval[i][2];

            int l = i + 1;
            int h = interval.size()-1;
            int idx = -1;

            while(l <= h){
                int mid = l + (h - l)/2;

                if(interval[mid][0] <= second){
                    l = mid + 1;
                }else{
                    idx = mid;
                    h = mid - 1;
                }
            }

            if(idx != -1){
                int x = val + mini[idx];

                res = min(res, x);
            }
        }

        return res == INT_MAX ? -1 : res;
    }
};

// 0 2, 3 5, 1 4, 5 6
// 0 2, 1 4, 3 5, 5 6 