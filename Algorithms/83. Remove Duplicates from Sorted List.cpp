/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
typedef ListNode *List;
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL) return NULL;
        List p0 = head, p1 = head->next;
        while (p1 != NULL) {
            if (p1->val == p0->val) {
                p0->next = p1->next;
            } 
            else p0 = p1;
            p1 = p1->next;   
        }
        return head;
    }
};