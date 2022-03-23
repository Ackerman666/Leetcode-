class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        quicksort(nums , 0 , nums.size()-1);
        return(nums);
    }

    void quicksort(vector<int>& nums , int left , int right){
        if(left>=right)
            return;
        int pivot_index=(left+right)/2 , pivot = nums[pivot_index] , i=left , j=right;
        while(i!=j){
            while(nums[j] >= pivot && i!=j)
                j--;
            while(nums[i] <= pivot && i!=j)
                i++;
            if(i!=j)
                swap(nums[i] , nums[j]);
        }
        int nextleft , nextright;
        if(nums[i] > pivot){                              //i=j�����ަ�m���Ȥ��T�w�O�_�p��j��pivot �G�n���B�~�P�_
            if(i <= pivot_index){                         //�bpivot����
                swap(nums[i] , nums[pivot_index]);
                nextleft = i+1;
                nextright = i-1;
            }
            else{                                        //�bpivot�k��
                swap(nums[i-1] , nums[pivot_index]);
                nextleft = i;
                nextright = i-2;
            }
        }
        else{
            if(i >= pivot_index){
                swap(nums[i] , nums[pivot_index]);
                nextleft = i+1;
                nextright = i-1;
            }
            else{
                swap(nums[i+1] , nums[pivot_index]);
                nextleft = i+2;
                nextright = i;
            }
        }
        quicksort(nums , left , nextright);
        quicksort(nums , nextleft , right);
    }
};
