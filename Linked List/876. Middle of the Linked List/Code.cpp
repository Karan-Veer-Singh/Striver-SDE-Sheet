/*
Problem link: https://leetcode.com/problems/middle-of-the-linked-list/
Solution link: https://takeuforward.org/data-structure/find-middle-element-in-a-linked-list/
Solution video: https://www.youtube.com/watch?v=sGdwSH8RK-o&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=29
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
	ListNode* middleNode(ListNode* head) {
		ListNode *slow = head, *fast = head;
		while (fast != NULL && fast->next != NULL) {
			fast = fast->next->next;
			slow = slow->next;
		}
		return slow;
	}
};

/*
Time Complexity: O(N)
Space Complexity: O(1)
*/

/*

Intuition: In the Tortoise-Hare approach, we increment slow ptr by 1 and fast ptr by 2, so if take a close look fast ptr will travel double than that of the slow pointer. So when the fast ptr will be at the end of Linked List, slow ptr would have covered half of Linked List till then. So slow ptr will be pointing towards the middle of Linked List.

Approach:

Create two pointers slow and fast and initialize them to a head pointer.
Move slow ptr by one step and simultaneously fast ptr by two steps until fast ptr is NULL or next of fast ptr is NULL.
When the above condition is met, we can see that the slow ptr is pointing towards the middle of Linked List and hence we can return the slow pointer.
*/