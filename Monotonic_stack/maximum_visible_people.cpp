//Problem statement
// You are given an array arr[ ], where arr[i] represents the height of the ith person standing in a line.
// A person i can see another person j if:
// height[j] < height[i],
// There is no person k standing between them such that height[k] ≥ height[i].
// Each person can see in both directions (front and back).
// Your task is to find the maximum number of people that any person can see (including themselves).

class Solution {
  public:
    int maxPeople(vector<int> &arr) {
        // code here
        // initialize the array size
        int n = arr.size();
        
        // initialize stack, and vectors for left and right
        stack<pair<int,int>>st;
        vector<int>L(n,1);
        vector<int>R(n,1);
        
        // finding a how much people a person see to there left at each postion
        for(int i = 0; i < n; i++){
            while(!st.empty() && st.top().first < arr[i]){
                L[i] += L[st.top().second];
                st.pop();
            }
            
            st.push({arr[i], i});
        }
        
        // clear the stack to use for right also
        while(!st.empty()){
            st.pop();
        }
        
        //finding a how much people a person see to there right at each postion
        for(int i = n-1; i >= 0; i--){
            while(!st.empty() && st.top().first < arr[i]){
                R[i] += R[st.top().second];
                st.pop();
            }
            
            st.push({arr[i], i});
        }
        
        
        // intialize a max_people variable that is the answer
        int max_people = INT_MIN;
        
        // finding the maximum visible persons
        for(int i = 0; i < n; i++){
            max_people = max(max_people , L[i] + R[i] - 1);
        }
        
        return max_people;
    }
};

// Intution behind the problem 
// You think about that is standing in a line and at each position How much persons he can from his left and from his right 
// and the person that has small height than another person he can be see by another person so there we have to only check how much person he can see
// for this type of questions we can think of monotonic stack that gives me the right greater or right smakker or same of left.
// this problem is totally depend upon Monotonic stack 
