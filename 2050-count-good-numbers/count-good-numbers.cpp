class Solution {
public:
    const int mod = 1e9 + 7;
    
    long long pow(long long b, long long e) {
        if(e == 0) return 1;
        if(e == 1) return b;
        long long res = (pow(b, e/2) % mod);

        if(e % 2 == 0) return res * res;
        return ((res * res)%mod * b)%mod;
    }

    int countGoodNumbers(long long n) {
        if(n % 2 == 0) return (pow(20, n/2) % mod);
        return ((pow(20, n/2) % mod) * 5) % mod;
    }
};