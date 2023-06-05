class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        for(int i = 0; i < image.size(); i++)
        {
            int left = 0;
            int right = image.size() - 1;
            while(right > left)
            {
                swap(image[i][right], image[i][left]);
                ++left;
                --right;
            }
            for(int j = 0; j < image[i].size(); j++)
            {
                image[i][j] ^= 1;
            }
        }
        return image;
    }
};
