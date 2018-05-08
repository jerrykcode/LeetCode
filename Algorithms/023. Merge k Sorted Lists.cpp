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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        List head = NULL, tail = NULL;
        while (1) {
            int minIndex = -1, flag = 0;                   
            for (int i = 0; i < lists.size(); i ++) {  
                if (lists[i] == NULL) continue;
                flag = 1;
                if (minIndex == -1 || lists[i]->val < lists[minIndex]->val) minIndex = i;
            }
            if (!flag) break;
            List tmp = new ListNode(lists[minIndex]->val);
            if (head == NULL) head = tmp;
            if (tail != NULL) tail->next = tmp;
            tail = tmp;
            lists[minIndex] = lists[minIndex]->next;
        }
        return head;
    }
};
