class Solution {
  public:
    int maxPathSum(vector<int> &a, vector<int> &b) {
        // Code here
        int na = a.size();
        int nb = b.size();
        int res = 0;
        int suma = 0;
        int sumb = 0;
        
        int i = 0;
        int j = 0;
        
        while(i < na && j < nb){
            if(a[i] < b[j]){
                suma += a[i++];
            }else if(a[i] > b[j]){
                sumb += b[j++];
            }else{
                res += max(suma, sumb);
                suma = a[i];
                sumb = b[j];
                i++;
                j++;
            }
        }
        
        while(i < na){
            suma += a[i++];
        }
        
        while(j < nb){
            sumb += b[j++];
        }
        
        res += max(suma, sumb);
        
        return res;
    }
};