/*
Problem link: https://leetcode.com/problems/reverse-linked-list/
Solution link: https://takeuforward.org/data-structure/reverse-a-linked-list/
Solution video: https://www.youtube.com/watch?v=iRtLEoL-r-g&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=28
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
	ListNode* reverseList(ListNode* head) {
		ListNode *prev = NULL, *next = NULL;
		while (head != NULL) {
			next = head->next;
			head->next = prev;
			prev = head;
			head = next;
		}
		return prev;
	}
};

/*
Time Complexity:

Since we are iterating only once through the list and achieving reversed list. Thus, the time complexity is O(N) where N is the number of nodes present in the list.

Space Complexity:

To perform given tasks, no external spaces are used except three-pointers. So, space complexity is
O(1).
*/

/*
We will use three-pointers to traverse through the entire list and interchange links between nodes. One pointer to keep track of the current node in the list. The second one is to keep track of the previous node to the current node and change links. Lastly, a pointer to keep track of nodes in front of current nodes.

STEP 1:

currrent_p is a pointer to keep track of current nodes. Set it to head.
prev_p is a pointer to keep track of previous nodes. Set it to NULL.
next_p is a pointer to keep track of next nodes.
STEP 2:

Set next_p to point next node to node pointed by current_p.
Change link between nodes pointed by current_p and prev_p.
Update prev_p to current_p and current_p pointer to next_p.
Perform STEP 2 until current_p reaches the end of the list.

STEP 3:

Set head as prev_p. This makes the head point at the last node.

Dry Run:

At beginning,

As per this example, current_p points node with 3 and prev_p points to NULL

Now, we start iterating throughout the list until current_p has a value equal to NULL. Set next_p to the next node of the current_p pointed node present in the list.

Since the next node to current_p pointed node is B. Therefore next_p points to node B.

Now, interchange linking between nodes pointed by prev_p and next_p,i.e, node A and NULL. Then, prev_p moves to node A, current_p moves to B, and next_p to C.

Thus, at the first iteration, we pointed node A from node B to NULL.

In the second iteration, we point node B from node C to node A. Move next_p to node D, current_p to node C and prev_p to node A. This is performed by the same steps.

In the third iteration, we point node C from node D to node B. Move next_p to out of list, current_p to node D and prev_p to node C.

In the fourth iteration, we point node D from NULL to node C. Move current_p out of list and prev_p to node D.

Since current_p value is equal to NULL so iteration stops. We set head as prev_p.
Hence, we achieved our reversed list.
*/