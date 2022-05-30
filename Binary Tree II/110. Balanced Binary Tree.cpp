/*
Problem link: https://leetcode.com/problems/balanced-binary-tree/
Solution link: https://takeuforward.org/data-structure/check-if-the-binary-tree-is-balanced-binary-tree/
Solution video: https://www.youtube.com/watch?v=Yt50Jfbd8Po
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
private:
	int dfsHeight(TreeNode *root) {
		if (root == NULL)    return 0;

		int leftHeight = dfsHeight(root->left);
		if (leftHeight == -1)    return -1;

		int rightHeight = dfsHeight(root->right);
		if (rightHeight == -1)   return -1;

		if (abs(leftHeight - rightHeight) > 1)     return -1;

		return 1 + max(leftHeight, rightHeight);
	}

public:
	bool isBalanced(TreeNode* root) {
		return dfsHeight (root) != -1;
	}
};

/*
Time Complexity: O(N)

Space Complexity: O(1) Extra Space + O(H) Recursion Stack space
(Where “H”  is the height of binary tree)
*/