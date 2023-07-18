class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int product = 1;
        int count = 0;
        vector<int> ret;
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] == 0)
            {
                count++;
                if(count >= 2)
                {
                    ret.assign(nums.size(),0);
                    return ret;
                }
            }
            else
            {
                product *= nums[i];
            }
        }
        if(count == 1)
        {
            for(int i = 0; i < nums.size(); i++)
            {
                if(nums[i] != 0)
                {
                    ret.push_back(0);
                }
                else
                {
                    ret.push_back(product);
                }
            }
        }
        else
        {
            for(int i = 0; i < nums.size(); i++)
            {
                ret.push_back(product / nums[i]);
            }
        }
        return ret;
    }
};
