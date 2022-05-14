/*
Problem link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
Solution link: https://takeuforward.org/data-structure/stock-buy-and-sell/
Solution video: https://www.youtube.com/watch?v=eMSfBgbiEjk&list=PLgUwDviBIf0rPG3Ictpu74YWBQ1CaBkm2&index=12
*/

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int profit = 0;
		int mini = INT_MAX;
		for (int price : prices) {
			mini = min(mini, price);
			profit = max(profit, price - mini);
		}
		return profit;
	}
};

/*
Time complexity: O(n)
Space Complexity: O(1)
*/

/*
Intuition: We will linearly travel the array. We can maintain a minimum from the starting of the array and compare it with every element of the array, if it is greater than the minimum then take the difference and maintain it in max, otherwise update the minimum.

Approach:

Create a variable maxPro and mark it as 0.
Create a variable minPrice and mark it as max_value.
Run a for loop from 0 to n.
Update the minPrice at if it greater than current element of the array
Take the difference of the minPrice with the current element of the array and compare and maintain it in maxPro.
Return the maxPro.
*/