class Fancy {
public:
    unsigned long s[100001], inc = 0, m = 1;
    unsigned int len = 0;
    int M = 1000000007;
    
    Fancy() {
    }
    
    unsigned long modPow(unsigned long x, int y) {
    unsigned long tot = 1, p = x;
    for (; y; y >>= 1) {
        if (y & 1)
            tot = (tot * p) % M;
        p = (p * p) % M;
    }
    return tot;
}
    
    void append(int val) {
        s[len++] = (((M + val - inc)%M) * modPow(m, M-2))%M;
    }
    void addAll(int i) {
        inc = (inc+ i%M)%M;
    }
    
    void multAll(int x) {
        m = (m* x%M)%M;
        inc = (inc* x%M)%M;
    }
    
    int getIndex(int i) {
        
        if (i >= len){
            return -1;
        }else{
            return ((s[i] * m)%M+inc)%M;
        }
    }
};
