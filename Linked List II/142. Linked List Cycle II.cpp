/*
Problem link: https://leetcode.com/problems/linked-list-cycle-ii/
Solution link: https://takeuforward.org/data-structure/starting-point-of-loop-in-a-linked-list/
Solution video: https://www.youtube.com/watch?v=QfbOhn0WZ88&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=38
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
    ListNode *detectCycle(ListNode *head) {
        if (head == NULL || head->next == NULL)  return NULL;
        ListNode *slow = head;
        ListNode * fast = head;

        while (fast->next != NULL && fast->next->next != NULL) {
            fast = fast->next->next;
            slow = slow->next;

            if (slow == fast) {
                slow = head;
                while (slow != fast) {
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow;
            }
        }
        return NULL;
    }
};


/*
Time Complexity: O(N)
Reason: We can take overall iterations club it to O(N)

Space Complexity: O(1)
Reason: No extra data structure is used.
*/