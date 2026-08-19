class Solution {
public:
    bool check(int limit, int tot_days, vector<int>& weights) {
        int day = 1;
        int weight = 0;
        for (int i = 0; i < weights.size(); i++) {
            if (weight + weights[i]  <= limit) {
                weight += weights[i];
            } else {
                day++;
                weight = weights[i];
                if (day > tot_days)
                    return false;
            }
        }
        return true;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        // sort(weights.begin(),weights.end());
        int low = *max_element(weights.begin(), weights.end()); // Becasue if you take one we must split products wich is not efficent so we take some other low so among all we take max so it can allow products one at a time
        int high = 0;
        for(int i=0;i<weights.size();i++){
            high += weights[i];
        }
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (check(mid, days, weights)) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};