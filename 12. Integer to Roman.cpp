class Solution {
public:
    string ToLetter(int value)
    {
        string ret;
        if(value >= 1000)
        {
            while(value)
            {
                ret += "M";
                value -= 1000;
            }
        }
        else if (value >= 500)
        {
            if(value == 900)
            {
                ret += "CM";
            }
            else
            {
                ret += "D";
                value -= 500;
                while(value)
                {
                    ret += "C";
                    value -= 100;
                }
            }
        }
        else if(value >= 100)
        {
            if(value == 400)
            {
                ret += "CD";
            }
            else
            {
                while(value)
                {
                    ret += "C";
                    value -= 100;
                }
            }
        }
        else if(value >= 50)
        {
            if(value == 90)
            {
                ret += "XC";
            }
            else
            {
                ret += "L";
                value -= 50;
                while(value)
                {
                    ret += "X";
                    value -= 10;
                }
            }
        }
        else if(value >= 10)
        {
            if(value == 40)
            {
                ret += "XL";
            }
            else
            {
                while(value)
                {
                    ret += "X";
                    value -= 10;
                }
            }
        }
        else if(value >= 5)
        {
            if( value == 9)
            {
                ret += "IX";
            }
            else
            {
                ret += "V";
                value -= 5;
                while(value)
                {
                    ret += "I";
                    value -= 1;
                }
            }
        }
        else
        {
            if(value == 4)
            {
                ret += "IV";
            }
            else
            {
                while(value)
                {
                    ret += "I";
                    value -= 1;
                }
            }
        }
        return ret;
    }
    string intToRoman(int num) {
        string ret = "";
        int factor = 1000;
        while(factor)
        {
            int first = num / factor;
            int left = num % factor;
            if(left == num)
            {
                factor /= 10;
                continue;
            }
            first *= factor;
            ret += ToLetter(first);
            num %= factor;
            factor /= 10;
        }
        return ret;
    }
};
