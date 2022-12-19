class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0)
            return false;
        vector<int> arr;
        while(x)
        {
            arr.push_back(x%10);
            x/=10;
        }
        int left = 0;
        int right = arr.size() - 1;
        while(right > left && arr[right] == arr[left])
        {
            ++left;
            --right;
        }
        if(right <=left)
        return true;
        else
        return false;
    }
};
