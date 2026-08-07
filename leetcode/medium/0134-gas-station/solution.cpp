class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        vector<int>netgain(gas.size());
        int Overall_fuel = 0;
        for(int i=0;i<gas.size();i++)
        {
        netgain[i] = gas[i] - cost[i];
        Overall_fuel += netgain[i];
        }
        if(Overall_fuel < 0) return -1;

        int start = 0;
        int current_fuel = 0;
        for(int i = 0;i<gas.size();i++)
        {
            if(current_fuel < 0)
            {
            start = i;
            current_fuel = 0;
            }
            current_fuel += netgain[i];
        }
        return start;
    }
};