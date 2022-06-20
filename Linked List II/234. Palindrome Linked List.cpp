/*
Problem link: https://leetcode.com/problems/palindrome-linked-list/
Solution link: https://takeuforward.org/data-structure/check-if-given-linked-list-is-plaindrome/
Solution video: https://www.youtube.com/watch?v=-DtNInqFUXs&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=37
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
private:
    ListNode* reverseList(ListNode *curr) {
        ListNode *prev = NULL, *next = NULL;

        while (curr != NULL) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

public:
    bool isPalindrome(ListNode* head) {
        if (head == NULL || head->next == NULL)  return true;

        ListNode *slow = head;
        ListNode *fast = head;

        while (fast->next != NULL && fast->next->next != NULL) {
            fast = fast->next->next;
            slow = slow->next;
        }

        slow->next = reverseList(slow->next);
        slow = slow->next;

        while (slow != NULL) {
            if (head->val != slow->val)  return false;
            head = head->next;
            slow = slow->next;
        }

        return true;
    }
};


/*
Time Complexity: O(N/2)+O(N/2)+O(N/2)
Reason: O(N/2) for finding the middle element, reversing the list from the middle element,
and traversing again to find palindrome respectively.

Space Complexity: O(1)
Reason: No extra data structures are used.
*/