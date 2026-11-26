class Solution {
public:
    bool canAliceWin(int n) {
        int turn = 0;
        int stones = 10;

        while(n >= stones){
            n -= stones;
            stones--;
            turn++;
        }

        // cout<<turn<<endl;

        return turn % 2 == 1;
    }
};