class MinStack {
public:
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
        if(minVal.empty())
        {
            minVal.push_back(val);
        }
        else
        {
            if(st.top() <= minVal[minVal.size()-1])
            {
                minVal.push_back(val);
            }
        }
    }
    
    void pop() {
        if(minVal[minVal.size()-1] == st.top())
        {
            minVal.pop_back();
            st.pop();
        }
        else
        {
            st.pop();
        }
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minVal[minVal.size()-1];
    }
private:    
    stack<int> st;
    vector<int> minVal;
};
