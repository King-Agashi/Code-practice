class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        int n = arr.size();
        long long int modn = 1000000007;
        vector<long long int> dp(n, 1);
        sort(arr.begin(), arr.end());
        unordered_map<int, int> index;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++){
                if(arr[i] % arr[j]){
                    continue;
                }
                int m = arr[i] / arr[j];
                if(index.find(m) != index.end()){
                    dp[i] += 1L*dp[j]*dp[index[m]];
                    dp[i] %= modn;
                }
            }
            index[arr[i]] = i;
        }
        return accumulate(dp.begin(), dp.end(), 0L)%modn;
    }
};