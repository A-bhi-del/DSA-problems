class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        vector<int>freq(10, 0);

        for(int val : digits){
            freq[val]++;
        }

        int ans = 0;

        for(int i = 0; i < 10; i++){
            if(freq[i] == 0 || i % 2 == 1) continue;

            vector<int>temp = freq;
            temp[i]--;

            int count = 0;
            int gre_1 = 0;
            bool is_zero = false;

            if(temp[0] > 0){
                is_zero = true;
            }

            for(int j = 0; j < 10; j++){
                if(temp[j] > 0){
                    count++;
                }

                if(temp[j] > 1 && j != 0){
                    gre_1++;
                }
            }

            if(is_zero){
                ans += (count - 1) * (count - 1) + gre_1;
            }else{
                ans += count * (count - 1) + gre_1;
            }
        }

        return ans;
    }
};

// 1 3 2 2 4
// 6 + 12 

// 124, 214, 224, 324, 234, 134, 314

// 1 2 2 2 4
// 2 + 1 + 6 + 1 

// 1 0 2 2 3 3 4
// 9 + 2 + 16 + 1 + 12 + 2