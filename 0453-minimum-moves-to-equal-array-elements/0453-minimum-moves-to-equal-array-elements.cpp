class Solution {
public:
    int minMoves(vector<int>& nums) {
        int ans = 0;
        int small = INT_MAX;

        for(int &num : nums)
        {
            small = min(num,small);
        }

        for(int &num : nums)
        {
            ans += num - small;
        }

        return ans;
    }
};

/*
1 2 5 7 -> 7 8 11 7 -> 11 12 11 11 -> 12 12 12 12
8
2 3 6
3 4 7
4 5 7 8
5 6 8 8
6 7 8 9
7 8 9 9
8 9 9 10
9 10 10 10
10 11 11 10
11 11 11 12
12 12 12 12
*/