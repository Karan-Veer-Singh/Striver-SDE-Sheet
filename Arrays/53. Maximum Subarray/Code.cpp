/*
Problem link: https://leetcode.com/problems/maximum-subarray/
Solution link: https://takeuforward.org/data-structure/kadanes-algorithm-maximum-subarray-sum-in-an-array/
Solution video: https://www.youtube.com/watch?v=w_KEocd__20&list=PLgUwDviBIf0rPG3Ictpu74YWBQ1CaBkm2&index=5
*/

class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		int sum = 0;
		int maxi = INT_MIN;
		for (int i = 0; i < nums.size(); i++) {
			sum += nums[i];
			maxi = max(maxi, sum);
			if (sum < 0) sum = 0;
		}
		return maxi;
	}
};

/*
Time Complexity: O(N)
Space Complexity:O(1)
*/

/*
Intuition: Basically this problem can be done in linear time complexity with Kadane’s algorithm along with that will also get the subarray which is giving the largest positive-sum.

Approach:

-> We will have the following variables in the beginning :

msf – max so far, meh – max end here, start – to get the starting index of ans’s subarray, end – to get the ending index of ans’s subarray.

-> Traverse the array starting with adding the ith element with max_end_here(meh) , now we will check that adding the element gives greater value than max_so_far(msf) , if yes then we will update our meh and also update the starting and ending index .

for(int i=0;i<nums.size();i++){

meh+=nums[i];

if(meh>msf){ msf=meh; start=s; end=i; }

if(meh<0){meh=0; s=i+1;}

}

->Now in this step, we will print the answer subarray using the start and end variables.

->Return the largest subarray sum that is:- msf.
*/