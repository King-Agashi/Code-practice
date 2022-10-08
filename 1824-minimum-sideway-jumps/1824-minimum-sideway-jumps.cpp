class Solution {
public:
    int solveMem(vector<int>& ob, int p, int l, vector<vector<int>>& dp){
        if(p == ob.size()-1)
            return 0;
        if(ob[p] == l)
            return INT_MAX;
        if(dp[l][p] != -1)
            return dp[l][p];
        
        if(ob[p+1] != l){
            dp[l][p] = solveMem(ob,p+1,l,dp);
        }
        else{
            int l1 = (l-1 == 0)? l+2 : l-1;
            int l2 = (l+1 == 4)? l-2 : l+1;
            dp[l][p] = min(solveMem(ob,p,l1,dp),solveMem(ob,p,l2,dp)) + 1;
        }
        return dp[l][p];
    }
    int minSideJumps(vector<int>& obstacles) {
        int n = obstacles.size();
        vector <vector<int>> dp(4,vector<int>(n,-1));
        int ans = solveMem(obstacles, 0 , 2, dp);
        return ans;
    }
};