
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
    bool equationsPossible(vector<string>& equations) {
        UnionFindSet ufs(27);
        for(auto e : equations)
        {
            if(e[1] == '=')
            {
                ufs.Union(e[0] - 'a' + 1, e[3] - 'a' + 1);
            }
        }
        for(auto e : equations)
        {
            if(e[1] == '!')
            {
                if(ufs.InSet(e[0] - 'a' + 1, e[3] - 'a' + 1))
                return false;
            }
        }
        return true;
    }
};
