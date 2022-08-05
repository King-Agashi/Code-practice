class Solution {
    public void rotate(int[] n, int k) {
        k = k % n.length;
        reverse(n, 0, n.length-1);
        reverse(n, 0, k-1);
        reverse(n, k, n.length-1);
    }
    
    public void reverse(int[] n, int s, int e) {
        while(s <= e) {
            int t = n[s];
            n[s] = n[e];
            n[e] = t;
            s++;
            e--;
        }
    }
}