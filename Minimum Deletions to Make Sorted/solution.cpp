class Solution {
  public:
    int minDeletions(vector<int>& arr) {
        // code here
        vector<int>temp;
        int n = arr.size();
        
        for(int i = 0; i < n; i++){
            int s = 0;
            int e = temp.size()-1;
            
            while(s <= e){
                int mid = s + (e - s)/2;
                
                if(temp[mid] < arr[i]){
                    s = mid + 1;
                }else{
                    e = mid - 1;
                }
            }
            
            if(s == temp.size()){
                temp.push_back(arr[i]);
            }else if(temp[s] > arr[i]){
                temp[s] = arr[i];
            }
        }
        
        return n - temp.size();
    }
};