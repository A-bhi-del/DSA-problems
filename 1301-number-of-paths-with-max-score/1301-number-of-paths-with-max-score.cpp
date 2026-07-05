class Solution {
public:
    unordered_map<int, int>mp;
    int mod = 1e9+7;
    pair<int,int> dp[101][101];
    bool vis[101][101];

    pair<int,int> solve(int r, int c, vector<string>& board){
        if(r < 0 || c < 0 || board[r][c] == 'X'){
            return {-1, 0};
        }

        if(r == 0 && c == 0){
            return {0, 1};
        }

        if(vis[r][c]){
            return dp[r][c];
        }

        vis[r][c] = true;

        pair<int,int>left = solve(r, c-1, board);
        pair<int,int>up = solve(r-1, c, board);
        pair<int,int>UpLeft = solve(r-1, c-1, board);

        int maxi = max({left.first, up.first, UpLeft.first});

        if(maxi == -1){
            return dp[r][c] = {-1, 0};
        }

        long long ways = 0;

        if(left.first == maxi){
            ways = (ways + left.second) % mod;
        }

        if(up.first == maxi){
            ways = (ways + up.second) % mod;
        }

        if(UpLeft.first == maxi){
            ways = (ways + UpLeft.second) % mod;
        }

        int val = 0;
        if(board[r][c] >= '0' && board[r][c] <= '9'){
            val = (board[r][c] - '0');
        }

        return dp[r][c] = {(maxi + val) % mod,(int)ways};
    }

    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n = board.size();
        int m = board[0].length();

        auto ans = solve(n-1, m-1, board);

        if(ans.first == -1){
            return {0,0};
        }

        return {ans.first, ans.second};
    }
};