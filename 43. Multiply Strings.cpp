class Solution {
public:

    void reverse(string& s, int left, int right)
    {
        while (right > left)
        {
            swap(s[left], s[right]);
            right--;
            left++;
        }
    }

    string addStrings(string num1, string num2) {
        string retstr;
        int end1 = num1.size() - 1;
        int end2 = num2.size() - 1;
        int carry = 0;
        while (end1 >= 0 || end2 >= 0)
        {
            int temp1 = 0, temp2 = 0, ttl = 0;
            if (end1 >= 0)
                temp1 = num1[end1] - '0';
            if (end2 >= 0)
                temp2 = num2[end2] - '0';
            ttl = temp1 + temp2 + carry;
            if (ttl > 9)
            {
                carry = 1;
                ttl -= 10;
            }
            else
            {
                carry = 0;
            }
            retstr += (ttl + '0');
            end1--;
            end2--;
        }
        if (carry == 1)
        {
            retstr += '1';
        }
        int start = 0;
        int end = retstr.size() - 1;
        while (start < end)
        {
            swap(retstr[start], retstr[end]);
            start++;
            end--;
        }
        return retstr;

    }

    string multiply(string num1, string num2) {
        if(num1[0] == '0' || num2[0] == '0')
        {
            string s("0");
            return s;
        }
        int end1 = num1.size() - 1;
        string ttlstr;
        int carry = 0;
        int sign = 0;
        for (end1; end1 >= 0; end1--)
        {
            string tmpstr;
            for (int j = sign; j > 0; j--)
            {
                tmpstr += '0';
            }
            for (int i = num2.size() - 1; i >= 0; i--)
            {
                int temp1 = num1[end1] - '0';
                int temp2 = num2[i] - '0';
                int product = temp1 * temp2 + carry;
                if (product > 9)
                {
                    carry = product / 10;
                    product %= 10;
                }
                else
                {
                    carry = 0;
                }
                tmpstr += (product + '0');
            }
            if (carry != 0)
            {
                tmpstr += (carry + '0');
                carry = 0;
            }
            reverse(tmpstr, 0, tmpstr.size()-1);
            ttlstr = addStrings(tmpstr, ttlstr);
            sign += 1;
        }
        return ttlstr;
    }
};
