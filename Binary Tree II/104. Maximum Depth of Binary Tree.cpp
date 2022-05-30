/*
Problem link: https://leetcode.com/problems/maximum-depth-of-binary-tree/
Solution link: https://takeuforward.org/data-structure/maximum-depth-of-a-binary-tree/
Solution video: https://www.youtube.com/watch?v=eD3tmO66aBA
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
	int maxDepth(TreeNode* root) {
		if (root == NULL)    return 0;

		int lh = maxDepth(root->left);
		int rh = maxDepth(root->right);

		return 1 + max(lh, rh);
	}
};

/*
Time Complexity: O(N)

Space Complexity: O(1) Extra Space + O(H) Recursion Stack space,
where “H”  is the height of the binary tree.
*/