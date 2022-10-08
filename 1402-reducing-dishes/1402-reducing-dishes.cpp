class Solution {
public:
    int solveMem(vector<int>& arr, int i, int j, vector<vector<int>> &dp){
        if(i>= arr.size()){
            return 0;
        }
        if(dp[i][j] != -1)
            return dp[i][j];
        
        return dp[i][j] = max(solveMem(arr,i+1,j,dp), (arr[i]*j + solveMem(arr,i+1,j+1,dp))); 
    }
    int maxSatisfaction(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int n = arr.size();
        vector <vector<int>> dp(n,vector<int>(n+1,-1));
        return solveMem(arr,0,1,dp);
    }
};