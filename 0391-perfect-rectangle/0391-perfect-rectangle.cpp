class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        int n = rectangles.size();
        int minX = INT_MAX;
        int minY = INT_MAX;
        int maxX = INT_MIN;
        int maxY = INT_MIN;

        set<pair<int,int>>mp;
        for(auto ract : rectangles){
            int x = ract[0];
            int y = ract[1];
            int a = ract[2];
            int b = ract[3];

            minX = min(x, minX);
            minY = min(y, minY);
            maxX = max(a, maxX);
            maxY = max(b, maxY);
        }

        for(auto ract : rectangles){
            int x = ract[0];
            int y = ract[1];
            int a = ract[2];
            int b = ract[3];

            if(mp.count({x, y})){
                mp.erase({x, y});
            }else{
                mp.insert({x, y});
            }

            if(mp.count({x, b})){
                mp.erase({x, b});
            }else{
                mp.insert({x, b});
            }

            if(mp.count({a, y})){
                mp.erase({a, y});
            }else{
                mp.insert({a, y});
            }

            if(mp.count({a, b})){
                mp.erase({a, b});
            }else{
                mp.insert({a, b});
            }
        }

        if(mp.size() != 4){
            return false;
        }

        if(!mp.count({minX, minY}) || !mp.count({minX, maxY}) || !mp.count({maxX, minY}) || !mp.count({maxX, maxY})){
            return false;
        }

        __int128 region_area = (__int128)(maxX - minX) * (maxY - minY);

        __int128 total_area = 0;

        for(auto ract : rectangles){
            int x = ract[0];
            int y = ract[1];
            int a = ract[2];
            int b = ract[3];

            __int128 area = (__int128)(a - x) * (b - y);
            total_area += area;
        }

        return (total_area == region_area);

        // return true;
    }
};

// miny = 1, minx = 1, maxy = 4, maxx = 4

// step 1 check all the points in boundary or not
// if step 2 true than calculate the total sum of ractangles
// if total_sum == coverarea sum than true otherwise false;

// 0 0 1 1
// 0 1 3 2
// 1 0 2 2

// 0 0 