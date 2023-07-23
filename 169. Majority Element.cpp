class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 1;
        int majority = nums[0];
        for(int i = 1; i < nums.size(); ++i)
        {
            if(nums[i] == majority)
                ++count;
            else
                --count;
            if(count == 0)
            {
                majority = nums[i];
                count = 1;
            }
        }
        return majority;
    }
};

// class Solution {
//public:
//    int majorityElement(vector<int>& nums) {
//        map<int, int> mp;
//        int sz = nums.size();
//        for(int i = 0; i < sz;i++)
 //       {
   //         if(++mp[nums[i]] > sz / 2)
     //           return nums[i]; 
       // }
     //   return 0;
   // }
//};


//class Solution {
//public:
//    int majorityElement(vector<int>& nums)
//    {
//        map<int, int> count;
//        for(int i = 0; i < nums.size(); i++)
//        {
//            count[nums[i]]++;
//            if(count[nums[i]] > nums.size() /2)
//            return nums[i];
//        }
//        return -1;
//    }
//};
