class Solution {
public:
    int kthFactor(int n, int k) {
        vector<int>start_half;
        vector<int>end_half;

        for(int i = 1; i*i <= n; i++){
            if(n % i == 0){
                start_half.push_back(i);

                if(i != n/i){
                    end_half.push_back(n/i);
                }
            }
        }

        int n1 = start_half.size();
        int n2 = end_half.size();

        if(n1 + n2 < k){
            return -1;
        }

        if(k <= n1){
            return start_half[k-1];
        }

        k = k - n1;

        // cout<<"i am safe"<<endl;

        return end_half[n2 - k];
    }
};