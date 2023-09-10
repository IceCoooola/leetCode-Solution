class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0)
            return false;
        long long rev = 0;
        int tmp = x;
        while(tmp)
        {
            rev = ((rev * 10) + (tmp % 10));
            tmp /= 10;
        }
        if(rev == x)
            return true;
        else
            return false;
        
    }
};

// class Solution {
// public:
//     bool isPalindrome(int x) {
//         if(x < 0)
//             return false;
//         vector<int> arr;
//         while(x)
//         {
//             arr.push_back(x%10);
//             x/=10;
//         }
//         int left = 0;
//         int right = arr.size() - 1;
//         while(right > left && arr[right] == arr[left])
//         {
//             ++left;
//             --right;
//         }
//         if(right <=left)
//         return true;
//         else
//         return false;
//     }
// };
