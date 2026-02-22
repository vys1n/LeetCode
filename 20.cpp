#include <stack>
#include <string>
using namespace std;

bool isValid(string s) {
    stack<char> st;

    for (char ch : s) {
        if (ch == '(' || ch == '[' || ch == '{') {
            st.push(ch);
        }

        else if (ch == ')' || ch == ']' || ch == '}') {
            if (st.empty()) {
                return false;
            } else {
                char top = st.top();
                st.pop();
                if (ch == ')' && top != '(' || ch == ']' && top != '[' || ch == '}' && top != '{') {
                    return false;
                }
            }
        }
    }

    return st.empty();
}

/* bool new_sol(string s) {
    stack<char> st;
    for (char ch : s) {
        if (ch == '('){
            st.push(')');
        } else if (ch == '['){
            st.push(']');
        } else if (ch == '{'){
            st.push('}');
        } else {
            if (st.empty() || st.top() != ch) {
                return false;
            }
            else if (!st.empty() && st.top() == ch) {
                st.pop();
            }
        }
    }
    return st.size() == 0;
} */
