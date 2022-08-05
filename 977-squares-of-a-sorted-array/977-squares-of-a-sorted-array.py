class Solution:
    def sortedSquares(self, nums: List[int]) -> List[int]:
        def sq(num):
            return num*num
        return sorted(list(map(sq,nums)))