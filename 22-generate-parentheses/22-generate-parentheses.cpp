class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans={"()"};
        for(int i=1;i<n;i++)
        {
            int m = ans.size();
            for(int j=0;j<m;j++)
            {
                string temp= ans[j];
                int k=temp.length()-1;
                while(temp[k]==')')
                {
                    string temp2 = temp;
                    temp2.insert(k,"()");
                    ans.push_back(temp2);
                    k--;
                }
                ans[j]=ans[j]+"()";
            }
        }
        return ans;
    }
};