class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        int sz = citations.size();
        //0 1 3 5 6
        //    3 2 1
        int hIdx = 0;
        for(int i = sz-1; i >=0; i--)
        {
            if(citations[i] > hIdx)
                hIdx++;
        }
        return hIdx;
    }
};
