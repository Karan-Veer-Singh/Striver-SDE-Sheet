/*
Problem link: https://leetcode.com/problems/next-greater-element-ii/
Solution link: https://takeuforward.org/data-structure/next-greater-element-using-stack/
Solution video: https://www.youtube.com/watch?v=Du881K7Jtk8&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=76
*/

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        stack<int> s;
        vector<int> nge(n, -1);

        for (int i = 2 * n - 1; i >= 0; i--) {
            while (!s.empty() && s.top() <= nums[i % n])   s.pop();
            if (i < n)   nge[i] = s.empty() ? -1 : s.top();
            s.push(nums[i % n]);
        }
        return nge;
    }
};

/*
Time Complexity: O(N)

Space Complexity: O(N)
*/