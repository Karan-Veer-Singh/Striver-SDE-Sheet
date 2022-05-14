Problem Statement: You are given an array of prices where prices[i] is the price of a given stock on an ith day.

You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock. Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

Examples:

Example 1:

Input: prices = [7,1,5,3,6,4]

Output: 5

Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.

Note: That buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.

Example 2:

Input: prices = [7,6,4,3,1]

Output: 0

Explanation: In this case, no transactions are done and the max profit = 0.
Solution:

Disclaimer: Don’t jump directly to the solution, try it out yourself first.

Solution 1: Brute Force

Intuition: We can simply use 2 loops and track every transaction and maintain a variable maxPro to contain the max value among all transactions.

Approach: 

Use a for loop of ‘i’ from 0 to n.
Use another for loop from ‘i+1’ to n.
If arr[j] > arr[i] , take the difference and compare  and store it in the maxPro variable.
Return maxPro.


Code:

#include<bits/stdc++.h>

using namespace std;
int maxProfit(int arr[]) {
  int maxPro = 0;
  for (int i = 0; i < 6; i++) {
    for (int j = i + 1; j < 6; j++) {
      if (arr[j] > arr[i]) {
        maxPro = max(arr[j] - arr[i], maxPro);
      }
    }
  }
  return maxPro;
}

int main() {
  int arr[] = {7,1,5,3,6,4};
  int maxPro = maxProfit(arr);
  cout << "Max profit is: " << maxPro << endl;
}
Output:

Max profit is: 5

Time complexity: O(n^2)

Space Complexity: O(1)

Soltuion 2:Optimal solution 

Intuition: We will linearly travel the array. We can maintain a minimum from the starting of the array and compare it with every element of the array, if it is greater than the minimum then take the difference and maintain it in max, otherwise update the minimum.

Approach:

Create a variable maxPro and mark it as 0.
Create a variable minPrice and mark it as max_value.
Run a for loop from 0 to n.
Update the minPrice at if it greater than current element of the array
Take the difference of the minPrice with the current element of the array and compare and maintain it in maxPro.
Return the maxPro.


Code:

#include<bits/stdc++.h>

using namespace std;
int maxProfit(int arr[]) {
  int maxPro = 0;
  int minPrice = INT_MAX;
  for (int i = 0; i < 6; i++) {
    minPrice = min(minPrice, arr[i]);
    maxPro = max(maxPro, arr[i] - minPrice);
  }
  return maxPro;
}
int main() {
  int arr[] = {7,1,5,3,6,4};
  int maxPro = maxProfit(arr);
  cout << "Max profit is: " << maxPro << endl;
}
Output: Max profit is: 5

Time complexity: O(n)

Space Complexity: O(1)