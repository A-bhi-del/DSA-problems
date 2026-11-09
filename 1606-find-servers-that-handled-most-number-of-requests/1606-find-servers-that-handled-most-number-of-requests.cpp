class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        int n = arrival.size();

        set<int>book_st;

        for(int i = 0; i < k; i++){
            book_st.insert(i);
        }

        vector<int>req_pr_server(k, 0);

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>min_heap;

        for(int i = 0; i < n; i++){
            int time = arrival[i];

            while(!min_heap.empty() && min_heap.top().first <= time){
                int sv = min_heap.top().second;
                min_heap.pop();
                book_st.insert(sv);
            }

            int tar = i % k;

            auto it = book_st.lower_bound(tar);

            if(it == book_st.end()){
                it = book_st.begin();
            }

            if(book_st.empty()){
                continue;
            }

            int tar_sv = *it;

            book_st.erase(it);

            min_heap.push({arrival[i] + load[i], tar_sv});

            req_pr_server[tar_sv]++;
        }

        vector<pair<int,int>>reqserver;

        for(int i = 0; i < k; i++){
            reqserver.push_back({req_pr_server[i], i});
        }

        sort(reqserver.begin(), reqserver.end(), [](const pair<int,int>&a, const pair<int,int>&b){
            return a.first > b.first;
        });

        vector<int>ans;
        ans.push_back(reqserver[0].second);

        for(int i = 1; i < reqserver.size(); i++){
            if(reqserver[i].first == reqserver[0].first){
                ans.push_back(reqserver[i].second);
            }
        }

        return ans;
    }
};