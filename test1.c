/*1.删除链表中等于给定值 val 的所有节点。
示例:
输入: 1->2->6->3->4->5->6, val = 6
输出: 1->2->3->4->5
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
		//当前节点是否是要删除的节点
		if (cur->val == val)
		{
			//先获取下一个节点
			next = cur->next;
			//把当前节点的内容释放
			free(cur);
			//
			cur = next;
			//重新
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
			//当前节点不是要删除的节点
			//
			prev = cur;
			cur = cur->next;
		}
	}
	return head;
}


