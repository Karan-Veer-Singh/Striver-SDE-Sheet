/*
Problem link: https://leetcode.com/problems/delete-node-in-a-linked-list/
Solution link: https://takeuforward.org/data-structure/delete-given-node-in-a-linked-list-o1-approach/
Solution video: https://www.youtube.com/watch?v=icnp4FJdZ_c&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=32
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
	void deleteNode(ListNode* node) {
		*node = *(node -> next);
	}
};

/*
Time Complexity: O(1)
Reason: It is a two-step process that can be obtained in constant time.

Space Complexity: O(1)
Reason: No extra data structure is used.
*/

/*
Approach:

We are given access to nodes that we have to delete from the linked list. So, whatever operation we want to do in the linked list, we can operate in the right part of the linked list from the node to be deleted.

The approach is to copy the next node’s value in the deleted node. Then, link node to next of next node. This does not delete that node but indirectly it removes that node from the linked list.

*/