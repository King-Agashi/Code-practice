class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        vector<int>v(nums);
        for(int i=1; i<nums.size(); i++)
            nums[i] += nums[i-1];

        for(int i=nums.size()-2; i>=0;i--)
            v[i] += v[i+1];

        int f=0,s=0;
        
        for(int i=0; i<nums.size();i++){
            if(v[f] == nums[s])
                return s;
            else
                f++, s++;
        }
        return -1;
    }
};