/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

typedef ListNode * List;
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        List p0 = head;
        List p1 = head;
        List pre = NULL;
        for (int i = 0; i < n; i ++)
            p1 = p1->next;
        while (p1 != NULL) {
            p0 = p0->next;
            p1 = p1->next;
            pre = pre == NULL ? head : pre->next;
        }
        //Delete p0
        if (pre == NULL)
            return head->next; //p0 = head
        pre->next = p0->next;
        return head;
    }
};
