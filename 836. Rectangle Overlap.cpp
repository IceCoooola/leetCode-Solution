class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        if(rec2[3] >= rec1[3] || rec2[2] >= rec1[2])
            return (rec2[0] < rec1[2] && rec2[1] < rec1[3]);
        else
            return (rec2[2] > rec1[0] && rec2[3] > rec1[1]);
    }
};
