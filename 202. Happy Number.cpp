class Solution {
public:
    bool isHappy(int n) {
        int count = 10000;
        set<int> st;
        st.insert(n);
        while(n != 1)
        {
            int t = 0;
            while(n)
            {
                t = t + pow((n%10) , 2);
                n /= 10;
            }
            n = t;
            if(st.count(n))
                return false;
            st.insert(n);
        }
        return true;
    }
};
