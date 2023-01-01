class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int last = digits.size() - 1;
        digits[last] += 1;
        int carry = 0;
        while (digits[last] >= 10)
        {
            carry = digits[last] / 10;
            if(last - 1 < 0)
            {
                digits[last] %= 10;
                digits.insert(digits.begin(), carry);
            }
            else
            {
                digits[last] %= 10;
                digits[last - 1] += carry;
                last -= 1;
            }
        }
        return digits;
    }
};
