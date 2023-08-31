class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int sz = numbers.size();
        vector<int> ret(2);
        for(int i = 0; i < sz; i++)
        {
            int target2 = target - numbers[i];
            int right = sz - 1;
            int left = i + 1;
            while(right >= left)
            {
                int mid = (right + left) / 2;
                if(numbers[mid] == target2)
                {
                    ret[0] = i+1;
                    ret[1] = mid+1;
                    return ret;
                }
                else if(numbers[mid] > target2)
                {
                    right = mid - 1;
                }
                else{
                    left = mid + 1;
                }
            }
        }
        return ret;
    }
};
