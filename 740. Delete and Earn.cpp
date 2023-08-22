class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int arr[10001] = {0};
        for(auto e: nums)
        {
            arr[e] += e;
        }
        vector<int> choose(10001);
        vector<int> NoChoose(10001);
        for(int i = 1; i < 10001; i++)
        {
            choose[i] = NoChoose[i-1] + arr[i];
            NoChoose[i] = max(NoChoose[i-1], choose[i-1]);
        }
        return max(NoChoose[10000], choose[10000]);
    }
};
