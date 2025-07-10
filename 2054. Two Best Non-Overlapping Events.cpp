class Solution {
public:
    // Sort the events in ascending order of start time.
    // When selecting events[i], use binary search to find the earliest non-overlapping event.
    // Then use a precomputed array to find the maximum value among all events after that one.
    int maxTwoEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end());

        vector<int> start;
        for(auto &event : events)
            start.push_back(event[0]);

        vector<int> max_value(events.size()+1, 0);
        for(int i=max_value.size()-2 ; i>=0 ; --i){
            max_value[i] = max(events[i][2], max_value[i+1]);
        }

        int ans = INT_MIN;
        for(int i=0 ; i<events.size() ; ++i){
            ans = max(ans, events[i][2]);
            int next = upper_bound(start.begin(), start.end(), events[i][1]) - start.begin();
            if(next != start.size()){
                ans = max(ans, events[i][2] +  max_value[next]);
            }
        }
        return ans;
    }
};
