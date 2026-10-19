class Solution {
  public:
    vector<int> lexicographicallyLargest(vector<int> &arr) {
        // code here
        int n = arr.size();
        
        vector<pair<int,int>>inter;
        
        int i = 0;
        
        for(int j = 1; j < n; j++){
            if((arr[j] + arr[j-1]) % 2 == 1){
                inter.push_back({i, j-1});
                i = j;
            }
        }
        
        inter.push_back({i, n-1});
        
        for(auto in : inter){
            int s = in.first;
            int e = in.second;
            // cout<<s<<" "<<e<<endl;
            
            sort(arr.begin() + s, arr.begin() + e + 1, greater<int>());
        }
        
        return arr;
    }
};