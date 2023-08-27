class Solution {
public:
    bool wordPattern(string pattern, string s) {
        stringstream ss(s);
        unordered_map<char, string> mp1;
        unordered_map<string, char> mp2;
        string e = "";
        for(int i = 0; i < pattern.length(); i++)
        {
            ss >> e;
            if(mp1.find(pattern[i]) == mp1.end())
                mp1[pattern[i]] = e;
            if(mp2.find(e) == mp2.end())
                mp2[e] = pattern[i];
            if(mp1[pattern[i]] != e || mp2[e] != pattern[i])
                return false;
        }
        if (ss >> e)
            return false;
        return true;
    }
};
// class Solution {
// public:
//     bool wordPattern(string pattern, string s) {
        
//         stringstream str(s);
//         map<char, string> dic;
//         int i = 0;
//         while(str >> s)
//         {
//             if(dic.find(pattern[i]) == dic.end())
//             {
//                 for(auto e : dic)
//                 {
//                     if(e.second == s)
//                         return false;
//                 }
//                 dic[pattern[i]] = s;
//             }
//             else if(dic[pattern[i]] != s)
//             {
//                 return false;
//             }
//             ++i;
//         }
//         if(i != pattern.size())
//             return false;
//         return true;
//     }
// };
