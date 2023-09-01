class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ret;
        unordered_map<string, vector<string>> mp;
        for(auto e: strs)
        {
            string tmp = e;
            sort(e.begin(), e.end());
            mp[e].push_back(tmp);
        }
        for(auto e: mp)
        {
            vector<string> tmp;
            for(auto str : e.second)
            {
                tmp.push_back(str);
            }
            ret.push_back(tmp);
        }
        return ret;
    }
};
