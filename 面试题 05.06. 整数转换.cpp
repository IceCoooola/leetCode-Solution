class Solution {
public:
    int convertInteger(int A, int B) {
            int t = A ^ B;
            int sum = 0;
            for(int i = 0; i < 32; i++)
            {
                if(t >> i & 1 == 1)
                {
                    sum += 1;
                }
            }
            return sum;

    }
};
