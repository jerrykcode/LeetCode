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
    //leetcode Note: You may not modify the values in the list's nodes, only nodes itself may be changed.
    //不改变结点的值，改变结点本身。
    ListNode* swapPairs(ListNode* head) {
        List p = head, pnext = NULL, ppre = NULL; 
        while (p != NULL && p->next != NULL) {
            pnext = p->next;
            List tmp = pnext->next;
            pnext->next = p;
            if (ppre == NULL)
                head = pnext;
            else ppre->next = pnext;
            ppre = p;
            p = tmp;
        }
        if (p != NULL) {
            if (ppre == NULL) head = p;
            else {
                ppre->next = p;
                ppre = p;
            }
        }
        if (ppre != NULL) ppre->next = NULL;
        return head;
    }
};
