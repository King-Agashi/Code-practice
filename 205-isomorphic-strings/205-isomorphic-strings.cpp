class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char, char> m;
        map<char, char> n;
        for(int i = 0;i < s.size();i++){
            char a = s[i];
            char b = t[i];
            
            if(m.count(a) == 0) { 
                m[a] = b; 
            }
            if(n.count(b) == 0){
                n[b] = a;
            }
            if(m[a] != b || n[b] != a){
                return false;
            }
        }
        return true;
    }
};