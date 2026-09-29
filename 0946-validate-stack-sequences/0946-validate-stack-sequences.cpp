class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int n = pushed.size();

        stack<int>st;
        st.push(pushed[0]);
        int i = 1;
        int j = 0;

        while(!st.empty() && i < n && j < n){
            while(!st.empty() && st.top() == popped[j] && j < n){
                st.pop();
                j++;
            }

            st.push(pushed[i]);
            i++;
        }

        while(!st.empty() && st.top() == popped[j] && j < n){
            st.pop();
            j++;
        }

        if(st.empty()){
            return true;
        }

        return false;
    }
};