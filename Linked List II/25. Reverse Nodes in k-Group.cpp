/*
Problem link: https://leetcode.com/problems/reverse-nodes-in-k-group/
Solution link: https://takeuforward.org/data-structure/reverse-linked-list-in-groups-of-size-k/
Solution video: https://www.youtube.com/watch?v=Of0HPkk3JgI&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=35
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
    int lengthOfLinkedList(ListNode* head) {
        int length = 0;
        while (head != NULL) {++length; head = head->next;}
        return length;
    }

public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == NULL || head->next == NULL || k == 1) return head;

        int length = lengthOfLinkedList(head);

        ListNode *res = new ListNode();
        res->next = head;

        ListNode *prev = res, *curr = NULL, *n = NULL;

        while (length >= k) {
            curr = prev->next;
            n = curr->next;

            for (int i = 1; i < k; i++) {
                curr->next = n->next;
                n->next = prev->next;
                prev->next = n;
                n = curr->next;
            }

            length -= k;
            prev = curr;
        }

        return res->next;
    }
};

/*
Time Complexity: O(N)
Reason: Nested iteration with O((N/k)*k) which makes it equal to O(N).

Space Complexity: O(1)
Reason: No extra data structures are used for computation.
*/