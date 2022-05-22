/*
Problem link: https://practice.geeksforgeeks.org/problems/activity-selection-1587115620/1
Solution link: https://www.geeksforgeeks.org/activity-selection-problem-greedy-algo-1/
Solution video: https://www.youtube.com/watch?v=II6ziNnub1Q&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=46
*/


// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
public:
	struct activity {
		int start;
		int end;
	};

	bool static compare(activity a, activity b) {
		return a.end < b.end;
	}

	//Function to find the maximum number of activities that can
	//be performed by a single person.
	int activitySelection(vector<int> start, vector<int> end, int n)
	{
		// Your code here
		struct activity a[n];
		for (int i = 0; i < n; i++) {
			a[i].start = start[i];
			a[i].end = end[i];
		}

		sort(a, a + n, compare);

		int res = 1;
		int limit = a[0].end;
		for (int i = 1; i < n; i++) {
			if (a[i].start > limit) {
				limit = a[i].end;
				res++;
			}
		}
		return res;
	}
};

// { Driver Code Starts.
int main()
{
	int t;

	//testcases
	cin >> t;
	while (t--)
	{
		//size of array
		int n;
		cin >> n;
		vector<int> start(n), end(n);

		//adding elements to arrays start and end
		for (int i = 0; i < n; i++)
			cin >> start[i];
		for (int i = 0; i < n; i++)
			cin >> end[i];
		Solution ob;
		//function call
		cout << ob.activitySelection(start, end, n) << endl;
	}
	return 0;
}
// } Driver Code Ends

/*
Time Complexity: O(n) to iterate through every position and insert them in a data structure.
O(n log n)  to sort the data structure in ascending order of end time. O(n)  to iterate through the positions and check which activity can be performed.

Overall : O(n) +O(n log n) + O(n) ~O(n log n)

Space Complexity: O(n)  since we used an additional data structure for storing the start time, end time.
*/

/*
Approach:
The greedy choice is to always pick the next activity whose finish time is least among the remaining activities and the start time is more than or equal to the finish time of the previously selected activity. We can sort the activities according to their finishing time so that we always consider the next activity as minimum finishing time activity.
1) Sort the activities according to their finishing time
2) Select the first activity from the sorted array and print it.
3) Do the following for the remaining activities in the sorted array.
…….a) If the start time of this activity is greater than or equal to the finish time of the previously selected activity then select this activity and print it.
*/