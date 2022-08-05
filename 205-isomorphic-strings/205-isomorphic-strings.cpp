class Solution {
public:
    bool isIsomorphic(string s, string t) {
        
        unordered_map<char,char>ma;
        unordered_set<char>mapped;
        
        if(s.length()!=t.length())
            return false;
        
        for(int i=0;i<s.length();i++){
            char ch1=s[i];
            char ch2=t[i];
            
            if(ma.find(ch1)!=ma.end()){
                if(ma[ch1]!=ch2)
                    return false;
            }
            
            else{
                if(mapped.find(ch2)!=mapped.end())
                    return false;
                
                mapped.insert(ch2);
                ma[ch1]=ch2;
            }
        }
        return true;
    }
};