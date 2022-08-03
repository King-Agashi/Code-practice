class Solution {
public:
    int myAtoi(string s) {
        int n = s.length(), i = 0, sign = 1, res = 0;
        while(s[i] == ' '){
            i++;
        }
        
        if (s[i] == '-' || s[i] == '+'){
            sign = 1 - 2 * (s[i++] == '-');
        }
        
        while(s[i] >= '0' && s[i] <= '9'){
            if (res > INT_MAX / 10 || (res == INT_MAX / 10  && s[i] - '0' > 7)){
                if(sign == 1)
                    return INT_MAX;
                else
                    return INT_MIN;
            }
            res = res*10 + (s[i] - '0');
            i++;
        }
        return res*sign;
    }
};