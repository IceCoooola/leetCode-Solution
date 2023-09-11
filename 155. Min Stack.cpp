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


// class MinStack {
// public:
//     MinStack() {
//     }
    
//     void push(int val) {
//         st.insert(val);
//         data.push(val);
//     }
    
//     void pop() {

//         st.erase(st.find(data.top()));
//         data.pop();
//     }
    
//     int top() {
//         return data.top();
//     }
    
//     int getMin() {
//         return *st.begin();
//     }
//     stack<int> data;
//     multiset<int> st;
// };

// /**
//  * Your MinStack object will be instantiated and called as such:
//  * MinStack* obj = new MinStack();
//  * obj->push(val);
//  * obj->pop();
//  * int param_3 = obj->top();
//  * int param_4 = obj->getMin();
//  */
