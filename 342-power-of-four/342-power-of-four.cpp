class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n==4)
            return true;
        
        for(int i=0;i<31;i+=2)
            if(pow(2,i)==n)
                return true;
        
        for(int i=-30;i<=0;i+=2)
            if(pow(2,i)==n)
                return true;
        
        return false;
    }
};