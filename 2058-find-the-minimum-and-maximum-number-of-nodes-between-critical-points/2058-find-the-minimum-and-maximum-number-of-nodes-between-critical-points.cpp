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
        ListNode* temp = head; 
        int p = -1;
        int c = -1;  
        int mini = INT_MAX;     
        int f = INT_MAX;
        int la = -1;
        int l = 1;

        while(temp->next != NULL && temp->next->next != NULL){
            int prev = temp->val;
            int mid = temp->next->val;
            int aft = temp->next->next->val;

            if((prev < mid && aft < mid) || (prev > mid && aft > mid)){
                p = c;
                c = l + 1;
                f = min(f, l+1);
                la = max(la, l+1);
                if(p != -1 && c != -1){
                    mini = min(mini, c - p);
                }
            }

            temp = temp->next;
            l++;
        }

        if(p == -1 || c == -1){
            return {-1,-1};
        }

        return {mini, la-f};
    }
};