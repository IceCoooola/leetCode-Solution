class Solution {
public:
    int mySqrt(int x) {
        int ret = 0;
        while((long)ret * ret <= x)
        {
            ++ret;
            if((long)ret * ret == x)
              return ret;
        }
        return ret - 1;
    }
};
