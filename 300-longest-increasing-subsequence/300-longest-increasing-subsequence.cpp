class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int ans=1;
        vector<int>x(nums.size(),1);
        for(int i=1;i<nums.size();i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j] && x[i]<=x[j])
                    x[i]=x[j]+1;
                ans=max(ans,x[i]);
            }
        }
        return ans;
    }
};