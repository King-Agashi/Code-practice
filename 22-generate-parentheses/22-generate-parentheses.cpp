class Solution {
public:
    void solve(int n,string s,vector<string>&ans,int open){
        if(!n && !open){        ///if the len of string is 2*n and is balanced{i.e no. of  "("  = no. of ")"    }
            ans.push_back(s);
            return;
            
        }
        if(n){                  
            solve(n-1,s+"(",ans,open+1);
            
        }
        if(open){                ////check if there is "(" in excess
            solve(n,s+")",ans,open-1);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        solve(n,"",ans,0);
        return ans;
        
    }
};