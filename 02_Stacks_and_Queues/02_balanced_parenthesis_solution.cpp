

#include <stack>
#include <string>

bool isBalanced(string expression) 
{
    int n = expression.size();

    stack<char> st;
    st.push(expression[0]);
    for (int i = 1; i < n; i++) {
      if (expression[i] == '[' || expression[i] == '(' || expression[i] == '{') {
          st.push(expression[i]);
      } else {
          if ((expression[i] == ']' && st.top() == '[') ||
              (expression[i] == ')' && st.top() == '(') ||
              (expression[i] == '}' && st.top() == '{')) {
            st.pop();
          } else {
            return false;
          }
      }
    }
    if (st.empty()) {
        return true;
    }
    return false;
}