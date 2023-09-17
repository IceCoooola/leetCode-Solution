class Solution {
public:
    int longestPalindrome(string s) {
        int sz = s.length();
        unordered_map<char, int> mp;
        int ret = 0;
        bool odd = false;
        for(int i = 0; i < s.length(); i++)
        {
            mp[s[i]]++;
        }
        for(auto e: mp)
        {
            if(e.second % 2 == 0)
            {
                ret += e.second;
            }
            else
            {
                ret += e.second - 1;
                odd = true;
            }
        }
        if(odd)
            return ret + 1;
        return ret;
    }
};
