class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        
        int res[51] = {0}, pre_loc[51] = {0}, k_appear[100001] = {0}, max_res = 0; // res[num]: The maximum number of times the current num can be accumulated
        int tot_k = 0;  // tot_k -> The guaranteed minimum answer

        for(int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            if(num == k)
                ++tot_k;
            k_appear[i] = tot_k;
            if(num != k){
                // Calculate the total occurrences of k from the previous position of nums[i] to this position
                int k_count = k_appear[i] - k_appear[pre_loc[num]];
                // If k_count >= previously accumulated count => restart from the beginning
                if(k_count >= res[num])
                    res[num] = 1;
                else
                    res[num] = res[num] - k_count + 1;
                pre_loc[num] = i;
            }
            max_res = max(max_res, res[num]);
            k_appear[i] = tot_k;      
        }
        return max_res + tot_k;
    }
};
