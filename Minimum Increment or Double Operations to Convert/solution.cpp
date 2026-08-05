class Solution {
  public:
    int countMinOperations(vector<int>& arr) {
        // code here
        int count = 0;
        
        int maxi = *max_element(arr.begin(), arr.end());
        
        int p = 1;
        
        while(p < maxi){
            p = p << 1;
            if(p > maxi) break;
            count++;
        }

        for(int val : arr){
            int temp = 0;
            
            while(val >= 1){
                if(val % 2 == 1){
                    temp++;
                }
                val = val / 2;
            }
            
            count += temp;
        }
        
        return count;
    }
};

// 7 8
// 6 8
// 3 4
// 2 4
// 1 2
// 0 2
// 0 1
// 0 0 

// 7 8 9
// 6 8 9
// 6 8 8
// 3 4 4
// 2 4 4
// 1 2 2
// 0 2 2 
// 0 1 1
// 0 0 1
// 0 0 0 -> 0