class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> mp;
        unordered_map<int, int> in_degree;
        for (int i = 0; i < numCourses; ++i) {
            in_degree[i] = 0;
        }
        for (auto prerequisite: prerequisites) {
            if (mp.find(prerequisite[1]) == mp.end()) {
                mp[prerequisite[1]] = vector<int>();
            }
            mp[prerequisite[1]].push_back(prerequisite[0]);
            in_degree[prerequisite[0]] += 1;
        }
        stack<int> st;
        auto it = in_degree.begin();
        while  (it != in_degree.end()) {
            if (it->second == 0) {
                st.push(it->first);
            }
            it++;
        }
        while (!st.empty()) {
            int top = st.top();
            st.pop();
            for (auto e: mp[top]) {
                in_degree[e]--;
                if (in_degree[e] == 0) {
                    st.push(e);
                }
            }
        }
        it = in_degree.begin();
        while (it != in_degree.end()) {
            if (it->second != 0) return false;
            it++;
        }
        return true;
    }
};
