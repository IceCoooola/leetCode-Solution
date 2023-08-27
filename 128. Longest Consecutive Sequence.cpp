class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        set<int> st;
        for(auto e: nums)
        {
            st.insert(e);
        }    

        auto it = st.begin();
        int maxCount = 1;
        int currentCount = 1;
        int prev = *it;
        it++;
        while(it != st.end())
        {
            if(*it == prev + 1)
            {
                currentCount++;
            }
            else
            {
                maxCount = maxCount > currentCount? maxCount : currentCount;
                currentCount = 1;
            }
            prev = *it;
            it++;
        }
        return max(maxCount, currentCount);
    }
};
