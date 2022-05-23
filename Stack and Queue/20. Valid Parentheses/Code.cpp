/*
Problem link: https://leetcode.com/problems/valid-parentheses/
Solution link: https://takeuforward.org/data-structure/check-for-balanced-parentheses/
Solution video: https://www.youtube.com/watch?v=wkDfsKijrZ8&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=75
*/

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for (char c : s) {
            if (c == '(' || c == '{' || c == '[')    st.push(c);
            else {
                if (st.empty())  return false;
                char ch = st.top(); st.pop();
                if ( (c == ')' && ch != '(' ) || (c == '}' && ch != '{' ) || (c == ']' && ch != '[') )
                    return false;
            }
        }
        return st.empty();
    }
};

/*
Time Complexity: O(N)

Space Complexity: O(N)
*/

/*
Intuition:  We have to keep track of previous as well as most recent opening brackets and also keep in mind the sequence, as after opening of the bracket there should be opposite pairs of brackets. Also handle the corner cases like [ ) ( ] where closing bracket occurs first and opening bracket after it, which is an invalid sequence, as well as [ ( ] ) where the most recent opening didn’t get its opposite pair hence it will also not be valid.

So we have to use a data structure that will keep track of first in and last out, hence we will use the stack.

Approach:

Whenever we get the opening bracket we will push it into the stack. I.e ‘{‘, ’[’, ’(‘.
Whenever we get the closing bracket we will check if the stack is non-empty or not.
If the stack is empty we will return false, else if it is nonempty then we will check if the topmost element of the stack is the opposite pair of the closing bracket or not.
If it is not the opposite pair of the closing bracket then return false, else move ahead.
After we move out of the string the stack has to be empty if it is non-empty then return it as invalid else it is a valid string.
*/
