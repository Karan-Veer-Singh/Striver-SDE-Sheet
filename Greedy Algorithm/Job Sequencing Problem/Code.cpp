/*
Problem link: https://practice.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1#
Solution link: https://takeuforward.org/data-structure/job-sequencing-problem/
Solution video: https://www.youtube.com/watch?v=LjPx4wQaRIs&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=48
*/

// { Driver Code Starts
// Program to find the maximum profit job sequence from a given array
// of jobs with deadlines and profits
#include<bits/stdc++.h>
using namespace std;

// A structure to represent a job
struct Job
{
	int id;	 // Job Id
	int dead; // Deadline of job
	int profit; // Profit if job is over before or on deadline
};


// } Driver Code Ends
/*
struct Job
{
    int id;	 // Job Id
    int dead; // Deadline of job
    int profit; // Profit if job is over before or on deadline
};
*/

class Solution
{
public:
	bool static compare(Job a, Job b) {
		return a.profit > b.profit;
	}
	//Function to find the maximum profit and the number of jobs done.
	vector<int> JobScheduling(Job arr[], int n)
	{
		// your code here
		sort(arr, arr + n, compare);

		int maxDead = arr[0].dead;
		for (int i = 1; i < n; i++)
			maxDead = max(maxDead, arr[i].dead);

		vector<int> slot(maxDead + 1, -1);
		int count = 0, profit = 0;

		for (int i = 0; i < n; i++) {
			for (int j = arr[i].dead; j > 0; j--) {
				if (slot[j] == -1) {
					slot[j] = i;
					count ++;
					profit += arr[i].profit;
					break;
				}
			}
		}

		return {count, profit};
	}
};

// { Driver Code Starts.
// Driver program to test methods
int main()
{
	int t;
	//testcases
	cin >> t;

	while (t--) {
		int n;

		//size of array
		cin >> n;
		Job arr[n];

		//adding id, deadline, profit
		for (int i = 0; i < n; i++) {
			int x, y, z;
			cin >> x >> y >> z;
			arr[i].id = x;
			arr[i].dead = y;
			arr[i].profit = z;
		}
		Solution ob;
		//function call
		vector<int> ans = ob.JobScheduling(arr, n);
		cout << ans[0] << " " << ans[1] << endl;
	}
	return 0;
}

// } Driver Code Ends

/*
Time Complexity: O(N log N) + O(N*M).

O(N log N ) for sorting the jobs in decreasing order of profit. O(N*M) since we are iterating through all N jobs and for every job we are checking from the last deadline, say M deadlines in the worst case.

Space Complexity: O(M) for an array that keeps track on which day which job is performed if M is the maximum deadline available.
*/

/*
Approach:  The strategy to maximize profit should be to pick up jobs that offer higher profits. Hence we should sort the jobs in descending order of profit. Now say if a job has a deadline of 4 we can perform it anytime between day 1-4, but it is preferable to perform the job on its last day. This leaves enough empty slots on the previous days to perform other jobs.

Basic Outline of the approach:-

Sort the jobs in descending order of profit.
If the maximum deadline is x, make an array of size x .Each array index is set to -1 initially as no jobs have been performed yet.
For every job check if it can be performed on its last day.
If possible mark that index with the job id and add the profit to our answer.
If not possible, loop through the previous indexes until an empty slot is found.
*/