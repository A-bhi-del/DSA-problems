class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        sort(arr.begin(), arr.end());
        priority_queue<int, vector<int>, greater<int>> min_heap;

        int n = arr.size();

        int count = 1;
        for(int i = 0; i < n-1; i++){
            if(arr[i] == arr[i+1]){
                count++;
            }else{
                min_heap.push(count);
                count = 1;
            }
        }

        min_heap.push(count);

        while(!min_heap.empty() && (k > 0)){
            if(k >= min_heap.top()){
                k -= min_heap.top();
                min_heap.pop();
            }else{
                break;
            }
        }
        
        return min_heap.size();
    }
};

// 1 1 2 3 3 3 4

        // while(!min_heap.empty()){
        //     cout<<min_heap.top()<<endl;
        //     min_heap.pop();
        // }