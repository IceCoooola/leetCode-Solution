class Solution {
public:
    void reverse(string& s, int left, int right)
    {
        while(left < right)
        {
            swap(s[left], s[right]);
            left++;
            right--;
        }
    }
    
    string reverseStr(string s, int k) {
        int prev = 0;
        int cur = k-1;
        while(cur < s.size())
        {
            reverse(s, prev, cur);
            prev+=(2*k);
            cur+=(2*k);
        }
        if(prev < s.size())
        {
            reverse(s, prev, s.size()-1);
        }
        return s;
    }
};
