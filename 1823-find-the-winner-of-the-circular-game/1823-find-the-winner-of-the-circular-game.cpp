class Solution {
public:
    
    int solve(int k, int idx, vector<int>& person){
        if(person.size() == 1){
            return person[0];
        }

        idx = (idx + k) % person.size();
        person.erase(person.begin() + idx);

        return solve(k, idx, person);
    }

    int findTheWinner(int n, int k) {
        vector<int>person;
        for(int i = 1; i <= n; i++){
            person.push_back(i);
        }
        return solve(k-1, 0, person);
    }
};