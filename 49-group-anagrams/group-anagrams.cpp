class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> m;
        vector<vector<string>> res;

        for(auto s: strs) {
            string ss = s;
            sort(ss.begin(), ss.end());
            // cout<<s<<" "<<ss<<endl;

            if(m.find(ss) == m.end()) m[ss] = vector<string>(1, s);
            else m[ss].push_back(s);
        }

        for(auto e: m) {
            res.push_back(e.second);
        }

        return res;
    }
};