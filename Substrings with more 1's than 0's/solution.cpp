class Solution {
  public:
    vector<int>segTree;
    
    int find_query(int s, int e, int l, int r, int i){
        if(r < s || l > e){
            return 0;
        }
        
        if(l <= s && e <= r){
            return segTree[i];
        }
        
        int mid = s + (e - s)/2;
        
        return find_query(s, mid, l, r, 2*i+1) + find_query(mid+1, e, l, r, 2*i+2);
    }
    
    void update_segTree(int i, int s, int e, int index){
        if(s == e){
            segTree[i] += 1;
            return;
        }
        
        int mid = s + (e - s)/2;
        
        if(index <= mid){
            update_segTree(2*i+1, s, mid, index);
        }else{
            update_segTree(2*i+2, mid+1, e, index);
        }
        
        segTree[i] = segTree[2*i+1] + segTree[2*i+2];
    }
    
    int countSubstring(string& s) {
        // Code Here
        int n = s.length();
        int ans = 0;
        segTree.resize(4*(n+1), 0);
        
        vector<int>pre(n+1, 0);
        
        for(int i = 1; i <= n; i++){
            if(s[i-1] == '0'){
                pre[i] = -1;
            }else{
                pre[i] = 1;
            }
        }
        
        for(int i = 1; i <= n; i++){
            pre[i] = pre[i] + pre[i-1];
        }
        
        vector<int>copy_pre = pre;
        sort(copy_pre.begin(), copy_pre.end());
        
        int idx = 0;
        
        unordered_map<int,int>mp;
        
        for(int i = 0; i <= n; i++){
            if(!mp.count(copy_pre[i])){
                mp[copy_pre[i]] = idx;
                idx++;
            }
        }
        
        for(int i = 0; i <= n; i++){
            int index = mp[pre[i]];
            
            int count = find_query(0, idx-1, 0, index-1, 0);
            ans += count;
            
            update_segTree(0, 0, idx-1, index);
            
        }
        
        return ans;
    }
};