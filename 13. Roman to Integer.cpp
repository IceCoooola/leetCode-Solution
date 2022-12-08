class Solution {
public:
    int retVal(const char& input)
    {
        switch(input)
        {
            case 'I':
            return 1;
            case 'V':
            return 5;
            case'X':
            return 10;
            case 'L':
            return 50;
            case 'C':
            return 100;
            case 'D':
            return 500;
            case 'M':
            return 1000;
        }
        return 0;
    }
    int romanToInt(string s) {
        int ret = 0;
        for(char i = 0; i < s.size(); i++)
        {
            if(i < s.size()&&
            retVal(s[i]) < retVal(s[i+1]))
            ret -= retVal(s[i]);
            else
            ret+=retVal(s[i]);
        }
        return ret;
    }
};
