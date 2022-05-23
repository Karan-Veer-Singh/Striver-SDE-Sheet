/*
Problem link: https://leetcode.com/problems/implement-stack-using-queues/
Solution link: https://takeuforward.org/data-structure/implement-stack-using-single-queue/
Solution video: https://www.youtube.com/watch?v=jDZQKzEtbYQ&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=75
*/

class MyStack {
public:
    /** Initialize your data structure here. */
    queue<int> q;

    MyStack() {

    }

    /** Push element x onto stack. */
    void push(int x) {
        q.push(x);

        for (int i = 0; i < q.size() - 1; i++)
        {
            q.push(q.front());
            q.pop();
        }
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int x = q.front();
        q.pop();

        return x;
    }

    /** Get the top element. */
    int top() {
        return q.front();
    }

    /** Returns whether the stack is empty. */
    bool empty() {
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
