class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n==3)
            return true;
        
        for(int i=-30;i<31;i+=1)
            if(pow(3,i)==n)
                return true;
        
        return false;
    }
};