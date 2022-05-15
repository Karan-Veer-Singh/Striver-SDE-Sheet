/*
Problem link: https://leetcode.com/problems/add-two-numbers/
Solution link: https://takeuforward.org/data-structure/add-two-numbers-represented-as-linked-lists/
Solution video: https://www.youtube.com/watch?v=LBVsXSMOIk4&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=33
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
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode *dummy = new ListNode(0);
		ListNode *temp = dummy;
		int carry = 0;

		while (l1 != NULL || l2 != NULL || carry) {
			int sum = 0;
			if (l1 != NULL)  { sum += l1->val; l1 = l1->next; }
			if (l2 != NULL)  { sum += l2->val; l2 = l2->next; }
			sum += carry;
			carry = sum / 10;
			ListNode *newNode = new ListNode(sum % 10);
			temp->next = newNode;
			temp = temp->next;
		}
		return dummy->next;
	}
};

/*
Time Complexity: O(max(m,n)). Assume that m and n represent the length of l1 and l2 respectively, the algorithm above iterates at most max(m,n) times.

Space Complexity: O(max(m,n)). The length of the new list is at most max(m,n)+1.
*/

/*
Intuition: Keep track of the carry using a variable and simulate digits-by-digits sum starting from the head of the list, which contains the least significant digit.

Approach:



Visualization of the addition of two numbers:

342 + 465 = 807

342+465=807.

Each node contains a single digit and the digits are stored in reverse order.

Just like how you would sum two numbers on a piece of paper, we begin by summing the least significant digits, which is the head of l1 and l2. Since each digit is in the range of 0…9, summing two digits may “overflow”. For example

5 + 7 = 12. In this case, we set the current digit to 2 and bring over the carry=1 to the next iteration.

carry must be either 0 or 1 because the largest possible sum of two digits (including the carry) is 9 + 9 + 1 = 19.

Psuedocode:

Create a dummy node which is the head of new linked list.
Create a node temp, initialise it with dummy.
Initialize carry to 0.
Loop through lists l1 and l2 until you reach both ends, and until carry is present.
Set sum=l1.val+ l2.val + carry.
Update carry=sum/10.
Create a new node with the digit value of (sum%10) and set it to temp node’s next, then advance temp node to next.
Advance both l1 and l2.
Return dummy’s next node.
Note that we use a dummy head to simplify the code. Without a dummy head, you would have to write extra conditional statements to initialize the head’s value.

Take extra caution in the following cases:

Test case	Explanation
l1=[0,1], l2=[0,1,2]	When one list is longer than the other.
l1=[], l2=[0,1]	When one list is null, which means an empty list.
l1=[9,9], l2=[1]	The sum could have an extra carry of one at the end, which is easy to forget.
*/