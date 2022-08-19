class Solution {
public:
    bool isPossible(vector<int>& nums) {
        int a = 0, b = 0, c = 0, i = 0;
        for(int k = -1000; k <= 1001; k++){
            int q = 0;
            
            while(i<nums.size() && nums[i]==k)
                i++,q++;
            
            if(q<a+b)
                return false;
            
            int s = max(0, q-a-b-c);
            
            c = q - s - a;
            b = a;
            a = s;
        }
        return true;
    }
};