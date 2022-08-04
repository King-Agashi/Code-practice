class Solution {
public:
    int pivotIndex(vector<int>& nums) 
    {
        for(int i=0;i<nums.size();i++)
        {
            int l=accumulate(nums.begin(),nums.begin()+i,0);
            int r=accumulate(nums.begin()+i+1,nums.end(),0);
            
            if(l==r)
            return i;
        }
        return -1;
    }
};