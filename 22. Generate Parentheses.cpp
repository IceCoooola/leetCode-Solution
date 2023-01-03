class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ret;
        _generate(n,0,"", ret);
        return ret;
    }

    void _generate(int left, int right, string str, vector<string>& ret)
    {
        if(right == 0 && left == 0)
        {
          ret.push_back(str);
          return;
        }
        if(left > 0)
        {
        _generate(left - 1, right + 1, str + "(", ret);
        }
        if(right > 0)
        {
            _generate(left, right - 1, str+")", ret);
        }
    }
};
