class TopVotedCandidate {
public:
    vector<int>prefix;
    vector<int>t;
    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        int n = persons.size();
        t.resize(n, 0);

        for(int i = 0; i < n; i++){
            t[i] = times[i];
        }

        prefix.resize(n, 0);
        unordered_map<int,int>freq;
        int maxi = INT_MIN;
        int max_freq_ele = -1;

        for(int i = 0; i < n; i++){
            freq[persons[i]]++;

            if(maxi <= freq[persons[i]]){
                maxi = freq[persons[i]];
                max_freq_ele = persons[i];
            }

            prefix[i] = max_freq_ele;
        }
    }

    int binary_search(int target){
        int l = 0;
        int h = t.size()-1;
        int ans = prefix[0];

        while(l <= h){
            int mid = l + (h - l)/2;

            if(t[mid] <= target){
                ans = prefix[mid];
                l = mid + 1;
            }else{
                h = mid - 1;
            }
        }

        return ans;
    }
    
    int q(int t) {
        int ans = binary_search(t);

        return ans;
    }
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */