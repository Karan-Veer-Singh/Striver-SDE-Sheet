/*
Problem link: https://practice.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1
Solution link: https://takeuforward.org/data-structure/n-meetings-in-one-room/
Solution video: https://www.youtube.com/watch?v=II6ziNnub1Q&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=46
*/

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
	//Function to find the maximum number of meetings that can
	//be performed in a meeting room.
	struct meeting {
		int start;
		int end;
	};

	bool static compare(struct meeting a, meeting b) {
		return a.end < b.end;
	}

	int maxMeetings(int start[], int end[], int n)
	{
		// Your code here
		struct meeting meet[n];
		for (int i = 0; i < n; i++) {
			meet[i].start = start[i];
			meet[i].end = end[i];
		}

		sort(meet, meet + n, compare);

		int count = 1, limit = meet[0].end;
		for (int i = 1; i < n; i++) {
			if (meet[i].start > limit) {
				limit = meet[i].end;
				count++;
			}
		}

		return count;
	}
};

// { Driver Code Starts.
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int start[n], end[n];
		for (int i = 0; i < n; i++) cin >> start[i];

		for (int i = 0; i < n; i++) cin >> end[i];

		Solution ob;
		int ans = ob.maxMeetings(start, end, n);
		cout << ans << endl;
	}
	return 0;
}  // } Driver Code Ends

/*
Time Complexity: O(n) to iterate through every position and insert them in a data structure. O(n log n)  to sort the data structure in ascending order of end time. O(n)  to iterate through the positions and check which meeting can be performed.

Overall : O(n) +O(n log n) + O(n) ~O(n log n)

Space Complexity: O(n)  since we used an additional data structure for storing the start time, end time.
*/

/*
Initial Thought Process:-
Say if you have two meetings, one which gets over early and another which gets over late. Which one should we choose?  If our meeting lasts longer the room stays occupied and we lose our time. On the other hand, if we choose a meeting that finishes early we can accommodate more meetings. Hence we should choose meetings that end early and utilize the remaining time for more meetings.

Approach:

To proceed we need a vector of three quantities: the starting time, ending time, meeting number. Sort this data structure in ascending order of end time.

We need a variable to store the answer. Initially, the answer is 1 because the first meeting can always be performed. Make another variable, say limit that keeps track of the ending time of the meeting that was last performed. Initially set limit as the end time of the first meeting.

Start iterating from the second meeting. At every position we have two possibilities:-

If the start time of a meeting is  strictly greater than limit we can perform the meeting. Update the answer.Our new limit is the ending time of the current meeting  since it was last performed.Also update limit.
 If the start time is less than or equal to limit  ,skip and move ahead.
 */