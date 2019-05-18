/*1.ɾ�������е��ڸ���ֵ val �����нڵ㡣
ʾ��:
����: 1->2->6->3->4->5->6, val = 6
���: 1->2->3->4->5
*/

/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     struct ListNode *next;
* };
*/
struct ListNode* removeElements(struct ListNode* head, int val){
	struct ListNode* prev = NULL;
	struct ListNode* cur = head;
	struct ListNode* next;
	while (cur)
	{
		//��ǰ�ڵ��Ƿ���Ҫɾ���Ľڵ�
		if (cur->val == val)
		{
			//�Ȼ�ȡ��һ���ڵ�
			next = cur->next;
			//�ѵ�ǰ�ڵ�������ͷ�
			free(cur);
			//
			cur = next;
			//����
			if (prev == NULL)
			{
				head = next;
			}
			else
			{
				prev->next = next;
			}
		}
		else
		{
			//��ǰ�ڵ㲻��Ҫɾ���Ľڵ�
			//
			prev = cur;
			cur = cur->next;
		}
	}
	return head;
}


