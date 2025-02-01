class Solution {
public:
    int maxDepth(string s) {
        int count=0, max_count=0;
        stack <char> stk;

        for(auto e: s) {
            if(e == '(') stk.push('(');
            if(e == ')') {
                cout<<stk.top();
                max_count = max(max_count, int(stk.size()));
                stk.pop();
            }
        }

        return max_count;
    }
};