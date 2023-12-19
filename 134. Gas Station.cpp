class Solution {
public:
    // [-2, -2, -2, 3, 3]
    // 
    // [3, -1, -1, 3, -4]
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        vector<int> gas_and_cost(n);
        int ret = -1;
        int sum = 0;
        for (int i = 0; i < n; i++) {
            gas_and_cost[i] = gas[i] - cost[i];
            sum += gas_and_cost[i];
        }
        if (sum < 0) {
            return -1;
        }
        sum = 0;
        for (int i = 0; i < n; i++) {
            if (sum == 0 && gas_and_cost[i] >= 0) {
                ret = i;
            }
            sum += gas_and_cost[i];
            if (sum < 0) {
                sum = 0;
            }
        }
        return ret;
    }
};
