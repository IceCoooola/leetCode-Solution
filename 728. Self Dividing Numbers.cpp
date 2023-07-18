class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> ret;
        for(int i = left; i <= right; i++)
        {
            int t = i;
            bool flag = true;
            while(t)
            {
                if(t % 10 == 0)
                {
                    flag = false;
                    break;
                }
                if (i % (t % 10) != 0)
                {
                    flag = false;
                    break;
                }
                t /= 10;
            }
            if(flag == true)
            {
                ret.push_back(i);
            }
        }
        return ret;
    }
};
