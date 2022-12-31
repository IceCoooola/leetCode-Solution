class Solution {
public:
    int lengthOfLastWord(string s) {
        stringstream str(s);
        while(str >> s)
        ;
        return s.size();
    }
};
