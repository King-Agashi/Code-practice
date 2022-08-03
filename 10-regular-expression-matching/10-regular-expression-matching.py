class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        q = []

        # pre-processing
        temp = p[0]
        for char in p[1:]:
            if char != "*":
                q.append(temp)
                temp = char
            else:
                temp += char
        q.append(temp)
        print(q)

        # initiating dp table
        dp = [[False] * (len(q)+1) for _ in range(len(s)+1)]

        # base case
        dp[0][0] = True
        for ndx in range(1,len(q)+1):
            if len(q[ndx-1]) == 2:
                dp[0][ndx] = True
            else:
                break

        # fill in the table
        for j in range(1,len(q)+1):
            for i in range (1, len(s)+1):
                if len(q[j-1]) == 1:
                    if (dp[i-1][j-1] == True) and (q[j-1]==s[i-1] or q[j-1]=="."):
                        dp[i][j] = True
                else:
                    if ((dp[i-1][j] == True) and 
                        (q[j-1][0]==s[i-1] or q[j-1][0]==".")) or dp[i][j-1] == True:
                        dp[i][j] = True


        return dp[len(s)][len(q)]