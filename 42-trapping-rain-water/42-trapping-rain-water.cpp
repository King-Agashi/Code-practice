class Solution {
public:
    int trap(vector<int>& a) {
        
        // Declarations and inits
        int n       =   a.size(),
            l       =   0       ,
            r       =   n - 1   ,
            res     =   0       ,
            maxl    =   0       ,
            maxr    =   0       ;
        
        while(l <= r){
            if(a[l] <= a[r]) {
                if(a[l] >= maxl)
                    maxl = a[l];
                else
                    res += maxl - a[l];
                l++;
            }
            
            else{
                if(a[r] >= maxr)
                    maxr = a[r];
                else
                    res += maxr - a[r];
                r--;
            }
        }
        
        return res;
    }
};