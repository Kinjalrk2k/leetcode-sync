class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        if(x < 10) return true;

        int n = floor(log10(x) + 1);
        
        for(int i=0; i<n/2; i++) {
            int last = int(x/pow(10, i)) % 10;
            int first = int(x/pow(10, n-i-1)) % 10;
            if(first != last) return false;
        }

        return true;
    }
};