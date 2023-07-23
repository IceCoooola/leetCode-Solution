class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> ret;
        for(int i = 0; i < nums.size(); i++)
        {
            int index = abs(nums[i]) - 1;
            if(nums[index] > 0)
                nums[index] = -1 * nums[index];
        }
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] > 0)
                ret.push_back(i+1);
        }
        return ret;
    }
};

//class Solution {
//public:
//    vector<int> findDisappearedNumbers(vector<int>& nums) {
//        set<int> st;
  //      vector<int> ret;
    //    int n = nums.size();
      //  for(int i = 0; i < n; i++)
        //{
          //  st.insert(nums[i]);
        //}
   //     auto it = st.begin();
   //     for(int i = 1; i <= n; i++)
    //    {
    //        if(*it != i)
      //      {
      //          ret.push_back(i);
      //      }
       //     else
           // {
          //      ++it;
        //    }
      //  }
    //    return ret;
  //  }
//};
