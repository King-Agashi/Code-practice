class Solution {
public:
    int dp[50][50];
    int minScoreTriangulation(vector<int>& A) {
        int n=A.size();
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                dp[i][j]=INT_MAX;
        return solve(A,n);
    }
private:
    int solve(vector<int>& A, int n){
        for(int k=0;k<n;k++){
            int j=k;
            for(int i=0;i<n-k;i++){
                if(i==j || i+1==j)
                    dp[i][j]=0;
                else{
                    for(int p=i+1;p<j;p++){
                        int r1=dp[i][p];
                        int r2=dp[p][j];
                        dp[i][j]=min(dp[i][j],r1+r2+A[i]*A[j]*A[p]);
                    }
                }
                j++;
            }
        }
        return dp[0][n-1];
    }
};