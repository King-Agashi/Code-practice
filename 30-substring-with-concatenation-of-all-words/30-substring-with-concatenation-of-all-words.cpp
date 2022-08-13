class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        
        vector<int> res;
        int wordslen = words.size();
        int wlen = words[0].size();
        int len = s.size();
        unordered_map<string, int> M;
        
        for(int i=0;i<wordslen;i++){
            M[words[i]] += 1;
        }
        
        for(int i=0;i + wlen*wordslen <= len;i++){
            
            int startIdx = i;
            bool isValid = true;
            unordered_map<string, int> tM = M;
            
            while(startIdx < i + wlen*wordslen){
                string wrd = s.substr(startIdx, wlen);
                if(tM[wrd] > 1){
                    tM[wrd] -= 1;    
                } else if(tM[wrd] == 1){
                    tM.erase(wrd);
                }else{
                    isValid = false;
                    break;
                }
                
                startIdx += wlen;
            }
            
            if(isValid && tM.size() == 0){
               res.push_back(i); 
            }
        }
        
        return res;
    }
};