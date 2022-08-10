class Solution {
public:
    bool check_alphas(std::vector<int>& alpha_target, std::vector<int>& alpha_word)
    {
        int j = 0;
        while (j < 26 && alpha_target[j] == alpha_word[j])
        {
            j++;
        }
        if (j == 26)
            return true;
        return false;
    }
    bool checkInclusion(string s1, string s2) {
        std::vector<int>alpha_target(26);
        std::vector<int>alpha_word(26);
        if (s1.size() > s2.size())
        {
            return false;
        }
        
        for (int i = 0; i < s1.size(); ++i)
        {
            alpha_target[s1[i] - 'a'] += 1;
            alpha_word[s2[i] - 'a'] += 1;
        }
        if (check_alphas(alpha_target, alpha_word))
            return true;
        for (int i = s1.size(); i < s2.size(); ++i)
        {
            
            alpha_word[s2[i - s1.size()] - 'a'] -= 1;
            alpha_word[s2[i] - 'a'] += 1;
            if (check_alphas(alpha_target, alpha_word))
                return true;
        }
        return false;
    }
};