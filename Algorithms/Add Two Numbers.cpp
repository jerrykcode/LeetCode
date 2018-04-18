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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		int k = 0;
		List head = NULL, tail = NULL;
		while (l1 != NULL && l2 != NULL) {
			int val = (l1->val + l2->val + k) %10;
			k = (l1->val + l2->val + k)/10;
			List tmp = new ListNode(val);
			if (head == NULL) head = tmp;
			if (tail != NULL) tail->next = tmp;
			tail = tmp;
			l1 = l1->next;
			l2 = l2->next;
		}
		while (l1 != NULL) {
			List tmp = new ListNode((l1->val + k)%10);
			if (head == NULL) head = tmp;
			if (tail != NULL) tail->next = tmp;
			tail = tmp;
			k = (l1->val + k)/10;
			l1 = l1->next;
		}
		while (l2 != NULL) {
			List tmp = new ListNode((l2->val + k)%10);
			if (head == NULL) head = tmp;
			if (tail != NULL) tail->next = tmp;
			tail = tmp;
			k = (l2->val + k)/10;
			l2 = l2->next;
		}
		if (k != 0) {
			List tmp = new ListNode(k);
			if (head == NULL) head = tmp;
			if (tail != NULL) tail->next = tmp;
			tail = tmp;
		}
		return head;
    }
};

/* TEST

List input(int size) {
	List head = NULL, tail = NULL;
	for (int i = 0; i < size; i ++) {
		int item;
		cin>>item;
		List tmp = new ListNode(item);
		if (head == NULL) head = tmp;
		if (tail != NULL) tail->next = tmp;
		tail = tmp;
	}
	return head;
}

void print(List l) {
	while (l != NULL) {
		cout << l->val;
		l = l->next;
	}
}

int main()
{
	List l1, l2;
	int size1, size2;
	cin>>size1>>size2;
	l1 = input(size1);
	l2 = input(size2);
	Solution * s = new Solution;
	print(s->addTwoNumbers(l1, l2));
	return 0;
}
*/
