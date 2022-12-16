class Solution {
public:
    int reverse(int x) {
        if(x == 0)
        return 0;
        queue<int> q;
        int flag = 1;
        long ret = 0;
        if(x <= 0)
        {
            flag = -1;
        }
        x = abs(x);
        while(x)
        {
            int val = x % 10;
            q.push(val);
            x/=10;
        }
        long factor = pow(10, q.size()-1);
        while(!q.empty())
        {
            ret += q.front() * factor;
            if(ret > INT_MAX || ret < 0 - 1 - INT_MAX)
        {
            return 0;
        }
            factor /= 10;
            q.pop();
        }
        ret *= flag;
        return ret;
    }
};
