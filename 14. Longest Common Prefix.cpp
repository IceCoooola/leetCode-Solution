class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 1)
            return strs[0];
        if(strs[0].length() == 0)
            return "";
        int idx = 0;
        string ret = "";
        while(idx < strs[0].length())
        {        
            for(int i = 1; i < strs.size(); i++)
            {
            if(idx >= strs[i-1].length() ||idx >= strs[i].length() || strs[i][idx] != strs[i-1][idx])
            {
                return ret;
            }
            }
        ret += strs[0][idx++];
        }
    return ret;
    }
};
// class Solution {
// public:
//     string longestCommonPrefix(vector<string>& strs) {
//         string ret;
//         int pos = 0;
//         bool flag = true;
//         if(strs[0].size() == 0)
//         return ret;
//         if(strs.size() == 1)
//         {
//             ret = strs[0];
//             return ret;
//         }
//         while(flag)
//         {
//         for(int i = 1; i < strs.size(); ++i)
//         {
//             if (strs[i].size() == 0||pos >= strs[i].size()||strs[i][pos] != strs[i-1][pos])
//             {
//                 flag = false;
//             } 
//         }
//         if(flag == true)
//         ret += strs[0][pos];
//         pos++;
//         }
//         return ret;
//     }
// };
