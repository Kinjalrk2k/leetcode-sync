class Solution {
public:
    int beautySum(string s) {
        int sum = 0;
        int freq[26] = {0};
        int max_freq, min_freq;

        for(int i=0; i<s.size(); i++) {
            // clearing
            for(int i=0; i<26; i++) freq[i] = 0;
            for(int j=i; j<s.size(); j++) {
                freq[s[j] - 'a']++;

                cout<<"boo";
                max_freq = INT_MIN;
                min_freq = INT_MAX;
                for(auto e: freq) {
                    if(e > 0) {
                        max_freq = max(max_freq, e);
                        min_freq = min(min_freq, e);
                    }
                }
                // cout<<s.substr(i, j-i+1)<<" "<<max_freq<<" "<<min_freq<<endl;
                sum += (max_freq - min_freq);
            }
        }

        return sum;
    }
};