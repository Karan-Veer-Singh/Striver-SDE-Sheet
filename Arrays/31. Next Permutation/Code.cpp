/*
Problem link: https://leetcode.com/problems/next-permutation/
Solution link: https://takeuforward.org/data-structure/next_permutation-find-next-lexicographically-greater-permutation/
Solution video: https://www.youtube.com/watch?v=LuLCLgMElus&list=PLgUwDviBIf0rPG3Ictpu74YWBQ1CaBkm2&index=9
*/

class Solution {
public:
	void nextPermutation(vector<int>& nums) {
		int n = nums.size(), k, l;
		for (k = n - 2; k >= 0; k--)
			if (nums[k] < nums[k + 1])   break;

		if (k < 0) {
			reverse(nums.begin(), nums.end());
		}
		else {
			for (l = n - 1; l > k; l--)
				if (nums[l] > nums[k]) break;

			swap(nums[k], nums[l]);
			reverse(nums.begin() + k + 1, nums.end());
		}
	}
};

/*
Time Complexity: For the first iteration backward, the second interaction backward and reversal at the end takes O(N) for each, where N is the number of elements in the input array. This sums up to 3*O(N) which is approximately O(N).

Space Complexity: Since no extra storage is required. Thus, its complexity is O(1).
*/

/*
Intuition :

Intuition lies behind the lexicographical ordering of all possible permutations of a given array. There will always be an increasing sequence of all possible permutations when observed.

Let’s check all sequences of permutations of {1,2,3}.

{1,2,3}

{1,3,2}

{2,1,3}

{2,3,1}

{3,1,2}

{3,2,1}

Thus, we can see every sequence has increasing order. Hence, our approach aims to get a peak from where the increasing sequence starts. This is what we achieve from our first step of the approach.

Then, we need to get just a larger value than the point where the peak occurs. To make rank as few as possible but greater than input array, just perverse array from breakpoint achieved from the first step of the approach. We achieve these from all remaining steps of our approach.

Approach :

Step 1: Linearly traverse array from backward such that ith index value of the array is less than (i+1)th index value. Store that index in a variable.

Step 2: If the index value received from step 1 is less than 0. This means the given input array is the largest lexicographical permutation. Hence, we will reverse the input array to get the minimum or starting permutation. Linearly traverse array from backward. Find an index that has a value greater than the previously found index. Store index another variable.

Step 3: Swap values present in indices found in the above two steps.

Step 4: Reverse array from index+1 where the index is found at step 1 till the end of the array.
/*