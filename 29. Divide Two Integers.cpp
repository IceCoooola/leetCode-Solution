class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend >= INT_MAX)
        {
            if(divisor == 1)
            return INT_MAX;
            if(divisor == -1)
            return -1 * INT_MAX;
        }
        if(dividend <= INT_MIN)
        {
            if(divisor == 1)
            return INT_MIN;
            if(divisor == -1)
            return INT_MAX;
        }
        int flag = dividend > 0 ? 1 : -1;
        divisor > 0 ? flag *= 1: flag *= -1;
        long dividend1 = abs(dividend);
        long divisor1 = abs(divisor);
        long ret = 0;
        while(dividend1 > 0)
        {
            dividend1 -= divisor1;
            ret++;
        }
        if(ret != 0 && dividend1 != 0)
            ret -= 1;
        ret *= flag;
        if(ret > INT_MAX)
           return INT_MAX;
        return ret;
    }
};
