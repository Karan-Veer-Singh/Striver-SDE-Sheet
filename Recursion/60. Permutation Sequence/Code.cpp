/*
Problem link: https://leetcode.com/problems/permutation-sequence/
Solution link: https://takeuforward.org/data-structure/find-k-th-permutation-sequence/
Solution video: https://www.youtube.com/watch?v=wT7gcXLYoao&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=56
*/

class Solution {
public:
	string getPermutation(int n, int k) {
		int fact = 1;
		vector<int> nums;
		for (int i = 1; i < n; i++) { fact *= i;  nums.push_back(i); }
		nums.push_back(n);
		string ans = "";
		k = k - 1;

		while (true) {
			ans += to_string(nums[k / fact]);
			nums.erase(nums.begin() + k / fact);
			if (nums.size() == 0)    break;
			k %= fact;
			fact /= nums.size();
		}
		return ans;
	}
};

/*
Time Complexity: O(N) * O(N) = O(N^2)
Reason: We are placing N numbers in N positions. This will take O(N) time. For every number,
we are reducing the search space by removing the element already placed in the previous step.
This takes another O(N) time.

Space Complexity: O(N)
Reason: We are storing the numbers in a data structure(here vector)
*/