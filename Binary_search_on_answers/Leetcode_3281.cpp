// You are given an array of integers start and an integer d, representing n intervals [start[i], start[i] + d].
// You are asked to choose n integers where the ith integer must belong to the ith interval. The score of the chosen integers is defined as the minimum absolute difference between any two integers that have been chosen.
// Return the maximum possible score of the chosen integers.

// Greedy + Binary_search
class Solution {
public:
    bool BS_check(vector<int>& start, int mid, int d){
        long long prev = start[0];

        for(int i = 1; i < start.size(); i++){
            long long int next=max(prev+mid, static_cast<long long>(start[i]));

            if(next > start[i] + d){
                return false;
            }

            prev = next;
        }

        return true;
    }

    int maxPossibleScore(vector<int>& start, int d) {
        sort(start.begin(), start.end());
        int n = start.size();
        int ans = -1;

        int low = 0;
        int high = start.back() + d - start[0];

        while(low <= high){
            int mid = low + (high - low)/2;

            if(BS_check(start, mid, d)){
                ans = mid;
                low = mid + 1;
            }else{
                high = mid - 1;
            }
        }

        return ans;
    }
};