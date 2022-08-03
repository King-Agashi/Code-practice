class Solution {
public:
    int threeSumClosest(vector<int>& a, int t) {
        sort(a.begin(), a.end());
        int n = a.size();
        
        int s = a[0] + a[1] + a[2];
        
        for(int i = 0; i < n-2; i++){
            int j = i + 1, k = n - 1;
            
            while(j < k){
                int x = a[i] + a[j] + a[k];
                
                if(abs(x-t) < abs(s-t))
                    s = x;
                
                if(x > t)
                    k--;
                else if(x < t)
                    j++;
                else
                    return t;
            }
        }
        return s;
    }
};