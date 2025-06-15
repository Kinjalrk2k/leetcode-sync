class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> phash(26, 0);
        vector<int> shash(26, 0);
        vector<int> res;

        if(p.size() > s.size()) return res;

        for(int i=0; i<p.size(); i++) phash[p[i]-'a']++;
        for(int i=0; i<p.size(); i++) shash[s[i]-'a']++; // just for initial window

        for(int i=0; i<=s.size()-p.size(); i++) {
            if(equal(phash.begin(), phash.end(), shash.begin())) res.push_back(i);

            if(i+p.size() < s.size()) {
                shash[s[i]-'a']--;
                shash[s[i+p.size()] - 'a']++;
            }
        }

        return res;
    }
};