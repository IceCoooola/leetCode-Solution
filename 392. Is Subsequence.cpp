class Solution {
public:
    bool isSubsequence(string s, string t) {
        int idx = 0;
        for(int i = 0; i < t.length() && idx < s.length();i++)
        {
            if(s[idx] == t[i])
                idx++;
        }
        return idx == s.length();
    }
};
// class Solution {
// public:
//     bool isSubsequence(string s, string t) {
//         if(s.length() == 0)
//             return true;
//         int idx = 0;
//         for(int i = 0; i < s.length(); i++)
//         {
//             while(idx < t.length() && t[idx] != s[i])   idx++;
//             idx++;
//         }
//         if(idx > t.size())
//             return false;
//         return true;
//     }
    
// };
