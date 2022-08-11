#define M 786433

class Solution {
public:

    int ipow(int a, int b){
        int res = 1;
        for (int i = 0; i < b; ++i)
            res = a * res % M;
        return res;
    }

    int strStr(string s, string p){

        int     ls      = s.length()        ,
                lp      = p.length()        ,
                k       = ipow(26, lp - 1)  ,
                f       = 0                 ,
                rollh   = 0                 ,
                pop                         ,
                put                         ;

        if (ls < lp)
            return -1;

        for (int i = 0; i < lp; ++i){
            f = (f * 26 % M + p[i] - 'a') % M;
            rollh = (rollh * 26 % M + s[i] - 'a') % M;
        }

        if (f == rollh)
            return 0;


        for (int i = lp; i < ls; ++i){
            pop = s[i - lp] - 'a';
            put = s[i] - 'a';
            rollh = ((rollh - k * pop % M + M) * 26 % M + put) % M;
            if (rollh == f)
                return i - lp + 1;
        }
        
        return -1;
    }
};