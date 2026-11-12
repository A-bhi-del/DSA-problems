class Solution {
public:
    int minTime(int n, int s1, int s2) {
        // code here
        if(s1 > s2){
            swap(s1, s2);
        }
        
        int low = 0;
        int high = n;
        
        int min_time = n* s2;
        
        while(low <= high){
            int mid = low + (high - low)/2;
            
            int t1 = s1 * (mid + 1);
            int t2 = s2 * (n - mid - 1);
            
            min_time = min(min_time, max(t1, t2));
            
            if(t1 <= t2){
                low = mid + 1;
            }else{
                high = mid - 1;
            }
        }
        
        return min_time;
    }
};