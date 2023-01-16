class Solution {
public:
    bool wordPattern(string pattern, string s) {
        
        stringstream str(s);
        map<char, string> dic;
        int i = 0;
        while(str >> s)
        {
            if(dic.find(pattern[i]) == dic.end())
            {
                for(auto e : dic)
                {
                    if(e.second == s)
                        return false;
                }
                dic[pattern[i]] = s;
            }
            else if(dic[pattern[i]] != s)
            {
                return false;
            }
            ++i;
        }
        if(i != pattern.size())
            return false;
        return true;
    }
};
