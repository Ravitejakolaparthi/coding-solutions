class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<int>pq1;
        priority_queue<int>pq2;
        for(int i =0;i<k;i++)
        {
            pq1.push(nums[i]);
        }
        vector<int>v;
        v.push_back(pq1.top());
        for(int i=k;i<nums.size();i++)
        {
            pq2.push(nums[i-k]);
            // if()
            pq1.push(nums[i]);
            while(!pq1.empty() && !pq2.empty() && pq1.top() == pq2.top())
            {
                pq1.pop();
                pq2.pop();
            }
            v.push_back(pq1.top());
        }
        // 1 3 -1 -3 5 3 6 7
            return v;
    }
};