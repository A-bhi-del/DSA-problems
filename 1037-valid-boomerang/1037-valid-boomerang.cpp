class Solution {
public:
    bool isBoomerang(vector<vector<int>>& points) {
        int a = points[0][0];
        int a2 = points[0][1];
        int b = points[1][0];
        int b2 = points[1][1];
        int c = points[2][0];
        int c2 = points[2][1];

        int area = abs(a*(b2-c2) + b*(c2-a2) + c*(a2-b2));

        if(area != 0){
            return true;
        }

        return false;
    }
};