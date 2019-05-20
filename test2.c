//给定一个带有头结点 head 的非空单链表，返回链表的中间结点。
//如果有两个中间结点，则返回第二个中间结点。
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

/*反转一个单链表。
示例 :
输入 : 1->2->3->4->5->NULL
输出 : 5->4->3->2->1->NULL*/
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