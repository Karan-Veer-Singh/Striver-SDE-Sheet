/*
Problem link: https://practice.geeksforgeeks.org/problems/minimum-platforms-1587115620/1#
Solution link: https://takeuforward.org/data-structure/minimum-number-of-platforms-required-for-a-railway/
Solution video: https://www.youtube.com/watch?v=dxVcMDI7vyI&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=47
*/

// { Driver Code Starts
// Program to find minimum number of platforms
// required on a railway station
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
public:
	//Function to find the minimum number of platforms required at the
	//railway station such that no train waits.
	int findPlatform(int arr[], int dep[], int n)
	{
		// Your code here
		sort(arr, arr + n);
		sort(dep, dep + n);

		int platform = 1, count = 1, i = 1, j = 0;

		while (i < n && j < n) {
			if (arr[i] <= dep[j]) { count++; i++; }
			else { count--; j++; }
			platform = max(platform, count);
		}
		return platform;
	}
};


// { Driver Code Starts.
// Driver code
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		int arr[n];
		int dep[n];
		for (int i = 0; i < n; i++)
			cin >> arr[i];
		for (int j = 0; j < n; j++) {
			cin >> dep[j];
		}
		Solution ob;
		cout << ob.findPlatform(arr, dep, n) << endl;
	}
	return 0;
}  // } Driver Code Ends

/*
Time Complexity: O(nlogn) Sorting takes O(nlogn) and traversal of arrays takes O(n) so overall time complexity is O(nlogn).

Space complexity: O(1)  (No extra space used).
*/

/*
Intuition: At first we need to sort both the arrays. When the events will be sorted, it will be easy to track the count of trains that have arrived but not departed yet. Total platforms needed at one time can be found by taking the difference of arrivals and departures at that time and the maximum value of all times will be the final answer.

Approach:  At first we need to sort both the arrays. When the events will be sorted, it will be easy to track the count of trains that have arrived but not departed yet. Total platforms needed at one time can be found by taking the difference of arrivals and departures at that time and the maximum value of all times will be the final answer. If(arr[i]<=dep[j]) means if arrival time is less than or equal to the departure time then- we need one more platform. So increment count as well as increment i. If(arr[i]>dep[j]) means arrival time is more than the departure time then- we have one extra platform which we can reduce. So decrement count but increment j. Update the ans with max(ans, count) after each iteration of the while loop.
*/