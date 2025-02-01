class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> map_s_t;
        unordered_map<char, char> map_t_s;

        for(int i=0; i<s.size(); i++) {
            if(
                (map_s_t.find(s[i]) != map_s_t.end() && map_s_t[s[i]] != t[i]) ||
                (map_t_s.find(t[i]) != map_t_s.end() && map_t_s[t[i]] != s[i])
            ) {
                return false;
            } else {
                map_s_t.insert({s[i], t[i]});
                map_t_s.insert({t[i], s[i]});
            }
        }

        return true;
    }
};