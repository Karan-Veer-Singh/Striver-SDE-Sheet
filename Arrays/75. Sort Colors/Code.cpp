/*
Problem link: https://leetcode.com/problems/sort-colors/
Solution link: https://takeuforward.org/data-structure/sort-an-array-of-0s-1s-and-2s/
Solution video: https://www.youtube.com/watch?v=oaVa-9wmpns&list=PLgUwDviBIf0rPG3Ictpu74YWBQ1CaBkm2&index=2
*/

class Solution {
public:
	void sortColors(vector<int>& nums) {
		int n = nums.size();
		int low = 0, mid = 0, high = n - 1;

		while (mid <= high) {
			if (nums[mid] == 0)  swap(nums[low++], nums[mid++]);
			else if (nums[mid] == 1) mid++;
			else    swap(nums[mid], nums[high--]);
		}
	}
};

/*
Time Complexity: O(N)
Space Complexity: O(1)
*/

/*
3-Pointer approach

This problem is a variation of the popular Dutch National flag algorithm

Intuition: In this approach, we will be using 3 pointers named low, mid, and high. We will be using these 3 pointers to move around the values. The primary goal here is to move 0s to the left and 2s to the right of the array and at the same time all the 1s shall be in the middle region of the array and hence the array will be sorted.

Approach:

Initialize the 3 pointers such that low and mid will point to 0th index and high pointer will point to last index
int low = arr[0]

int mid = arr[0]

int high = arr[n – 1]

Now there will 3 different operations / steps based on the value of arr[mid] and will be repeated until mid <= high.

arr[mid] == 0:
swap(arr[low], arr[mid])
low++, mid++

arr[mid] == 1:
mid++

arr[mid] == 2:
swap(arr[mid], arr[high])
high–;
The array formed after these steps will be a sorted array.
*/