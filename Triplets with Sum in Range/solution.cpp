class Solution {
	public:
	int solve(vector<int>& arr, int tar) {
		int count = 0;
		
		for (int i = 0; i < arr.size(); i++) {
			int val = arr[i];
			int s = i + 1;
			int e = arr.size() - 1;
			while (s <= e) {
				if (val + arr[s] + arr[e] > tar) {
					e--;
				} else {
		            count += e - s;
		            s++;
				}
			}
		}
		
		return count;
	}
	
	int countTriplets(vector<int> &arr, int l, int r) {
		// code here
		int n = arr.size();
		sort(arr.begin(), arr.end());
		
		return solve(arr,r) - solve(arr,l-1);
	}
};

// 1 2 3 4 5 6


// 2 3 4 4 5 8
