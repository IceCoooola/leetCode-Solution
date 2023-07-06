class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        int i = 0;
        int j = 0;
        string ret;
        while(i < m && j < n)
        {
            ret += word1[i++];
            ret += word2[j++];
        }
        while(i < m)
        {
            ret += word1[i++];
        }
        while(j < n)
        {
            ret += word2[j++];
        }
        return ret;
    }
};
