class Solution {
public:
    double myPow(double x, int n) {
        if(x == 1)
            return 1;
        if(x == -1)
        {
            if(abs(n) % 2 == 1)
            return -1;
            else 
            return 1;
        }
        bool flag = true;
        if(n < 0)
        {
            flag = false;
            if(n == INT_MIN)
                n = INT_MAX;
            else
                n = abs(n);
        }
        int mod = n % 4;
        if(n == INT_MAX && flag == false)
           mod += 1;
        double ret = 1;
        if(n == 0)
            return 1;
        for(int i = 0; i < n / 4; i++)
        {
            ret *= (x * x * x * x);
        }
        while(mod)
        {
            ret *= x;
            mod--;
        }
        if (flag == false)
            ret = 1.00/ret;
        return ret;
    }
};
