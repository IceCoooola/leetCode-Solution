class Solution {
public:
    int climbStairs(int n) {
        if(n == 1)
        return 1;
        int ret = 0;
        int first = 1;
        int second = 1;
        while(--n)
        {
            ret = first + second;
            first = second;
            second = ret;
        }
        return ret;

    }
};

/* class Solution {
public:
    int climbStairs(int n) {
        int ret = 0;
        _climbStairs(n, ret);
        return ret;
    }

    void _climbStairs(int n, int& ret)
    {
        if(n == 0)
        {
            ret++;
            return;
        }
        _climbStairs(n-1, ret);
        if(n > 1)
          _climbStairs(n-2, ret);
    }
};*/
