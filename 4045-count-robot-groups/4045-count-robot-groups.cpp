class Solution {
public:
    int countGroups(vector<int>& position, vector<int>& speed, int distance) {
        int n = speed.size();
        int groups = 1;

        int mini = speed[n-1];

        for(int i = n-2; i >= 0; i--){
            if(speed[i] <= mini && position[i+1] - position[i] > distance){
                groups++;
                mini = speed[i];
            }
        }
        
        return groups;
    }
};