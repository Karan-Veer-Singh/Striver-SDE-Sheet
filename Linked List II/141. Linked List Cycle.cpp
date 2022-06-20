/*
Problem link: https://leetcode.com/problems/linked-list-cycle/
Solution link: https://takeuforward.org/data-structure/detect-a-cycle-in-a-linked-list/
Solution video: https://www.youtube.com/watch?v=354J83hX7RI&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=35
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
    bool hasCycle(ListNode *head) {
        if (head == NULL || head->next == NULL)  return false;

        ListNode *slow = head;
        ListNode *fast = head;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)    return true;
        }

        return false;
    }
};


/*
Time Complexity: O(N)
Space Complexity: O(1)
*/