class Solution {
public:
    int poorPigs(int b, int md, int mt) {
        int tests = mt/md + 1;
        return ceil(log(b)/log(tests));
    }
};