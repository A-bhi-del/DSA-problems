class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();

        vector<int>copy_arr = arr;
        sort(copy_arr.begin(), copy_arr.end());

        unordered_map<int,int>mp;

        int rank = 1;

        for(int num : copy_arr){
            if(!mp.count(num)){
                mp[num] = rank;
                rank++;
            }
        }

        for(int i = 0; i < n; i++){
            arr[i] = mp[arr[i]];
        }

        return arr;
    }
};