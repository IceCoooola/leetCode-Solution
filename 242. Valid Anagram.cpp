class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length())
            return false;
        map<char, int> mp;
        int sz = s.length();
        for(int i = 0; i < sz; i++)
        {
            mp[s[i]]++;
            mp[t[i]]--;
        }
        for(auto e: mp)
        {
            if(e.second != 0)
                return false;
        }
        return true;
    }
};
// class Solution {
// public:
//     bool isAnagram(string s, string t) {
//         if(s.size()!= t.size())
//             return false;
//         map<char, int> compare;
//         for(int i = 0; i < s.size(); ++i)
//         {
//             compare[s[i]]++;
//         }
//         for(int i = 0; i < t.size(); ++i)
//         {
//             compare[t[i]]--;
//         }
//         for(auto e: compare)
//         {
//             if(e.second != 0)
//               return false;
//         }
//         return true;
//     }
// };
