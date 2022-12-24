class Solution {
public:
    int myAtoi(string s) {
        stringstream str(s);
        str >> s;
        int flag = 1;
        long ret = 0;
        if(s[0] == '-' || s[0] == '+')
        {
            if(s[0] == '-')
                flag = -1;
            s.erase(0, 1);
        }
        for(int j = 0; j < s.size(); j++)
        {
            if(s[j] - '0' > 9 ||s[j] - '0' < 0)
             {
                    s.erase(j);
                    break;
            }
        }
        int tmp = 0;
        while(s[tmp] == '0')
        {
            tmp++;
        }
        if(tmp)
        {
            s.erase(0, tmp);
        }
        if(s.size() == 0)
            return ret;
        if(s.size() > 10)
        {
                if(flag == -1)
                return INT_MIN;
                else
                return INT_MAX;
        }
            long factor = pow(10, s.size() - 1);
            for(int i = 0; i < s.size();i++)
            {
                ret += (s[i] - '0') * factor;
                factor /= 10;
            }
        
        ret *= flag;
        if(ret > INT_MAX)
        ret = INT_MAX;
        if(ret < INT_MIN)
        ret = INT_MIN;
        return ret;
    }
};
