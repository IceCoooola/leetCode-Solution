
string arr[10] = { "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };


class Solution {
public:
	void _letterCombination(string digits, int i, string s, vector<string>& ret)
	{
		if (digits[i] == '\0')
		{
			ret.push_back(s);
		}
		else
		{
			int num = digits[i] - '0';
			const string& str = arr[num];
			for (int j = 0; j < str.size(); j++)
			{
				char c = str[j];
				_letterCombination(digits, i + 1, s+c, ret);
			}
		}
	}
    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0)
        {
            return vector<string>();
        }
		vector<string> ret;
		int i = 0;
		string s;
		_letterCombination(digits, i, s, ret);
		return ret;
    }
};
