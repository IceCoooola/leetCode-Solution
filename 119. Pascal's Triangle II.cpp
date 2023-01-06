class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> even(rowIndex+1);
        even[0] = 1;
        if(rowIndex == 0)
        return even;
        vector<int> odd(rowIndex+1);
        odd[0] = 1;
        odd[1] = 1;
        if(rowIndex == 1)
            return odd;
        for(int i = 2; i < rowIndex+1; ++i)
        {
            if(i % 2 == 0)
            {
                even[0] = 1;
               for(int j = 1; j < i; j++)
               {
                    even[j] = odd[j] + odd[j-1];
               }
               even[i] = 1;
            }
            else
            {
                odd[0] = 1;
               for(int j = 1; j < i; j++)
               {
                    odd[j] = even[j] + even[j-1];
               }
               odd[i] = 1;
            }
        }
        if(rowIndex % 2 == 0)
        return even;
        else
        return odd;
    }
};
