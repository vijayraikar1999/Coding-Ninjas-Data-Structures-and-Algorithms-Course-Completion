#include<stack>

bool checkRedundantBrackets(string expr) {
	stack<char> s;

    for(int i = 0; i < expr.size(); i++) {
        if (expr[i] == '(' || expr[i] == '+' || expr[i] == '-' || 
            expr[i] == '*' || expr[i] == '/') {
            // Push the character onto the stack
            s.push(expr[i]);
        } else if (expr[i] == ')') {
            // Check for immediate '(' before ')', indicating redundancy
            if (s.top() == '(') {
                return true; // Redundant parentheses found
            } else {
                // Pop operators until an opening bracket is encountered
                while (!s.empty() && s.top() != '(') {
                    s.pop();
                }
                // Pop the opening bracket '('
                if (!s.empty()) {
                    s.pop();
                }
            }
        }
    }

    // No redundant parentheses found
    return false;
}