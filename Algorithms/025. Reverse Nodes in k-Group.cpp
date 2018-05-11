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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == NULL || k == 1) return head; //不用反转
        int len = getLength(head);
        if (len < k) return head; //不用反转
        List head0 = NULL, head1, p, q, tmp;
        for (int i = 0; i < len / k; i ++) {
            p = (i == 0) ? head : tmp;
            head1 = p;
            q = p->next;
            for (int j = 0; j < k - 1; j ++) { //反转 k - 1 次
                tmp = q->next;
                q->next = p;
                p = q;
                q = tmp;
            }
            //此时p为反转后的k个结点组成的链表的头指针，之前未进行过反转则赋值给head，否则赋给head0，即
            //上一次反转k个结点组成的链表的尾指针，然后head0 = head1，即更新head0为这次反转k个结点组成的链表的尾指针。
            if (head0 != NULL) head0->next = p;
            else head = p;
            head0 = head1;
        }
        head0->next = tmp;
        return head;
    }
private:
    int getLength(List head) {
        int len = 0;
        for (; head; head = head->next, len++);
        return len;
    }
};
