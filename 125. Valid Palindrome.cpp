class Solution {
public:
    bool isSameLetter(char a, char b)
    {
        if( 'A' <= a && a <= 'Z')
        {
            a = a - 'A' + 'a';
        }
        if( 'A' <= b && b <= 'Z')
        {
            b = b - 'A' + 'a';
        }
        if(a == b)
            return true;
        else
            return false;
    }
    bool isLetter(char x)
    {
        return ((x >='a' && x <='z') || (x>='A' && x<='Z')|| (x>='0' && x<='9'));
    }
    
    bool isPalindrome(string s) {
        int left = 0;
        int right = s.size() - 1;
        while(left < right)
        {
            while(left < right && !isLetter(s[left]))
            {
                left ++;
            }
            while(left < right && !isLetter(s[right]))
            {
                right--;
            }
        
            if(left == right)
            {
                return true;
            }
            if(isSameLetter(s[left], s[right]))
            {
                left++;
                right--;
            }
            else
            {
                return false;
            }
        }
        return true;
    }
};
