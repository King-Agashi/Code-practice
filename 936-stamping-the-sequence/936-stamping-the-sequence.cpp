class Solution {
public:
    vector<int> movesToStamp(string stamp, string target) {
        unordered_map<char,vector<int>> map;
        for(int i=0;i<stamp.size();i++)
            map[stamp[i]].push_back(i);
        vector<int> ret;
        string old;
        do
        {
            old=target;
            int star=0;
            for(int i=0;i<target.size();i++)
            {
                if(target[i]=='*')
                {
                    star++;
                    continue;
                }
                if(map.find(target[i])!=map.end()&&map[target[i]][0]<=star)
                {
                    for(int z=0;z<map[target[i]].size();z++)
                    {
                        int index = map[target[i]][z];
                        if(i+stamp.size()-index<=target.size())
                        {
                            if(index<=star)
                            {
                                if(check(stamp,target,i,index))
                                {
                                    ret.insert(ret.begin(),i-index);
                                    for(int j=i;j<i+stamp.size()-index;j++)
                                    {
                                        target[j]='*';
                                        cout<<j;
                                    }
                                    i += stamp.size()-index-1;
                                    break;
                                }
                            }
                            else
                            {
                                break;
                            }
                        }
                    }
                }
                star=0;
            }
        }
        while(ret.size()<=10*target.size()&&old!=target);
        for(char c:target)
            if(c!='*')
                return {};
        return ret;
    }
    bool check(string& stamp, string& target, int i, int z)
    {
        for(int j=0;j<stamp.size()-z;j++)
            if(stamp[z+j]!=target[i+j]&&target[i+j]!='*')
                return false;
        return true;
    }
    
};