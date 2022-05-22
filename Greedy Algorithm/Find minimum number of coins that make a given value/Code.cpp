/*
Problem link: https://practice.geeksforgeeks.org/problems/-minimum-number-of-coins4426/1/
Solution link: https://takeuforward.org/data-structure/find-minimum-number-of-coins/
Solution video: https://www.youtube.com/watch?v=mVg9CfJvayM&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=49
*/

// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
public:
	vector<int> minPartition(int N)
	{
		// code here
		int arr[] = { 1, 2, 5, 10, 20, 50, 100, 200, 500, 2000 };
		int size = 10;
		vector<int> ans;

		for (int i = size - 1; i >= 0; i--) {
			while (arr[i] <= N) {
				ans.push_back(arr[i]);
				N -= arr[i];
			}
		}
		return ans;
	}
};

// { Driver Code Starts.

int main() {
	int t;
	cin >> t;
	while (t--) {
		int N;
		cin >> N;

		Solution ob;
		vector<int> numbers = ob.minPartition(N);
		for (auto u : numbers)
			cout << u << " ";
		cout << "\n";
	}
	return 0;
}  // } Driver Code Ends


/*
Time Complexity:O(N)

Space Complexity:O(1)
*/

/*
Approach: We will keep a pointer at the end of the array i. Now while(V >= coins[i]) we will reduce V by coins[i] and add it to the ans array.

We will also ignore the coins which are greater than V and the coins which are less than V. We consider them and reduce the value of V by coins[I].
*/