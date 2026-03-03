//Given an array of integers arr[] and a number k, count the number of subarrays having XOR of their elements as k.
// Note: It is guranteed that the total count will fit within a 32-bit integer.

class Solution {
  public:
    long subarrayXor(vector<int> &arr, int k) {
        // code here
        int n = arr.size();
        unordered_map<int,int>mp;
        mp[0] = 1;
        
        int pre = 0;
        int count = 0;
        
        for(int i = 0; i < n; i++){
            pre = pre^arr[i];
            if(mp.count(pre^k)){
                count += mp[pre^k];
            }
            mp[pre]++;
        }
        
        return count;
    }
};

// 4 2 2 6 4 = arr
// 4 6 4 2 6 = pre
// yaha map prev xor ko store krke rakh rha hai.. and hum har steo me map me dekh rhe hai.. pre^k avaiable hai. or uska count jitna hai.. usko ans me add krte ja rhe hai
