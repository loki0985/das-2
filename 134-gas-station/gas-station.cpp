class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalGas = 0, totalCost = 0;
        int tank = 0, start = 0;

        for (int i = 0; i < gas.size(); i++) {
            totalGas += gas[i];
            totalCost += cost[i];
            tank += gas[i] - cost[i];

            // Cannot reach next station, choose next station as start
            if (tank < 0) {
                start = i + 1;
                tank = 0;
            }
        }

        return (totalGas >= totalCost) ? start : -1;
    }
};