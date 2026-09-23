class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n = tasks.size();

        auto comp = [](vector<int>& a, vector<int>& b) {
            if (a[0] == b[0]) {
                return a[2] > b[2];
            }
            return a[0] > b[0];
        };

        priority_queue<vector<int>, vector<vector<int>>, decltype(comp)>
            min_heap(comp);

        for (int i = 0; i < n; i++) {
            tasks[i].push_back(i);
        }

        sort(tasks.begin(), tasks.end());
        // for(int i = 0; i < n; i++){
        //     cout<<tasks[i][0]<<" "<<tasks[i][1]<<" "<<tasks[i][2]<<endl;
        // }

        vector<int> ans;
        int index = 0;
        long long time = tasks[index][0];
        while (!min_heap.empty() || index < n) {
            while (index < n && tasks[index][0] <= time) {
                min_heap.push({tasks[index][1], tasks[index][0], tasks[index][2]});
                index++;
            }
            
            if (min_heap.empty()) {
                time = tasks[index][0];
                continue;
            }
            
            auto arr = min_heap.top();
            min_heap.pop();
            int p = arr[0];
            int e = arr[1];
            int idx = arr[2];

            time += p;

            ans.push_back(idx);
        }
        
        return ans;
    }
};