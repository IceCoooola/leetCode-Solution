class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        unordered_map<int, int> um;
        for(int i = 0; i < nums.size(); i++)
        {
            ++um[nums[i]];
        }
        for(auto e: um)
        {
            if(e.second == nums.size()/2)
                return e.first;
        }
        return -1;
    }
};
