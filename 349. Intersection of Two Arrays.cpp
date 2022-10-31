class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> u1;
        unordered_set<int> u2;
        vector<int> ret;
        for(int i = 0; i < nums1.size(); i++)
        {
            u1.insert(nums1[i]);
        }
        for(int i = 0; i < nums2.size(); i++)
        {
            u2.insert(nums2[i]);
        }
        for(auto e: u1)
        {
            if(u2.find(e) != u2.end())
                ret.push_back(e);
        }
        return ret;
    }
};
