class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ret;
        int sz = nums.size();
        if(sz == 0)
            return ret;
        if(sz == 1){           
            ret.push_back(to_string(nums[0]));
            return ret;
            }
        int left = nums[0];
        int idx = 0;
        for(int i = 1; i < nums.size(); i++)
        {
            cout<<"left: "<<left<<endl;
            cout<<"idx: "<<idx<<endl;
            cout<<nums[i]<<endl;
            if(nums[i] == (left + 1))
            {
                left++;
            }
            else
            {
                if(left == nums[idx]){
                    ret.push_back(to_string(left));
                    left = nums[i];
                    idx = i;
                    }
                else
                {
                string tmp = (to_string(nums[idx])+"->" + to_string(left));
                cout<<tmp<<endl;
                ret.push_back(tmp);
                idx = i;
                left = nums[i];
                }
            }
        }
        if(left == nums[idx])
            ret.push_back(to_string(left));
        else
        {
            string tmp = to_string(nums[idx])+"->" + to_string(left);
            ret.push_back(tmp);
        }
        return ret;
    }
};
