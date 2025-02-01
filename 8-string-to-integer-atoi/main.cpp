class Solution {
public:
    int myAtoi(string s) {
        int sign = 1;
        long num = 0;
        bool began = false;
        for(auto e: s) {
            if(!began && e == ' ') continue;
            else if(!began && e == '-') {
                began = true;
                sign = -1;
            }
            else if(!began && e == '+') {
                began = true;
                sign = 1;
            }
            else if(isdigit(e)) {
                began = true;
                int digit = e - '0';
                num = ((num * 10) + digit);
                if(sign * num > INT_MAX)
                    return INT_MAX;
                else if(sign * num < INT_MIN)
                    return INT_MIN;
            } else {
                break;
            }
        }

        return sign * num;
    }
};