class Solution {
public:
    int n, m;
    void rev(vector<vector<int>>& grid, int s, int e){
        while(s < e){
            int i1 = s / m;
            int j1 = s % m;
            int i2 = e / m;
            int j2 = e % m;

            swap(grid[i1][j1], grid[i2][j2]);
            s++;
            e--;
        }
    }
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        n = grid.size();
        m = grid[0].size();
        int size = n*m;
        k = k % (n*m);

        rev(grid, 0, size-1);
        rev(grid, 0, k-1);
        rev(grid, k, size-1);

        return grid;
    }
};