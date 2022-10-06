class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string, int> count;
        for(int i = 0; i < words.size(); i++)
        {
            count[words[i]]++;
        }
        multimap<int, string, greater<int>> topK;
        auto it = count.begin();
        while(it != count.end())
        {
            topK.insert(make_pair(it->second, it->first));
            it++;
        }
        vector<string> ret;
        auto it2 = topK.begin();
        while(k--)
        {
            ret.push_back(it2->second);
            it2++;
        }
        return ret;
    }
};
