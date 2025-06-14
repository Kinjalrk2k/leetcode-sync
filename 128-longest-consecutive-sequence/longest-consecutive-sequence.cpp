class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> s;
        int max_c = 0;
        for(auto e: nums) s.insert(e);

        for(auto e: s) {
            int curr_c = 1, curr = e;
            if(s.find(curr-1) == s.end()) { // staring seq
                while(s.find(curr+1) != s.end()) {
                    curr++;
                    curr_c++;
                }

                max_c = max(max_c, curr_c);
            }
        }

        return max_c;
    }
};