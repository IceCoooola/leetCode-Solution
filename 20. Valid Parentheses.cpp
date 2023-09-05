class Solution {
public:
    bool isValid(string s) {
        if(s[0] == '}' || s[0] == ')' || s[0] == ']')
            return false;
        stack<char> st;
        int sz = s.length();
        st.push(s[0]);
        for(int i = 1; i < sz; i++)
        {
            if(s[i] == '}' || s[i] == ')' || s[i] == ']')
            {
                if(st.empty()) return false;
                if(s[i] == '}' && st.top() != '{') return false;
                else if(s[i] == ')' && st.top() != '(') return false;
                else if(s[i] == ']' && st.top() != '[') return false;
                st.pop();
            }
            else
            {
                st.push(s[i]);
            }
        }
        if(st.empty())
            return true;
        else
            return false;
    }
};
