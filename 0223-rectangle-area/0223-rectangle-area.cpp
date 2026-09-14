class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int top_x1 = min(ax2, bx2);
        int top_y1 = min(ay2, by2);
        int bo_x1 = max(ax1, bx1);
        int bo_y1 = max(ay1, by1);

        int area = (top_x1 - bo_x1) * (top_y1 - bo_y1);

        int total_area = (ax2 - ax1) * (ay2 - ay1) + (bx2 - bx1) * (by2 - by1);

        if(ay1 >= by2 || ax1 >= bx2 || ax2 <= bx1 || ay2 <= by1){
            return total_area;
        }

        return total_area - area;
    }
};