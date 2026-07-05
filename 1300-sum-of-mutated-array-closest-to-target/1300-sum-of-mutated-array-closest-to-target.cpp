class Solution {
public:
    int check(int value, vector<int>& arr){
        int sum = 0;

        for(int i = 0; i < arr.size(); i++){
            if(arr[i] < value){
                sum += arr[i];
            }else{
                sum += value*(arr.size() - i);
                break;
            }
        }

        return sum;
    }

    int findBestValue(vector<int>& arr, int target) {
        sort(arr.begin(), arr.end());

        int n = arr.size();

        int l = 0;
        int h = arr[n-1];
        int res = INT_MAX;
        int final_ans = INT_MAX;

        while(l <= h){
            int mid = l + (h - l)/2;
            int ans = check(mid, arr);
            if(abs(ans - target) < res){
                res = abs(ans-target);
                // cout<<mid<<" "<<res<<endl;
                final_ans = mid;
            }else if(abs(ans-target) == res){
                final_ans = min(final_ans, mid);
            }

            if(ans <= target){
                l = mid + 1;
            }else if(ans > target){
                h = mid - 1;
            }
        }

        return final_ans;
    }
};