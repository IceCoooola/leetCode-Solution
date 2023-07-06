class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        unordered_map<int, int> mp;
        vector<int> ret;
        for(int i = 0; i < nums.size(); i++)
        {
            mp[nums[i]]++;
            if(mp[nums[i]] == 2)
                ret.push_back(nums[i]);
        }
        for(int i = 0; i < nums.size(); i++)
        {
            mp[i + 1]++;
            if(mp[i+1] == 1)
                ret.push_back(i+1);
        }
        return ret;
    }
};
