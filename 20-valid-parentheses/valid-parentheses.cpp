class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for (auto e : s) {
            if (e == '(' || e == '{' || e == '[')
                st.push(e);

            if (e == ')') {
                if(!st.empty() && st.top() == '(') st.pop();
                else return false;
            } else if (e == '}') {
                if(!st.empty() && st.top() == '{') st.pop();
                else return false;
            } else if (e == ']') {
                if(!st.empty() && st.top() == '[') st.pop();
                else return false;
            }
        }

        return st.empty();
    }
};