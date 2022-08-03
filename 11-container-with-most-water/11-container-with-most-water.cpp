class Solution {
public:
    int maxArea(vector<int>& h) {
        int l=0,r=h.size()-1;
        int res=0;
        
        while(l<r){
            int lh=h[l];
            int rh=h[r];
            
            res=max(res,(r-l)*min(lh,rh));
            
            if(lh<rh) ++l;
            else --r;
        }
		
        return res;
    }
};