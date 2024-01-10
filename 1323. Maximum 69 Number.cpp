class Solution {
public:
    int maximum69Number (int num) {
        bool tf = false;
        return helper(num, tf);
    }

    int helper(int num, bool& changed){
        if (num < 10) {
            if (num == 6) {
                changed = true;
            }
            return 9;
        }
        int last = num % 10;
        int first = helper(num/10, changed);
        if (changed) return first * 10 + last;
        else {
            if (last == 6) {
                changed = true;
            }
            return first * 10 + 9;
        }
    }
};
