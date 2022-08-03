class Solution {
public:
    int maxArea(vector<int>& h) {
        int w = 0, i = 0, j = h.size() - 1;

        while (i < j) {
            int m = min(h[i], h[j]);

            w = max(w, (j - i) * m);

            while (h[i] <= m && i < j)
                i++;
            while (h[j] <= m && i < j)
                j--;
        }
        return w;
    }
};