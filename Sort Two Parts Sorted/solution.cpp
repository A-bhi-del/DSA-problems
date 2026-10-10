class Solution {
public:
    void mergeTwoParts(vector<int>& arr) {
        // code here
        
        int n = arr.size();
        
        int break_point = 0;
        
        for(int i = 1; i < n; i++){
            if(arr[i-1] > arr[i]){
                break_point = i;
                break;
            }
        }
        
        vector<int>ans(n, 0);
        int i = 0;
        
        int j = 0;
        int HN = break_point;
        
        while(j < HN && break_point < n){
            if(arr[j] <= arr[break_point]){
                ans[i++] = arr[j];
                j++;
            }else if(arr[j] > arr[break_point]){
                ans[i++] = arr[break_point];
                break_point++;
            }
            
        }
        
        while(j < HN){
            ans[i++] = arr[j++];
        }
        
        while(break_point < n){
            ans[i++] = arr[break_point++];
        }
        
        arr = ans;
    }
};