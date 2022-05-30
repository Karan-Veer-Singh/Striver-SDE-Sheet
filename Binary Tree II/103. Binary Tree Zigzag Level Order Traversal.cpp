/*
Problem link: https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/
Solution link: https://takeuforward.org/data-structure/zig-zag-traversal-of-binary-tree/
Solution video: https://www.youtube.com/watch?v=3OXWEdlIGl4
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
	vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
		vector<vector<int>> ans;
		if (root == NULL)    return ans;
		bool leftToRight = true;
		queue<TreeNode*> q;
		q.push(root);

		while (!q.empty()) {
			int size = q.size();
			vector<int> level(size);

			for (int i = 0; i < size; i++) {
				TreeNode *f = q.front();    q.pop();
				if (f->left)     q.push(f->left);
				if (f->right)    q.push(f->right);

				int index = (leftToRight) ? i : (size - i - 1);
				level[index] = f->val;
			}
			leftToRight = !leftToRight;
			ans.push_back(level);
		}
		return ans;
	}
};

/*
Time Complexity: O(N)
Space Complexity: O(N)
*/