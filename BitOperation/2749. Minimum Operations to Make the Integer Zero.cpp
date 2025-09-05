class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        int k = 1;
        while(1){
            long long remain = num1 - 1.0* num2 * k;
            // The remaining value must be at least >= k
            if(remain < k)
                return -1;
            // It takes [__builtin_popcountll(remain), remain] steps to reduce to 0
            if(k >= __builtin_popcountll(remain))
                return k;
            k++;
        }
        return -1;
    }
};
