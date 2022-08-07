import numpy as np

class Solution:
    def countVowelPermutation(self, n): 
        def power(mat, n, M):
            result = np.eye(len(mat), dtype = int)
            while n > 0:
                if n%2: result = np.dot(mat, result) % M
                mat = np.dot(mat, mat) % M
                n //= 2
            return result
        
        M = 10**9 + 7
        mat = np.matrix([[0,1,0,0,0], [1,0,1,0,0], [1,1,0,1,1], [0,0,1,0,1], [1,0,0,0,0]])      
        return np.sum(power(mat, n-1, M)) % M