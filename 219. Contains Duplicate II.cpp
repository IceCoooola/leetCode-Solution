class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int, vector<int>> mp;
        int sz = nums.size();
        for(int i = 0; i < sz; i++)
        {
            mp[nums[i]].push_back(i);
        }
        for(auto e: mp)
        {
            for(int i = 1; i < e.second.size(); i++)
            {
                if(e.second[i] - e.second[i-1] <= k)
                    return true;
            }
        }
        return false;
    }
};
