class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.length();
        if (n == 0) return 0;
        stack<int> st;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '(') {
                st.push(i);
            } else {
                if (!st.empty() && s[st.top()] == '(') st.pop();
                else st.push(i);
            }
        }
        if (st.empty()) return n;
        int ret = 0;
        int last = n;
        int top = st.top();
        while (!st.empty()) {
            top = st.top();
            ret = max(last - top - 1, ret);
            last = top;
            st.pop();
        }
        ret = max(ret, top);
        return ret;
    }
};
