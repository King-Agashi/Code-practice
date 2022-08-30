class Solution {
public:
        //TC- O(r*r*c*log(n))
    int maxSubarrayWithSumLessThanK(vector<int> v, int n,int k){
        int curr=0,ans=INT_MIN;
        set<int> st;
        st.insert(0);
        for(int i=0;i<n;i++){
            curr+=v[i];
            auto it = st.lower_bound(curr-k);
            
            if(it != st.end())
                ans = max(ans , curr - *it);
          
            st.insert(curr);
        }
        return ans;
    }
    int maxSumSubmatrix(vector<vector<int>>& M, int k) {
        int R = M.size(), C = M[0].size();
        int ma= INT_MIN;

        for(int i=0;i<R;i++){
            vector<int> a(C,0);
            for(int j=i;j<R;j++){
                for(int col=0;col<C;col++){
                    a[col] += M[j][col];
                }
                ma = max(ma, maxSubarrayWithSumLessThanK(a,C,k));
            }
        }
        return ma==INT_MIN? 0:ma;
        
    }
};