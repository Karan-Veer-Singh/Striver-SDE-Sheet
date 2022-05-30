/*
Problem link: https://leetcode.com/problems/diameter-of-binary-tree/
Solution link: https://takeuforward.org/data-structure/calculate-the-diameter-of-a-binary-tree/
Solution video: https://www.youtube.com/watch?v=Rezetez59Nk
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
	int height(TreeNode *root, int &diameter) {
		if (root == NULL)    return 0;
		int lh = height(root->left, diameter);
		int rh = height(root->right, diameter);
		diameter = max(diameter, lh + rh);
		return 1 + max(lh, rh);
	}
public:
	int diameterOfBinaryTree(TreeNode* root) {
		int diameter = 0;
		height(root, diameter);
		return diameter;
	}
};

/*
Time Complexity: O(N)

Space Complexity: O(1) Extra Space + O(H) Recursion Stack space
(Where “H”  is the height of binary tree )
/*