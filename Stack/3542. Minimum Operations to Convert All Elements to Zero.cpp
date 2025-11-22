class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ops = 0;
        stack<int> st;
        for(auto &num : nums){
            while(!st.empty() && st.top() > num){
                st.pop();
                ++ops;
            }
            if(num == 0 || (!st.empty() && st.top() == num))
                continue;
            st.push(num);
        }
        ops += st.size();
        return ops;
    }
};