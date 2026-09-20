class Solution {
public:
    int nextGreaterElement(int n) {
        vector<int>ac_digits;

        while(n > 0){
            int num = n % 10;
            ac_digits.push_back(num);
            n = n / 10;
        }

        reverse(ac_digits.begin(), ac_digits.end());
        int size = ac_digits.size();
        int idx = -1;

        for(int i = size - 1; i >= 0; i--){
            for(int j = size-1; j > i; j--){
                if(ac_digits[i] < ac_digits[j]){
                    swap(ac_digits[i], ac_digits[j]);
                    idx = i;
                    break;
                }
            }
            if(idx != -1){
                break;
            }
        }

        cout<<idx<<endl;

        if(idx != -1){
            sort(ac_digits.begin() + idx + 1, ac_digits.end());
        }else{
            return -1;
        }

        long long ans = 0;

        for(int i = 0; i < size; i++){
            ans = ans * 10 + ac_digits[i];
        }

        if(ans > INT_MAX){
            return -1;
        }

        return (int)ans;
    }
};

// 1 2