class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<char> st{};
        stack<int> idx{};
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                st.push(s[i]); 
                idx.push(i);
            }
            else if (s[i] == ')') {
                if (!st.empty() && st.top() == '(') {
                    st.pop();
                    idx.pop();
                }
                else {
                    st.push(')');
                    idx.push(i);
                }
            }
        }

        string::iterator it = s.begin();
        while (!idx.empty()) {
            int i = idx.top();
            idx.pop();
            s.erase(it + i );
        }
        return s;
    }
};