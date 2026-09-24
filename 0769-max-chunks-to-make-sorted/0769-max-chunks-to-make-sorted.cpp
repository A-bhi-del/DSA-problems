class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();

        int chunks = 1;

        vector<pair<int, int>>temp;

        for(int i = 0; i < n; i++){
            temp.push_back({arr[i], i});
        }

        sort(temp.begin(), temp.end());

        vector<pair<int,int>>inter;

        for(int i = 0; i < n; i++){
            inter.push_back({min(i, temp[i].second), max(i, temp[i].second)});
        }

        sort(inter.begin(), inter.end(), [](pair<int,int>& a, pair<int, int>& b){
            if(a.first == b.first){
                a.second > b.second;
            }
            return a.first < b.first;
        });

        // for(int i = 0; i < n; i++){
        //     cout<<inter[i].first<<" "<<inter[i].second<<endl;
        // }

        int e = inter[0].second;

        for(int i = 1; i < n; i++){
            if(e < inter[i].first){
                chunks++;
            }

            e = max(e, inter[i].second);
        }

        return chunks;
    }
};

// 2 3 1 0 5 4