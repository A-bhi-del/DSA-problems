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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        int node = 1;
        ListNode* tempa = NULL;
        ListNode* tempb = NULL;

        ListNode* head = list1;
        while(head != NULL){
            if(node == a){
                tempa = head;
            }else if(node == b+1){
                tempb = head->next;
                break;
            }
            node++;
            head = head->next;
        }

        ListNode* head2 = list2;

        if(tempa != NULL){
            tempa->next = head2;
        }

        while(head2->next != NULL){
            head2 = head2->next;
        }

        head2->next = tempb;

        return list1;
    }
};