/*
Problem link: https://leetcode.com/problems/pascals-triangle/
Solution link: https://takeuforward.org/data-structure/program-to-generate-pascals-triangle/
Solution video: https://www.youtube.com/watch?v=6FLvhQjZqvM&list=PLgUwDviBIf0rPG3Ictpu74YWBQ1CaBkm2&index=8
*/

class Solution {
public:
	vector<vector<int>> generate(int numRows) {
		vector<vector<int>> ans(numRows);

		for (int i = 0; i < numRows; i++) {
			ans[i].resize(i + 1);
			ans[i][0] = ans[i][i] = 1;
			for (int j = 1; j < i; j++) {
				ans[i][j] = ans[i - 1][j - 1] + ans[i - 1][j];
			}
		}
		return ans;
	}
};

/*
Time Complexity: We are creating a 2D array of size (numRows * numCols) (where 1 <= numCols <= numRows), and we are traversing through each of the cells to update it with its correct value, so Time Complexity = O(numRows*numRows).

Space Complexity: Since we are creating a 2D array, space complexity = O(numRows*numRows).
*/

/*
Intuition: When you see the image above, you get a pretty good idea of what you are supposed to do here. Think about the image as a matrix now where each line is basically a row in the matrix. So, first things first, if you are at the edge of the matrix, the value is 1, that’s for sure. Now, what about the inner elements? Well, any inner element is obtained by doing the sum of the 2 values present in the row just above it, i.e., if the element is at index (i, j), then matrix[i][j] can be obtained by doing matrix[i – 1][j – 1] + matrix[i – 1][j].

Approach: To solve the problem, we need to first create an array of size N or numRows (input value). This array is used to store each of the rows expected in the output, so, for example, array[1] = [1,1]. In this array, the number of columns (say, numCols) is equal to the number of the i-th row + 1 (Since, 0-indexed), i.e., for 0-th row, numCols = 1. So, the number of columns is different for each row.

Next, we need to run a loop from i = 0 to numRows – 1 (inclusive) in order to store each row in our array. For each of iteration of this loop, we follow the below steps:

Create an array of size (i + 1) (For some languages such as C++, you need to create a 2D array at the start of the program and resize array[i] to (i + 1)).
Set the first and last value of array[i] to 1.
Run another loop from j = 1 to i – 1 (inclusive) and for each iteration put array[i][j] = array[i – 1][j – 1] + array[i – 1][j].
After iterating numRows times, you return the array.
*/