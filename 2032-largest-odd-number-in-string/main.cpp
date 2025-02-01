class Solution {
public:
    string largestOddNumber(string num) {
        int n = num.size();
      
        int pos=-1;
        for(int i=n-1; i>=0; i--) {
            if((num[i]-'0')%2 != 0) { pos=i; break; }
        }

  
    cout<<pos;
        if(pos == -1) return "";
        // if(pos==n-1) return num;
        return num.substr(0, pos+1);
    }
};