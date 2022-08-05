class Solution {
public:
    vector<int> twoSum(vector<int>& a,int t) {
        int n = a.size();
        vector<int>res;
        unordered_map<int,int>mp;

        for(int i=0;i<n;i++){
            if(mp.find(t - a[i]) != mp.end()){
                res.emplace_back(mp[t - a[i]]);
                res.emplace_back(i);
                return res;
            }
            else{
                mp[a[i]] = i;
            }
        }

        return res;
    }
};