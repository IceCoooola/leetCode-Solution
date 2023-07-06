class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int max = candies[0];
        int n = candies.size();
        vector<bool> ret;
        for(int i = 1; i < n; i++)
        {
            if(candies[i] > max)
                max = candies[i];
        }
        for(int i = 0; i < n; i++)
        {
            if(candies[i] + extraCandies >= max)
                ret.push_back(true);
                else
                ret.push_back(false);
        }
        return ret;
    }
};
