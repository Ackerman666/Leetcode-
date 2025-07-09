class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end());
        priority_queue<int, vector<int>, greater<>> pq;

        int ans = 0, n = events.size(), last_day = 0;
        for(auto &event : events){
            last_day = max(last_day, event[1]);
        }

        for(int i=0, j=1; j<=last_day ; ++j){
            // On day j, add all events that start on or before j
            while(i < n && events[i][0] <= j){
                pq.emplace(events[i][1]);
                ++i;    
            }
            // Remove all events that have already expired (end before day j)
            while(pq.size() && pq.top() < j)
                pq.pop();

            // Choose the event with the earliest end time among available ones on day j
            if(pq.size()){
                pq.pop();
                ++ans;
            }
        }

        return ans;

    }
};
