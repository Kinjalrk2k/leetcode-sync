class Solution {
public:
    pair<int,int> expand(string s, int i, int j) {
        while(i >= 0 && j < s.size()) {
            if(s[i] != s[j]) break;
            i--;
            j++;
        }

        return make_pair(i+1, j-1);
    }

    string longestPalindrome(string s) {
        int max_len = 0;
        pair<int,int> odd, even;
        int odd_len, even_len;
        int res_start, res_len;

        for(int i=0; i<s.size(); i++) {
            odd = expand(s, i, i);
            odd_len = odd.second-odd.first+1;
            if(odd_len > max_len) {
                res_start = odd.first;
                res_len = odd_len;
                max_len = odd_len;
            }
            
            even = expand(s, i, i+1);
            even_len = even.second-even.first+1;
            if(even_len > max_len) {
                res_start = even.first;
                res_len = even_len;
                max_len = even_len;
            }
        }

        return s.substr(res_start, res_len);
    }
};