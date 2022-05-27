/*
Problem link: https://practice.geeksforgeeks.org/problems/subset-sums2234/1
Solution link: https://takeuforward.org/data-structure/subset-sum-sum-of-all-subsets/
Solution video: https://www.youtube.com/watch?v=rYkfBRtMJr8&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=53
*/

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
private:
	void solve(int i, int sum, vector<int> &arr, int n, vector<int> &ans) {
		if (i == n) {
			ans.push_back(sum);
			return;
		}

		//element is picked.
		solve(i + 1, sum + arr[i], arr, n, ans);
		//element is not picked.
		solve(i + 1, sum, arr, n, ans);
	}

public:
	vector<int> subsetSums(vector<int> arr, int N)
	{
		// Write Your Code here
		vector<int> ans;
		solve(0, 0, arr, N, ans);
		return ans;
	}
};

// { Driver Code Starts.
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int N;
		cin >> N;
		vector<int> arr(N);
		for (int i = 0 ; i < N ; i++) {
			cin >> arr[i];
		}
		Solution ob;
		vector<int> ans = ob.subsetSums(arr, N);
		sort(ans.begin(), ans.end());
		for (auto sum : ans) {
			cout << sum << " ";
		}
		cout << endl;
	}
	return 0;
}  // } Driver Code Ends

/*
Time Complexity: O(2^n)+O(2^n log(2^n)). Each index has two ways. You can either pick it up or not pick it. So for n index time complexity for O(2^n) and for sorting it will take (2^n log(2^n)).

Space Complexity: O(2^n) for storing subset sums, since 2^n subsets can be generated for an array of size n.
*/

/*
Intuition: The main idea is that on every index you have two options either to select the element to add it to your subset(pick) or not select the element at that index and move to the next index(non-pick).

Approach: Traverse through the array and for each index solve for two arrays, one where you pick the element,i.e add the element to the sum or don’t pick and move to the next element, recursively, until the base condition. Here when you reach the end of the array is the base condition.
*/