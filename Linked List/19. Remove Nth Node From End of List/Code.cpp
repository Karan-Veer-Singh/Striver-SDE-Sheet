/*
Problem link: https://leetcode.com/problems/remove-nth-node-from-end-of-list/
Solution link: https://takeuforward.org/data-structure/remove-n-th-node-from-the-end-of-a-linked-list/
Solution video: https://www.youtube.com/watch?v=Lhu3MsXZy-Q&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=31
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		ListNode *dummy = new ListNode(0);
		dummy->next = head;
		ListNode *slow = dummy;
		ListNode *fast = dummy;

		for (int i = 1; i <= n; i++)
			fast = fast->next;

		while (fast->next != NULL) {
			fast = fast->next;
			slow = slow->next;
		}

		slow->next = slow->next->next;
		return dummy->next;
	}
};

/*
Time Complexity: O(N)
Space Complexity: O(1)
*/

/*
Intuition :

What if we had to modify the same above approach to work in just one traversal? Let’s see what all information we have here:

We have the flexibility of using two-pointers now.
We know, the n-th node from the end is the same as (total nodes – n)th node from start.
But, we are not allowed to calculate total nodes, as we can do only one traversal.
What if, one out of the two-pointers is at the nth node from start instead of end? Will it make anything easier for us?

Yes, with two pointers in hand out of which one at n-th node from start, we can just advance both of them till end simultaneously, once the faster reaches the end, the slower will stand at the n-th node from the end.

Approach :

Take two dummy nodes, who’s next will be pointing to the head.
Take another node to store the head, initially it,s a dummy node(start), and the next of the node will be pointing to the head.The reason why we are using this extra dummy node, is because there is an edge case. If the node is equal to the length of the linkedlist, then this slow’s will point to slow’s next→ next. And we can say our dummy start node will be broken, and will be connected to the slow’s next→ next.
Start traversing until the fast pointer reaches the nth node.

Now start traversing by one step both of the pointers until the fast pointers reach the end.

When the traversal is done, just do the deleting part. Make  slow pointer’s next to the next of next of the slow pointer to ignore/disconnect the given node.

Last, return the next of start.
*/