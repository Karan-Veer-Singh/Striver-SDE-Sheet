/*
Problem link: https://practice.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1
Solution link: https://takeuforward.org/data-structure/fractional-knapsack-problem-greedy-approach/
Solution video: https://www.youtube.com/watch?v=F_DDzYnxO14&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=50
*/

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item {
	int value;
	int weight;
};


// } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/


class Solution
{
public:
	bool static compare(Item a, Item b) {
		double v1 = a.value / double(a.weight);
		double v2 = b.value / double(b.weight);
		return v1 > v2;
	}
	//Function to get the maximum total value in the knapsack.
	double fractionalKnapsack(int W, Item arr[], int n)
	{
		// Your code here
		sort(arr, arr + n, compare);
		int curWeight = 0;
		double finalvalue = 0.0;

		for (int i = 0; i < n; i++) {
			if (curWeight + arr[i].weight <= W) {
				curWeight += arr[i].weight;
				finalvalue += arr[i].value;
			}
			else {
				int remain = W - curWeight;
				finalvalue += (arr[i].value / (double) arr[i].weight) * (double) remain;
				break;
			}
		}
		return finalvalue;
	}
};


// { Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin >> t;
	cout << setprecision(2) << fixed;
	while (t--) {
		//size of array and weight
		int n, W;
		cin >> n >> W;

		Item arr[n];
		//value and weight of each item
		for (int i = 0; i < n; i++) {
			cin >> arr[i].value >> arr[i].weight;
		}

		//function call
		Solution ob;
		cout << ob.fractionalKnapsack(W, arr, n) << endl;
	}
	return 0;
}  // } Driver Code Ends

/*
Time Complexity: O(n log n + n).
O(n log n) to sort the items and O(n) to iterate through all the items for calculating the answer.

Space Complexity: O(1), no additional data structure has been used.
*/

/*
The greedy method to maximize our answer will be to pick up the items with higher values. Since it is possible to break the items as well we should focus on picking up items having higher value /weight first. To achieve this, items should be sorted in decreasing order with respect to their
value /weight. Once the items are sorted we can iterate. Pick up items with weight lesser than or equal to the current capacity of the knapsack. In the end, if the weight of an item becomes more than what we can carry, break the item into smaller units. Calculate its value according to our current capacity and add this new value to our answer.
*/