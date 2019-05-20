//����һ������ͷ��� head �ķǿյ���������������м��㡣
//����������м��㣬�򷵻صڶ����м��㡣
//Definition for singly-linked list.
struct ListNode {
	int val;
	struct ListNode *next;
};

struct ListNode* middleNode(struct ListNode* head){
	struct ListNode* slow = head;
	struct ListNode* fast = head;
	while (fast && fast->next)
	{
		fast = fast->next->next;
		slow = slow->next;
	}
	return slow;
}

/*��תһ��������
ʾ�� :
���� : 1->2->3->4->5->NULL
��� : 5->4->3->2->1->NULL*/
//Definition for singly-linked list.
struct ListNode {
	int val;
	struct ListNode *next;
};

struct ListNode* reverseList(struct ListNode* head) {
	struct ListNode* prev = NULL;
	struct ListNode* cur = head;
	struct ListNode* next;
	while (cur)
	{
		next = cur->next;
		cur->next = prev;
		prev = cur;
		cur = next;
	}
	return prev;
}