class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        
        int key = 0;
        for(int i = 0; i< nums.size(); i++)
        {
            key ^= nums[i];
        }
        int q = 0;
        while(((key >> q) & 1) != 1)
        {
            q++;
        }
        vector<int> arr1;
        vector<int> arr2;
        for(int i = 0; i< nums.size(); i++)
        {
            if(((nums[i] >> q) & 1) == 1)
            {
                arr1.push_back(nums[i]);
            }
            else
            {
                arr2.push_back(nums[i]);
            }
        }
        int ans = 0;
        vector<int> ret;
        for(int i = 0; i< arr1.size(); i++)
        {
            ans ^= arr1[i];
        }
        ret.push_back(ans);
        ans = 0;
        for(int i = 0; i< arr2.size(); i++)
        {
            ans ^= arr2[i];
        }
        ret.push_back(ans);
        return ret;        
    }
};
