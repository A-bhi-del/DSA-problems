class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end(),[](vector<int>& a, vector<int>& b){
            if(a[0] == b[0]){
                return a[1] > b[1];
            }
            return a[0] < b[0];
        });

        int merge_interval = 0;
        int sl = intervals[0][0];
        int sr = intervals[0][1];

        for(int i = 1; i < n; i++){
            int l = intervals[i][0];
            int r = intervals[i][1];

            if(sr < r){
                sl = l;
                sr = r;
            }else{
                merge_interval++;
            }
        }

        return n - merge_interval;
    }
};