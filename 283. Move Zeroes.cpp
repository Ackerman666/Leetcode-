class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int vc_len=nums.size() , qindex=0;
        int non_zero_num;
        int queue[100001];
        for(int i=0;i<vc_len;i++){
            int curr=nums[i];
            if(curr){
                queue[qindex++]=curr;
            }
        }
        for(int i=0;i<qindex;i++){
            nums[i]=queue[i];
        }
        for(int i=qindex;i<vc_len;i++)
            nums[i]=0;
    }
};
