class Solution {
public:
    const vector<string> pad = {
        "abc"   ,   // 2
        "def"   ,   // 3
        "ghi"   ,   // 4
        "jkl"   ,   // 5
        "mno"   ,   // 6
        "pqrs"  ,   // 7
        "tuv"   ,   // 8
        "wxyz"      // 9
    };
    
    vector<string> letterCombinations(string dig) {
        if (dig.empty())                    // Base case
            return {};
		
        vector<string> r;                   // Result string defined and init
        r.push_back("");
        
        for(auto d: dig){
            vector<string> t;               // Temp string to store res
            for(auto i: pad[d - '2']) {     // Iterate to the pressed key
                for(auto j: r) {            // Take all letters
                    t.push_back(j + i);
                }
            }
            r.swap(t);
        }
        return r;
    }
};