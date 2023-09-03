class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ret = 1;
        int sz = s.length();
        if(sz == 0)
            return 0;
        int j = 0;
        for(int i = 1; i < sz; i++)
        {
            int tmp = j;
            while(tmp < i)
            {
                if(s[tmp] == s[i])
                {
                    j = tmp + 1;
                    break;
                }
                tmp++;
            }
            ret = max(ret, i - j + 1);
        }
        return ret;
    }
};
// class Solution {
// public:
//     int lengthOfLongestSubstring(string s) {
//         if(s.size() == 0)
//             return 0;
//         queue<char> q;
//         q.push(s[0]);
//         int maxLength = 1;
//         map<char, bool> dict;
//         for(int i = 0; i < s.size(); i++)
//         {
//             dict[s[i]] = false;
//         }
//         dict[s[0]] = true;
//         for(int i = 1; i < s.size(); i++)
//         {
//             if(dict[s[i]] == false)
//             {
//                 q.push(s[i]);
//                 dict[s[i]] = true;
//                 if(maxLength < q.size())
//                 {
//                     maxLength = q.size();
//                 }
//             }
//             else
//             { 
//                 if(maxLength < q.size())
//                 {
//                     maxLength = q.size();
//                 }
//                 if(q.front() == s[i])
//                 {
//                     q.pop();
//                     q.push(s[i]);
//                 }
//                 else
//                 {
//                 while(!q.empty()&&q.front() != s[i])
//                 {
//                     dict[q.front()] = false;
//                     q.pop();
//                 }
//                 q.pop();
//                 q.push(s[i]);
//                 }
//             }
//         }
//         return maxLength;
//     }
// };
