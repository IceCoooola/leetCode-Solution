class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) {
            return "1";
        }
        else 
        {
            string prev = countAndSay(n-1);// 11
            string ret = count(prev);
            return ret;
        }
    }

    string count(string s) {
        char prev = s[0];
        int n = 1;
        string ret = "";
        
        for (int i = 1; i < s.length(); ++i) {
            if (s[i] == prev) {            
                n += 1;
            }
            else {
                ret += to_string(n);
                ret += prev;
                n = 1;
                prev = s[i];
            }
        }
        ret += to_string(n);
        ret += prev;
        return ret;
    }
    
};
