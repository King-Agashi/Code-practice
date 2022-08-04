class Solution {
public:
    int mirrorReflection(int p, int q) {
        if (!(p & 1) && !(q & 1))
            return mirrorReflection(p/2, q/2);
        return 1 - p % 2 + q % 2;
    }
};