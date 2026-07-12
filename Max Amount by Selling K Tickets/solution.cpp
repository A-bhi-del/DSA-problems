class Solution {
  public:
    int mod = 1e9+7;
    int maxAmount(vector<int>& arr, int k) {
        // code here
        priority_queue<int>max_heap;
        
        for(int num : arr){
            max_heap.push(num);
        }
        
        long long ans = 0;
        
        while(k > 0){
            int top = max_heap.top();
            max_heap.pop();
            
            if(top > 0){
                ans = (ans + top) % mod;
                top = top - 1;
                
                max_heap.push(top);
            }
            
            k--;
        }
        
        return ans;
    }
};