/*
Problem link: https://practice.geeksforgeeks.org/problems/implement-stack-using-array/1
Solution link: https://takeuforward.org/data-structure/implement-stack-using-array/
Solution video: https://www.youtube.com/watch?v=GYptUgnIM_I&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=69
*/

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

class MyStack
{
private:
    int arr[1000];
    int top;
public:
    MyStack() {top = -1;}
    int pop();
    void push(int);
};


int main()
{

    int T;
    cin >> T;
    while (T--)
    {
        MyStack *sq = new MyStack();

        int Q;
        cin >> Q;
        while (Q--) {
            int QueryType = 0;
            cin >> QueryType;
            if (QueryType == 1)
            {
                int a;
                cin >> a;
                sq->push(a);
            } else if (QueryType == 2) {
                cout << sq->pop() << " ";

            }
        }
        cout << endl;
    }
}
// } Driver Code Ends



//Function to push an integer into the stack.
void MyStack :: push(int x)
{
    // Your Code
    arr[++top] = x;
}

//Function to remove an item from top of the stack.
int MyStack :: pop()
{
    // Your Code
    if (top == -1)
        return -1;

    int x = arr[top--];
    return x;
}