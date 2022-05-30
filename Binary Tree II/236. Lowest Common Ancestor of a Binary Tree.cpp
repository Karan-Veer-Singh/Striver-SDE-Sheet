/*
Problem link: https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/
Solution link: https://takeuforward.org/data-structure/lowest-common-ancestor-for-two-given-nodes/
Solution video: https://www.youtube.com/watch?v=_-QHfMDde90
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		if (root == NULL || root == p || root == q)  return root;
		TreeNode *left = lowestCommonAncestor(root->left, p, q);
		TreeNode *right = lowestCommonAncestor(root->right, p, q);
		if (left == NULL)    return right;
		else if (right == NULL)  return left;
		return root;
	}
};

/*
Time complexity: O(N) where n is the number of nodes.
Space complexity: O(N), auxiliary space.
*/