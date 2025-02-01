class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<char> stk;
        string res = "";

        for(auto e: s) {
            if(e == '(') {
                stk.push(e);
                if(stk.size() > 1) {
                    res += "(";
                }
            } else if(e == ')') {
                stk.pop();
                if(stk.size() > 0) {
                    res += ")";
                }
            }
        }

        return res;
    }

};