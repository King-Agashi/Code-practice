class Solution {
public:
    void helper(vector<string> &res, string &b, int open, int close) {
        if(open == 0 && close == 0) {
            res.push_back(b);
            return;
        }
        
        if(open == close) {
            b.push_back('(');
            helper(res, b, open - 1, close);
            b.pop_back();
        }
        
        else {
            if(open > 0) {
                b.push_back('(');
                helper(res, b, open - 1, close);
                b.pop_back();
            }
            
            b.push_back(')');
            helper(res, b, open, close - 1);
            b.pop_back();
        }
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string b;
        helper(ans, b, n, n);
        return ans;
    }
};