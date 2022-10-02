class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> mp;
        for(auto e: nums)
        {
            mp[e]++;
        }
        multimap<int, int, greater<int>> sortMp;
        auto it = mp.begin();
        while(it != mp.end())
        {
            sortMp.insert(make_pair(it->second, it->first));
            ++it;
        }
        
        vector<int> ret;
        auto rit = sortMp.begin();
        for(int i = 0; i < k; i++)
        {
        ret.push_back(rit->second);
        ++rit;            
        }
        return ret;
    }
};
