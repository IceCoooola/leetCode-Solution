class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int sz = arr.size();
        vector<int> rising(sz, 1), decreasing(sz, 1);
        int ret = 1;
        for(int i = 1; i < sz; i++)
        {
            if(arr[i] > arr[i-1]) rising[i] = decreasing[i-1] + 1;
            else if(arr[i] < arr[i-1]) decreasing[i] = rising[i-1] + 1;
            ret = max(ret, max(rising[i], decreasing[i]));
        }
        return ret;
    }
};
