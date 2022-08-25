class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        if(ransomNote.size()> magazine.size()){
            return false;
        }
        
        vector<int> ransomNoteCounter(26, 0);
        vector<int> magazineCounter(26, 0);

        for(int i=0; i<ransomNote.size(); i++){
            ransomNoteCounter[ransomNote[i]-'a']++;
        }
        for(int i=0; i<magazine.size(); i++){
            magazineCounter[magazine[i]-'a']++;
        }
        for(int i=0; i<26; i++){
            if (ransomNoteCounter[i]>magazineCounter[i]){
                return false;
            }
        }
        return true;
    }
};