/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
typedef ListNode*List;
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        List head(NULL);
        List tail(NULL);
        while (l1 != NULL && l2 != NULL) {
            List tmp;
            if (l1 -> val < l2-> val){
                tmp = l1;
                l1 = l1-> next;
            } else {
                tmp = l2;
                l2 = l2->next;
            }
            if (!head) head = tmp;
            else tail->next = tmp;
            tail = tmp;
            tail->next = NULL;
        } // while
        if (l1) {
            if (!head) 
                head = l1;
            else
                tail->next = l1;
        }
        if (l2) {
            if (!head)
                head = l2;
            else
                tail->next = l2;
        }
    return head;
    } 
    
};
