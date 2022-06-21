class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        //���������̷s���X�{��m
        int record[100001]={0};
        for(int i=0 ; i<100001 ; i++)
            record[i]=-1;

        int ans=0 , temp=0 , nums_len = nums.size();
        int sub_array_front = 0;
        int DP[100001]={0};

        //���ثe���
        DP[0] = nums[0];
        for(int i=1 ; i<nums_len ; i++){
            DP[i] = DP[i-1] + nums[i];
        }

        for(int i=0 ; i<nums_len ; i++){
            int cur_num = nums[i];
            if(record[cur_num] < sub_array_front){
                temp+=cur_num;
            }
            else{
                temp = DP[i] - DP[ record[cur_num] ];
                sub_array_front = record[cur_num] + 1;
            }
            ans = max(ans , temp);
            record[cur_num] = i;
        }
        return(ans);
    }
};
