/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        // if(!head->next || !head->next->next){
        //     return {-1,-1};
        // }
        vector<int>ans;
        ListNode* temp = head;
        int l = 1;

        while(temp->next != NULL && temp->next->next != NULL){
            int prev = temp->val;
            int mid = temp->next->val;
            int aft = temp->next->next->val;

            if((prev < mid && aft < mid) || (prev > mid && aft > mid)){
                ans.push_back(l+1);
            }

            temp = temp->next;
            l++;
        }

        if(ans.size() < 2){
            return {-1,-1};
        }

        int mini = INT_MAX;

        for(int i = 1; i < ans.size(); i++){
            mini = min(mini, ans[i] - ans[i-1]);
        }

        return {mini, ans[ans.size()-1] - ans[0]};
    }
};