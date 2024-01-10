class Solution {
public:
    string freqAlphabets(string s) {
        int i = s.length() - 1;
        string ret = "";
        string tmp = "";
        while (i >= 0) {
            if (s[i] == '#') {
                tmp = 'a' + stoi(s.substr(i-2, 3)) - 1;
                ret = tmp + ret;
                i -= 3;
            }
            else {
                tmp = 'a' + stoi(s.substr(i, 1)) - 1;
                ret = tmp + ret;
                i -= 1;
            }
        }
        return ret;
    }
};
