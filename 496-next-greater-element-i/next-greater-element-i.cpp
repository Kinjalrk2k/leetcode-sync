class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        unordered_map<int, int> m;
        vector<int> res;
        for (auto it = nums2.rbegin(); it != nums2.rend(); ++it) {
            while (!st.empty() && st.top() <= *it)
                st.pop();

            int to_ins;
            if (st.empty()) {
                to_ins = -1;
                st.push(*it);
            } else if (st.top() > *it) {
                to_ins = st.top();
                st.push(*it);
            } else {
                to_ins = -1;
            }

            m.insert({*it, to_ins});
            // cout << *it << "->" << to_ins << endl;
        }

        for(auto e: nums1) {
            res.push_back(m[e]);
        }

        return res;
    }
};