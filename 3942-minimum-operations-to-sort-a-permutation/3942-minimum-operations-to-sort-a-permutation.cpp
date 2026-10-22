class Solution {
public:
    bool is_sorted(vector<int>& nums){
        int n = nums.size();

        for(int i = 0; i < n-1; i++){
            if(nums[i] > nums[i+1]){
                return false;
            }
        }

        return true;
    }

    int cnt(vector<int>& arr){
        int n = arr.size();
        int count = 0;
        if(arr[0] > arr[n-1]){
            count++;
            for(int i = 1; i < n; i++){
                if(arr[i] > arr[i-1]){
                    count++;
                }else{
                    break;
                }
            }
        }else if(arr[0] < arr[n-1]){
            count++;
            for(int i = 1; i < n; i++){
                if(arr[i-1] > arr[i]){
                    count++;
                }else{
                    break;
                }
            }
        }

        return count;
    }

    int minOperations(vector<int>& nums) {
        int n = nums.size();

        vector<int>temp = nums;
        if(is_sorted(nums)){
            return 0;
        }

        reverse(temp.begin(), temp.end());
        if(is_sorted(temp)){
            return 1;
        }

        int countn = cnt(nums);
        int countt = cnt(temp);
        bool t = true;
        bool nu = true;

        // cout<<countt<<" "<<countn<<endl;

        if(nums[0] > nums[n-1]){
            for(int i = countn; i < n-1; i++){
                if(nums[i] > nums[i+1]){
                    nu = false;
                    break;
                }
            }
        }else if(nums[0] < nums[n-1]){
            for(int i = countn; i < n-1; i++){
                if(nums[i] < nums[i+1]){
                    nu = false;
                    break;
                }
            }

            if(nu){
                countn++;
            }
        }

        if(temp[0] > temp[n-1]){
            for(int i = countt; i < n-1; i++){
                if(temp[i] > temp[i+1]){
                    t = false;
                    break;
                }
            }
        }else if(temp[0] < temp[n-1]){
            for(int i = countt; i < n-1; i++){
                if(temp[i] < temp[i+1]){
                    t = false;
                    break;
                }
            }
            if(t){
                countt++;
            }
        }

        // cout<<nu<<" "<<t<<endl;
        // cout<<countt<<" "<<countn<<endl;

        if(!t && !nu){
            return -1;
        }else if(!t && nu){
            return countn;
        }else if(!nu && t){
            return countt+1;
        }

        return min(countt + 1, countn);
    }
};

// 1 2 0
// 2 0 1