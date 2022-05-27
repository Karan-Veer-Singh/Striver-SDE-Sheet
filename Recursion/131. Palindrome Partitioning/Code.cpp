/*
Problem link: https://leetcode.com/problems/palindrome-partitioning/
Solution link: https://takeuforward.org/data-structure/palindrome-partitioning/
Solution video: https://www.youtube.com/watch?v=WBgsABoClE0&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=52
*/

class Solution {
private:
	bool isPalindrome(int start, int end, string s) {
		while (start <= end)
			if (s[start++] != s[end--])  return false;

		return true;
	}

	void solve(int index, string s, vector<string> &temp, vector<vector<string>> &ans) {
		if (index == s.size()) {
			ans.push_back(temp);
			return;
		}

		for (int i = index; i < s.size(); i++) {
			if (isPalindrome(index, i, s)) {
				temp.push_back(s.substr(index, i - index + 1));
				solve(i + 1, s, temp, ans);
				temp.pop_back();
			}
		}
	}

public:
	vector<vector<string>> partition(string s) {
		vector<vector<string>> ans;
		vector<string> temp;
		solve(0, s, temp, ans);
		return ans;
	}
};

/*
Time Complexity: O( (2^n) *k*(n/2) )

Reason: O(2^n) to generate every substring and O(n/2)  to check if the substring generated is a palindrome. O(k) is for inserting the palindromes in another data structure, where k  is the average length of the palindrome list.

Space Complexity: O(k * x)

Reason: The space complexity can vary depending upon the length of the answer. k is the average length of the list of palindromes and if we have x such list of palindromes in our final answer. The depth of the recursion tree is n, so the auxiliary space required is equal to the O(n).
*/

/*
Approach: The initial idea will be to make partitions to generate substring and check if the substring generated out of the partition will be a palindrome. Partitioning means we would end up generating every substring and checking for palindrome at every step. Since this is a repetitive task being done again and again, at this point we should think of recursion. The recursion continues until the entire string is exhausted. After partitioning, every palindromic substring is inserted in a data structure When the base case has reached the list of palindromes generated during that recursion call is inserted in a vector of vectors/list of list.

We have already discussed the initial thought process and the basic outline of the solution. The approach will get clearer with an example.

Say s = “aabb” and assume indexes of string characters to be 0-based. For a better understanding, we have divided recursion into some steps.

STEP 1: We consider substrings starting from the 0th index.[0,0] is a palindrome, so partition right after the 0th index.[0,1] is another palindrome, make a partition after 1st index. Beyond this point, other substrings starting from index 0 are “aab”  and “aabb”. These are not palindromes, hence no more. partitions are possible. The strings remaining on the right side of the partition are used as input to make recursive calls.


STEP 2: Consider the recursive call on the left(refer to image)  where “abb” is the input.[1,1] is a palindrome, make a partition after it.[1,2] and [1,3] are not palindromes.


STEP 3: Here “bb” is the input.[2,2] as well as [2,3]  are palindromes. Make one partition after the 2nd index and one after the 3rd index The entire string is exhausted after the 3rd index, so the right recursion ends here. Palindromes generated from the right recursion are inserted in our answer.

Our answer at this point :[ [“a”,” a”,” bb”] ]


The left recursion will continue with  “b” as its input.[3,3] is a palindrome so one last partition for the left recursion is made after the 3rd index. Insert the palindromes.

ans = [  [“a”,”a”,”bb”], [ “a”,”a”,”b”,”b”] ]

STEP 4: After the list of palindromic substrings are returned from the left recursive call, continue the same process for the call on the right that was left to recur. The right recursion is having “bb” as input, something we have already encountered in step 3. Hence we will repeat the same task which was done in step 3 onwards.


Final answer : [  [“a”,”a”,”bb”], [ “a”,”a”,”b”,”b”] ,[“aa”,”b”,”b”], [“aa”,”bb”] ]
*/