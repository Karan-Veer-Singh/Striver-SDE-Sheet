/*
Problem link: https://leetcode.com/problems/same-tree/
Solution link: https://takeuforward.org/data-structure/check-if-two-trees-are-identical/
Solution video: https://www.youtube.com/watch?v=BhuvF_-PWS0
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
	bool isSameTree(TreeNode* p, TreeNode* q) {
		if (p == NULL || q == NULL)  return p == q;
		return (p->val == q->val) && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
	}
};

/*
Time Complexity: O(N).
Reason: We are doing a tree traversal.

Space Complexity: O(N)
Reason: Space is needed for the recursion stack.
In the worst case (skewed tree), space complexity can be O(N).
*/