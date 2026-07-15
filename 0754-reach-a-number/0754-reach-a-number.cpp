class Solution {
public:
    int reachNumber(int target) {
        target = abs(target);
        int series = 0;

        while(target > 0){
            series++;
            target -= series;
        }

        if(target % 2 == 0){
            return series;
        }

        return series + 1 + series % 2; 
    }
};
// 1 -> 3 -> 7 -> 