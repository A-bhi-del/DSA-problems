class Solution {
public:
    string convert_DTB(int num){
        int copy = num;

        string binary = "";

        while(copy > 0){
            int digit = copy % 2;
            binary += digit + '0';

            copy = copy/2;
        }

        reverse(binary.begin(), binary.end());

        return binary;
    }

    bool check_palindrome(string& str){
        int i = 0;
        int j = str.length()-1;

        while(i <= j){
            if(str[i] != str[j]){
                return false;
            }
            i++;
            j--;
        }

        return true;
    }

    vector<int> minOperations(vector<int>& nums) {
        vector<int>ans;

        for(int num : nums){
            for(int k = 0; k <= 5000; k++){
                string binary_chota = convert_DTB(max(num-k, 0));

                string binary_bada = convert_DTB(num + k);

                bool is_palindrome_chota = check_palindrome(binary_chota);

                bool is_palindrome_bada = check_palindrome(binary_bada);

                if(is_palindrome_bada || is_palindrome_chota){
                    ans.push_back(k);
                    break;
                }
            }
        }

        return ans;
    }
};