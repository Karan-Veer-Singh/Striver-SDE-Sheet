/*
Problem link: https://practice.geeksforgeeks.org/problems/sort-a-stack/1
Solution link 1: https://www.geeksforgeeks.org/sort-a-stack-using-recursion/
Solution link 2: https://www.geeksforgeeks.org/sort-stack-using-temporary-stack/
Solution video 1: https://www.youtube.com/watch?v=PIwrEAaOrkk
Solution video 2: https://www.youtube.com/watch?v=K0XXVSL4wUo
*/

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

class SortedStack {
public:
	stack<int> s;
	void sort();
};

void printStack(stack<int> s)
{
	while (!s.empty())
	{
		printf("%d ", s.top());
		s.pop();
	}
	printf("\n");
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		SortedStack *ss = new SortedStack();
		int n;
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			int k;
			cin >> k;
			ss->s.push(k);
		}
		ss->sort();
		printStack(ss->s);
	}
}// } Driver Code Ends


/*The structure of the class is
class SortedStack{
public:
	stack<int> s;
	void sort();
};
*/
void sortedInsert(stack<int> &s, int temp) {
	if (s.empty() || s.top() < temp) {
		s.push(temp);
		return;
	}

	int e = s.top();
	s.pop();
	sortedInsert(s, temp);
	s.push(e);
}

void recSort(stack<int> &s) {
	if (s.empty())    return;
	int temp = s.top();  s.pop();
	recSort(s);
	sortedInsert(s, temp);
}

/* The below method sorts the stack s
you are required to complete the below method */
void SortedStack :: sort()
{
	//Your code here
	recSort(s);
}

/*
Time Complexity: O(N^2).
In the worst case for every sortstack(), sortedinsert() is called for ‘N’ times recursively for putting element to the right place
Auxiliary Space: O(N)
Use of stack data structure for storing values
*/