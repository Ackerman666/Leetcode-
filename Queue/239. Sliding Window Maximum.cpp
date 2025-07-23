class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        // A deque to store elements in decreasing order.
        // The front of the deque always contains the maximum element of the current window.
        deque<int>  q;
        
        for(int i=0 ; i<k ; ++i){
            while(q.size() && nums[i]>q.back())
                q.pop_back();
            q.push_back(nums[i]);
        }
        ans.push_back(q.front());
        
        for(int i=k ; i<nums.size() ; ++i){
            if(q.front() == nums[i-k])
                q.pop_front();
            // Maintain the decreasing order in the deque.
            while(q.size() && nums[i]>q.back())
                q.pop_back();
            q.push_back(nums[i]);
            ans.push_back(q.front());
        }
        return ans;
    }
};