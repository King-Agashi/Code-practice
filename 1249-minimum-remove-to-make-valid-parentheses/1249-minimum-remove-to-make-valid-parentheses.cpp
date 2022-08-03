class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int left=0;
        string ans;
        for(char c:s){
            if(c=='('){left++;ans.push_back(c);}
            else if(!left && c==')'){continue;}
            else if(left && c==')'){left--;ans.push_back(c);}
            else{ans.push_back(c);}
        }int i=ans.size()-1;
        while(left && i>=0){
            if(ans[i]=='('){ans.erase(ans.begin()+i);left--;}
            else{i--;}
        }return ans;
    }
};