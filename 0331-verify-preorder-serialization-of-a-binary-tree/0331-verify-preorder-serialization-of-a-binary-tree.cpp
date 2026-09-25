class Solution {
public:
    bool isValidSerialization(string preorder) {
        int n = preorder.length();
        vector<string>pre;
        string str = "";

        for(int i = 0; i < n; i++){
            str += preorder[i];
            if(preorder[i] == ','){
                str.pop_back();
                pre.push_back(str);
                str = "";
            }
        }
        
        pre.push_back(str);
        
        int slots = 1;

        for(int i = 0; i < pre.size(); i++){
            if(slots <= 0){
                return false;
            }

            if(pre[i] != "#"){
                slots += 2;
            }

            slots--;
        }

        return slots == 0;
    }
};

// 2 
























