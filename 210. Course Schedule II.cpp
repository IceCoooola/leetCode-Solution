class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // the map indicate that each prerequisite course pointing to 
        // ex: 61a -> cs188, cs189
        map<int, vector<int>> mp;

        // the in_degree indicate the prerequisites for each course, if 0, 
        // means that course does not have prereq
        map<int, int> in_degree;
        for (int i = 0; i < numCourses; ++i) in_degree[i] = 0;

        // a queue that indicate the 0s in degree node.
        stack<int> q;

        for (int i = 0; i < prerequisites.size(); ++i) {
            if (mp.find(prerequisites[i][1]) == mp.end()) {
                mp[prerequisites[i][1]] = vector<int>();
            }
            mp[prerequisites[i][1]].push_back(prerequisites[i][0]);
            in_degree[prerequisites[i][0]] += 1;
        }
        auto it = in_degree.begin();
        while (it != in_degree.end()) {
            if (it->second == 0){ 
                q.push(it->first);            
                it->second -= 1;
            }
            it++;
        }

        vector<int> ret;
        for (auto it: in_degree){
            cout << it.first <<" degree: "<<it.second<<endl;
            
        }

        while (!q.empty()) {
            int course = q.top();
            q.pop();
            ret.push_back(course);
            for (auto e: mp[course]) {
                in_degree[e] -= 1;
            }
            it = in_degree.begin();
            while (it != in_degree.end()) {
            if (it->second == 0){ 
                q.push(it->first);            
                it->second -= 1;
            }
            it++;
            }
            }
        if (ret.size() == numCourses){
            return ret;
        }
        return vector<int>();
    }
};
