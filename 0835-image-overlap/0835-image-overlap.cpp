class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        vector<pair<int,int>> ones1, ones2;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(img1[i][j] == 1) ones1.push_back({i, j});
            }
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(img2[i][j] == 1) ones2.push_back({i, j});
            }
        }

        unordered_map<int, int> mp; 
        int max_overlap = 0;

        for(auto it1 : ones1){
            for(auto it2 : ones2){
                int x = it1.first - it2.first;
                int y = it1.second -it2.second;
                int key = x * 200 + y; 
                mp[key]++;
                max_overlap = max(max_overlap, mp[key]);
            }
        }

        return max_overlap;
    }
};

/*
0 1 1 1
0 1 1 1
0 1 1 1
0 0 0 0 

0 0 0 0
1 1 1 0
1 1 1 0
1 1 1 0

1 0 
1 0

0 1 
1 0
*/