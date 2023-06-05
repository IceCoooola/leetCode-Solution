class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if(s.size() != goal.size())
            return false;
        int flag = 0;
        vector<int> v;
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] != goal[i])
                {
                    ++flag;
                    v.push_back(i);
                }
        }
        if(flag == 2)
        {
            if(s[v[0]] == goal[v[1]] && s[v[1]] == goal[v[0]])
                return true;
            else
                return false;
        }
        else if(flag == 0)
        {
            for(int i = 0; i < s.size(); i++)
            {
                for(int j = i+1; j < s.size(); j++)
                {
                    if(s[i] == s[j])
                        return true;
                }
            }
            return false;
    }
        else
    {        return false;}
    }
};
