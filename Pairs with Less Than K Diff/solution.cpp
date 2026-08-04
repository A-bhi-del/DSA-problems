class Solution {
	public:
	int countPairs(vector<int>& arr, int k) {
		// code here
		sort(arr.begin(), arr.end());
		int n = arr.size();
		if (n == 1) return 0;
		int ans = 0;
		int j = 0;
		
		for (int i = 0; i < n; i++) {
		    while(j < n && arr[i] - arr[j] >= k){
		        j++;
		    }
		    
			if(arr[i] - arr[j] < k){
			 //   cout<<i<<" "<<j<<endl;
			    ans += (i - j);
			}
		}
		
// 		int len = n - j;
// 		ans += (len * (len - 1))/2;
		
		return ans;
	}
};

// 9 10 10
