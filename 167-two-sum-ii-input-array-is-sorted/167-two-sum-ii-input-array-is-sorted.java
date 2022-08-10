class Solution {
    public int[] twoSum(final int[] a, final int target) {
        int l = 0;
        int r = a.length - 1;
        while (l < r) {
            final int sum = a[l] + a[r];
            if (sum == target) {
                return new int[]{l + 1, r + 1};
            }
            if (sum > target) {
                r = leftBinarySearch(a, l + 1, r - 2, target - a[l]);
            } else {
                l = rightBinarySearch(a, l + 2, r - 1, target - a[r]);
            }
        }
        throw new IllegalStateException("Impossible by the condition of this problem");
    }

    private int leftBinarySearch(final int[] a, int l, int r, final int key) {
        l--;
        r++;

        while (r > l + 1) {
            final int m = l + (r - l) / 2;
            if (a[m] >= key) {
                r = m;
            } else {
                l = m;
            }
        }

        return r;
    }

    private int rightBinarySearch(final int[] a, int l, int r, final int key) {
        l--;
        r++;

        while (r > l + 1) {
            final int m = l + (r - l) / 2;
            if (a[m] <= key) {
                l = m;
            } else {
                r = m;
            }
        }
        return l;
    }
}