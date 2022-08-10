class Solution
{
    public:
        int lengthOfLongestSubstring(string s)
        {
            map<char, int> seen;
            int maxl = 0, st = 0;

            for (int end = 0; end < s.length(); end++)
            {
                if (seen.find(s[end]) != seen.end())
                    st = max(st, seen[s[end]] + 1);

                seen[s[end]] = end;

                maxl = max(maxl, end - st + 1);
            }

            return maxl;
        }
};