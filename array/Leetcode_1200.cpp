//Given an array of distinct integers arr, find all pairs of elements with the minimum absolute difference of any two elements.
// Return a list of pairs in ascending order(with respect to pairs), each pair [a, b] follows
// a, b are from arr
// a < b
// b - a equals to the minimum absolute difference of any two elements in arr

class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>>ans;

        sort(arr.begin(), arr.end());
        int min_diff = INT_MAX;

        for(int i = 0; i < n-1; i++){
            int diff = abs(arr[i]-arr[i+1]);

            if(diff < min_diff){
                min_diff = diff;
                ans.clear();
            }

            if(diff == min_diff){
                ans.push_back({arr[i], arr[i+1]});
            }
        }

        return ans;
    }
};