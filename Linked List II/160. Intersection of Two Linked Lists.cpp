/*
Problem link: https://leetcode.com/problems/intersection-of-two-linked-lists/
Solution link: https://takeuforward.org/data-structure/find-intersection-of-two-linked-lists/
Solution video: https://www.youtube.com/watch?v=u4FWXfgS8jw&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=34
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == NULL || headB == NULL)  return NULL;

        ListNode *a = headA;
        ListNode *b = headB;

        while (a != b) {
            a = a == NULL ? headB : a->next;
            b = b == NULL ? headA : b->next;
        }

        return a;
    }
};

/*
Time Complexity: O(N)
Space Complexity: O(1)
*/