class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(s.length() == 0)
            return true;
        int idx = 0;
        for(int i = 0; i < s.length(); i++)
        {
            while(idx < t.length() && t[idx] != s[i])   idx++;
            idx++;
        }
        if(idx > t.size())
            return false;
        return true;
    }
    
};
