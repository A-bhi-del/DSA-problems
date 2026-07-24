class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int n = arr.size();
        if(n < 3){
            return false;
        }

        int i = 0;
        bool is_inc = false;
        bool is_dec = false;

        while(i < n){
            while(i+1 < n && arr[i] < arr[i+1]){
                is_inc = true;
                i++;
            }
            while(i+1 < n && arr[i] > arr[i+1]){
                is_dec = true;
                i++;
            }
            break;
        }

        cout<<i<<endl;
        if(i == n-1 && is_inc && is_dec){
            return true;
        }
        return false;
    }
};