class Solution {
public:
    string Justified(vector<string>& temp, int spaces){
        int total_elements = temp.size();
        string ans = "";
        if(total_elements == 1){
            ans += temp[0];
            for(int i = 0; i < spaces; i++){
                ans += " ";
            }

            return ans;
        }

        int gap = spaces/(total_elements-1);
        int extra = spaces % (total_elements-1);

        for(string word : temp){
            ans += word;
            if(spaces > 0){
                for(int i = 0; i < gap; i++){
                    ans += " ";
                }
            }

            spaces -= gap;
            if(extra > 0){
                ans += " ";
                extra--;
                spaces--;
            }
        }

        return ans;
    }

    string Last_Line_Justified(vector<string>& temp, int spaces){
        string ans = "";

        for(string word : temp){
            ans += word;
            if(spaces > 0){
                ans += " ";
                spaces--;
            }
        }

        for(int i = 0; i < spaces; i++){
            ans += " ";
        }

        return ans;
    }

    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string>ans;
        string res = "";
        vector<string>temp;
        int total_len = 0;
        int count = 0;

        for(string word : words){

            if(total_len+word.length() <= maxWidth && count <= (maxWidth-total_len - word.length())){
                temp.push_back(word);
            }else{
                string str = Justified(temp, maxWidth-total_len);
                temp.clear();
                ans.push_back(str);
                total_len = 0;
                count = 0;
                temp.push_back(word);
            }

            total_len += word.length();
            count++;
        }

        cout<<maxWidth-total_len<<endl;
        string str = Last_Line_Justified(temp, maxWidth-total_len);

        ans.push_back(str);
        
        return ans;
    }
};