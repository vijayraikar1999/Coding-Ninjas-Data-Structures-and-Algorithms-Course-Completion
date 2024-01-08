#include <iostream>
#include <stack>

void calculateSpan(int prices[], int n, int spans[]) {
    std::stack<int> s;  // Stack to keep track of indices

    for (int i = 0; i < n; i++) {
        // Pop elements from the stack while stack is not empty and 
        // top of stack is less than current price
        while (!s.empty() && prices[s.top()] < prices[i]) {
            s.pop();
        }

        // If stack is empty, then no element is greater on left of current element
        // So span will be index + 1
        spans[i] = (s.empty()) ? (i + 1) : (i - s.top());

        // Push the current index onto the stack
        s.push(i);
    }
}
