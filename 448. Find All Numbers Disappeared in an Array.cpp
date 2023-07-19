class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        set<int> st;
        vector<int> ret;
        int n = nums.size();
        for(int i = 0; i < n; i++)
        {
            st.insert(nums[i]);
        }
        auto it = st.begin();
        for(int i = 1; i <= n; i++)
        {
            if(*it != i)
            {
                ret.push_back(i);
            }
            else
            {
                ++it;
            }
        }
        return ret;
    }
};
