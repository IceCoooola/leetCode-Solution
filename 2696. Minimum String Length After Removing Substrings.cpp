class Solution {
public:
    int minLength(string s) {
        if(s.size() == 1)
            return 1;
        bool flag = true;
        while(flag)
        {
            flag = false;
            for(int i = 0; i < s.size(); i++)
            {
                if(s[i] == 'A' && i < s.size() - 1)
                {
                    if(s[i+1] == 'B')
                    {
                        s.erase(i, 2);
                        flag = true;
                    }
                }
                if(s.size() == 0)
                    return 0;
                if(s[i] == 'C' && i < s.size() - 1)
                {
                    if(s[i+1] == 'D')
                    {
                        s.erase(i, 2);
                        flag = true;
                    }
                }
                if(s.size() == 0)
                    return 0;
            }
        }
        cout<<s;
        return s.size();
    }
};
