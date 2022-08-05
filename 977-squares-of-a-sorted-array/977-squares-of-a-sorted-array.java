class Solution {
    public int[] sortedSquares(int[] nums) {
        int[] res = new int[nums.length];
        int right = nums.length - 1;
        int left = 0;
        int index = nums.length - 1;

        while (right != left) {
            int rightNumber = nums[right] * nums[right];
            int leftNumber = nums[left] * nums[left];

            if (rightNumber >= leftNumber) {
                res[index] = rightNumber;
                index--;
                right--;
            } else {
                res[index] = leftNumber;
                index--;
                left++;
            }
        }
        res[0] = nums[right] * nums[right];

        return res;
    }
}