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
    ListNode* sortList(ListNode* head) {
        if (head == NULL) return NULL;
        vector<List> lists;
        for (List i = head; i != NULL; i = i->next) {
            lists.push_back(i);
        }
        sort(lists.begin(), lists.end(), compare);
        head = lists[0];
        List tail = head;
        for (int i = 1; i < lists.size(); i++, tail = tail->next)
            tail->next = lists[i]; 
        tail->next = NULL;
        lists.clear();
        vector<List>().swap(lists);
        return head;
    }
private:
    static bool compare(List a, List b) {
        return a->val < b->val;
    }
};