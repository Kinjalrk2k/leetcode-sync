class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char,int> map_s;
        for(auto e: s) {
            if(map_s.find(e) == map_s.end()) map_s[e] = 1;
            else map_s[e]++;
        }

        map<char,int> map_t;
        for(auto e: t) {
            if(map_t.find(e) == map_t.end()) map_t[e] = 1;
            else map_t[e]++;
        }

        for(auto i=map_s.begin(); i != map_s.end(); i++) {
            cout<<i->first<<" "<<i->second;
        }

        cout<<endl;
        for(auto i=map_t.begin(); i != map_t.end(); i++) {
            cout<<i->first<<" "<<i->second;
        }

        return map_s == map_t;
    }
};