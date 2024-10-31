#define INI_ARRAY(nums, size, val)   \
        for(int i=0 ; i<size ; ++i){ \
            nums[i] = val;           \
        }

#define MIN(a, b)  (a) < (b) ? (a) : (b)
#define MAX(a, b)  (a) > (b) ? (a) : (b)


int minimumMountainRemovals(int* nums, int numsSize) {
    
    int LLIS[1001], RLIS[1001], ans = INT_MAX;
    INI_ARRAY(LLIS, numsSize, 1);
    INI_ARRAY(RLIS, numsSize, 1);

    for(int i = 1 ; i < numsSize ; ++i){
        for(int j = i-1 ; j>=0 ; --j){
            if(nums[i] > nums[j]){
                LLIS[i] = MAX(LLIS[i], LLIS[j] + 1);
            }
        }
    }

    for(int i = numsSize-1 ; i >= 0 ; --i){
        for(int j = i+1 ; j < numsSize ; ++j){
            if(nums[i] > nums[j]){
                RLIS[i] = MAX(RLIS[i], RLIS[j] + 1);
            }
        }
    }

    for(int i = 0 ; i < numsSize ; ++i){
        if(LLIS[i] > 1 && RLIS[i] > 1)
            ans = MIN(ans, (numsSize - (LLIS[i] + RLIS[i] - 1)));
    }

    return ans;


}
