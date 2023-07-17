class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int pivot = 0;
        int sumL = 0;
        int sumR = 0;
        for(int i = 1; i < nums.size(); i ++)
        {
            sumR += nums[i];
        }
        while(pivot < nums.size())
        {
            if(sumL == sumR)
            {
                return pivot;
            }
            else
            {
                sumL += nums[pivot];
                if(pivot != nums.size() - 1)
                    sumR -= nums[pivot + 1];
                pivot++;
            }
        }
        return -1;
    }
};
