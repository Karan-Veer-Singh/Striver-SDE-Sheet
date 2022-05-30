/*
Problem link: https://leetcode.com/problems/binary-tree-level-order-traversal/
Solution link: https://takeuforward.org/data-structure/level-order-traversal-of-a-binary-tree/
Solution video: https://www.youtube.com/watch?v=EoAsWbO7sqg
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
	vector<vector<int>> levelOrder(TreeNode* root) {
		vector<vector<int>> ans;
		if (root == NULL)    return ans;
		queue<TreeNode*> q;
		q.push(root);

		while (!q.empty()) {
			vector<int> level;
			int size = q.size();

			while (size--) {
				TreeNode *f = q.front();    q.pop();
				level.push_back(f->val);
				if (f->left != NULL)     q.push(f->left);
				if (f->right != NULL)    q.push(f->right);
			}
			ans.push_back(level);
		}
		return ans;
	}
};

/*
Time Complexity: O(N)
Space Complexity: O(N)
*/