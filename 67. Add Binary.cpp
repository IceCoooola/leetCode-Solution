class Solution {
public:
    string addBinary(string a, string b) {
        int m = a.length() - 1;
        int n = b.length() - 1;
        int carry = 0;
        string ret = "";
        while (m >= 0 && n >= 0) {
            int sum = (a[m--] - '0') + (b[n--] - '0') + carry;
            if (sum >= 2) {
                carry = 1;
                sum -= 2;
            } else {
                carry = 0;
            }
            ret = to_string(sum) + ret;
            //cout << ret << endl;
        }
        while (m >= 0) {
            int sum = (a[m--] - '0') + carry;
            if (sum >= 2) {carry = 1;
            sum -= 2;} else {carry = 0;}
            ret = to_string(sum) + ret;
        }
        while (n >= 0) {
            int sum = (b[n--] - '0') + carry;
            if (sum >= 2) {carry = 1;
            sum -= 2;} else {carry = 0;}
            ret = to_string(sum) + ret;
        }
        while (carry) {
            ret = '1' + ret;
            carry -= 1;
        }

        return ret;
    }
};
