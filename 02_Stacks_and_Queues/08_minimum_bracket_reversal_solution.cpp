#include <iostream>
#include <stack>
#include <string>

int countBracketReversals(std::string input) {
    stack<char> st;
    int n = input.size();
    
    // If the number of brackets is odd, they can't be balanced
    if (n % 2 != 0) {
        return -1;
    }
    
    for (int i = 0; i < n; i++) {
        if (input[i] == '{') {
            st.push(input[i]);
        } else {
            if (!st.empty() && st.top() == '{') {
                st.pop();
            } else {
                st.push(input[i]);
            }
        }
    }

    // int stackSize = st.size();
    // int openCount = 0;

    // // Count number of opening brackets in the stack
    // while (!st.empty() && st.top() == '{') {
    //     openCount++;
    //     st.pop();
    // }

    // // ceil(openCount / 2) + ceil(stackSize - openCount / 2)
    // return (openCount + 1) / 2 + (stackSize - openCount + 1) / 2;
    int ans_count = 0;
    char check_char = '}';

    while (!st.empty()) {
        if (st.top() == check_char) {
            st.pop();
        } else {
            st.pop();
            ans_count++;
        }
        check_char = check_char == '}' ? '{' : '}';
    }
    return ans_count;
}