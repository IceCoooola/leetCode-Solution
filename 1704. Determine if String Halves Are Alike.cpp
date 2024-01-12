class Solution {
public:
    bool halvesAreAlike(string s) {
        int n = s.length();
        int sum = 0;
        for (int i = 0; i < n / 2; ++i) {
            char left = tolower(s[i]);
            char right = tolower(s[i+n/2]);
            if (left == 'a' || left == 'e' || left == 'u' || left == 'i' || left == 'o') {
                sum += 1;
            }
            if (right == 'a' || right == 'e' || right == 'u' || right == 'i' || right == 'o') 
            {
                sum -=1;          
            }
        }
        return sum == 0;
    }
};
