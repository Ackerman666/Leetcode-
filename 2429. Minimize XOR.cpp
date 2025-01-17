class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int set_bit1 = __builtin_popcount(num1), set_bit2 = __builtin_popcount(num2);
        int ans = num1;

        if(set_bit1 > set_bit2){
            int diff = set_bit1 - set_bit2;
            for(int i=0 ; i<32, diff > 0 ; i++){
                if(num1 & (1 << i)){
                    ans ^= (1 << i);
                    --diff;
                }
            }
        }

        if(set_bit1 < set_bit2){
            int diff = set_bit2 - set_bit1;
            for(int i=0 ; i<32, diff > 0 ; i++){
                if(!(num1 & (1 << i))){
                    ans ^= (1 << i);
                    --diff;
                }
            }
        }
        return ans;
    }
};
