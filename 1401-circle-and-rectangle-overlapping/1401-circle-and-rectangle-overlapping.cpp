class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        int closeX = max(x1, min(xCenter, x2));
        int closeY = max(y1, min(yCenter, y2));

        if((closeX - xCenter) * (closeX - xCenter) + (closeY - yCenter) * (closeY - yCenter) <= radius * radius){
            return true;
        }

        return false;
    }
};
 