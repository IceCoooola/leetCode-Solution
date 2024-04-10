class MedianFinder {
public:

    priority_queue<int, vector<int>, greater<int>> right_half = priority_queue<int, vector<int>,std::greater<int>>();
    priority_queue<int> left_half = priority_queue<int>();
    MedianFinder() {
    }
    
    void addNum(int num) {
        if (left_half.size() < right_half.size()) {
            right_half.push(num);
            int top = right_half.top();
            right_half.pop();
            left_half.push(top);
        } else {
            left_half.push(num);
            int top = left_half.top();
            left_half.pop();
            right_half.push(top);
        }
    }
    
    double findMedian() {
        if (left_half.size() < right_half.size()) {
            return right_half.top();
        } else {
            return float(right_half.top() + left_half.top()) / 2;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
