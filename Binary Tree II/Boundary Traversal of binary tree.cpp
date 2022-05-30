/*
Problem link: https://practice.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1
Solution link: https://takeuforward.org/data-structure/boundary-traversal-of-a-binary-tree/
Solution video: https://www.youtube.com/watch?v=0ca1nvR0be4
*/

/* A binary tree Node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution {
private:
	bool isLeaf(Node *root) {
		return (root->left == NULL && root->right == NULL);
	}

	void addLeftBoundary(Node *root, vector<int> &ans) {
		Node *curr = root->left;
		while (curr != NULL) {
			if (!isLeaf(curr))   ans.push_back(curr->data);
			if (curr->left)  curr = curr->left;
			else    curr = curr->right;
		}
	}

	void addLeaves(Node *root, vector<int> &ans) {
		if (isLeaf(root)) { ans.push_back(root->data); return; }
		if (root->left)  addLeaves(root->left, ans);
		if (root->right) addLeaves(root->right, ans);
	}

	void addRightBoundary(Node *root, vector<int> &ans) {
		Node *curr = root->right;
		vector<int> temp;

		while (curr != NULL) {
			if (!isLeaf(curr))   temp.push_back(curr->data);
			if (curr->right) curr = curr->right;
			else    curr = curr->left;
		}

		for (int i = temp.size() - 1; i >= 0; i--)
			ans.push_back(temp[i]);
	}

public:
	vector <int> boundary(Node *root)
	{
		//Your code here
		vector<int> ans;
		if (root == NULL)    return ans;

		if (!isLeaf(root))   ans.push_back(root->data);

		addLeftBoundary(root, ans);
		addLeaves(root, ans);
		addRightBoundary(root, ans);

		return ans;
	}
};

/*
Time Complexity: O(N).
Reason: The time complexity will be O(H) + O(H) + O(N) which is ≈ O(N)

Space Complexity: O(N)
Reason: Space is needed for the recursion stack while adding leaves.
 In the worst case (skewed tree), space complexity can be O(N).
*/