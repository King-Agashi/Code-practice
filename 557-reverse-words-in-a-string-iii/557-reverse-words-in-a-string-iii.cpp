class Solution {
public:
    string reverseWords(string s) {
        int n=s.size();
        int i=0;
        int k=0;
        while(i<n){
            if(s[i]==' ')
            {
                reverse(s.begin()+k,s.begin()+i);
                k=i+1;
            }
            i++;
        }
        reverse(s.begin()+k,s.begin()+i);
        return s;
    }
};