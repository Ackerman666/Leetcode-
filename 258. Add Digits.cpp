class Solution {
public:
    int addDigits(int num) {
        while(1){
            if(num/10==0)
                break;
            else{
                int temp = 0;
                while(num){
                    temp += num%10;
                    num = num/10;
                }
                num = temp;
            }
        }
        return(num);
    }
};
