/*
Problem link: https://leetcode.com/problems/combination-sum-ii/
Solution link: https://takeuforward.org/data-structure/combination-sum-ii-find-all-unique-combinations/
Solution video: https://www.youtube.com/watch?v=G1fRTGRxXU8&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=51
*/

class Solution {
private:
	void findCombinations(int index, int target, vector<int> &ds, vector<vector<int>> &ans, vector<int> &candidates) {
		if (target == 0) {
			ans.push_back(ds);
			return;
		}

		for (int i = index; i < candidates.size(); i++) {
			if (i != index && candidates[i] == candidates[i - 1])  continue;
			if (candidates[i] > target)  break;
			ds.push_back(candidates[i]);
			findCombinations(i + 1, target - candidates[i], ds, ans, candidates);
			ds.pop_back();
		}
	}

public:
	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		vector<vector<int>> ans;
		vector<int> ds;
		sort(candidates.begin(), candidates.end());
		findCombinations(0, target, ds, ans, candidates);
		return ans;
	}
};

/*
Time Complexity:O(2^n*k)

Reason: Assume if all the elements in the array are unique then the no. of subsequence you will get will be O(2^n). we also add the ds to our ans when we reach the base case that will take “k”//average space for the ds.

Space Complexity:O(k*x)

Reason: if we have x combinations then space will be x*k where k is the average length of the combination.
*/

/*
Before starting the recursive call make sure to sort the elements because the ans should contain the combinations in sorted order and should not be repeated.

Initially, We start with the index 0, At index 0 we have n – 1 way to pick the first element of our subsequence.

Check if the current index value can be added to our ds. If yes add it to the ds and move the index by 1. while moving the index skip the consecutive repeated elements because they will form duplicate sequences.

Reduce the target by arr[i],call the recursive call for f(idx + 1,target – 1,ds,ans) after the call make sure to pop the element from the ds.(By seeing the example recursive You will understand).

if(arr[i] > target) then terminate the recursive call because there is no use to check as the array is sorted in the next recursive call the index will be moving by 1 all the elements to its right will be in increasing order.

Base Condition:

Whenever the target value is zero add the ds to the ans return.
*/