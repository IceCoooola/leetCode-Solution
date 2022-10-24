
class UnionFindSet
{
public:
    //constructor:: vector(size_t size, const T& value)
    //set all data to -1
    UnionFindSet(int size):_ufs(size, -1){}
    //set x1 and x2 into one group
    void Union(int x1, int x2)
    {
        int root1 = FindRoot(x1);
        int root2 = FindRoot(x2);
        if(root1 != root2)
        {
            _ufs[root1] += _ufs[root2];
            _ufs[root2] = root1;
        }
    }
    int FindRoot(int x)
    {
        while(_ufs[x] > 0)
        {
            x = _ufs[x];
        }
        return x;
    }
    //does x1 and x2 in one set
    int InSet(int x1, int x2)
    {
        int root1 = FindRoot(x1);
        int root2 = FindRoot(x2);
        return root1 == root2? true : false;
    }
    //how many trees in the set
       size_t SetSize()
    {
        int x = 0;
        for(auto e : _ufs)
        {
            if (e < 0)
                ++x;
        }
            return x;
    }
    
private:
    std::vector<int> _ufs;
};

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        UnionFindSet ufs(isConnected.size());
        for(int i = 0; i < isConnected.size();i++)
        {
            for(int j = 0; j < isConnected[i].size(); j++)   
            {
                if(isConnected[i][j] == 1)
                {
                    ufs.Union(i, j);
                }
            }
        }
        return ufs.SetSize();
    }
};
