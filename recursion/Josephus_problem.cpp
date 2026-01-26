// // You are playing a game with n people standing in a circle, numbered from 1 to n. Starting from person 1, every kth person is eliminated in a circular fashion. The process continues until only one person remains.
// Given integers n and k, return the position (1-based index) of the person who will survive.
class Solution {
  public:
    int jp(int n, int k){
        if(n == 1){
            return 0;
        }
        
        return (jp(n-1, k) + k)%n;
    }
    
    int josephus(int n, int k) {
        // code here
        return jp(n,k) + 1;
    }
};

// 1 2 3  4  5  6  7  8  9  10 11 12 13
// 1 2 3  5  6  7  9  10 11 13
// 1 2 5  6  7  10 11 13
// 2 5 6  10 11 13
// 5 6 10 13
// 5 6 13
// 5 6 
// 5
