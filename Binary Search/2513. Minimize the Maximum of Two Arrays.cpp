class Solution {
public:



    int minimizeSet(int divisor1, int divisor2, int uniqueCnt1, int uniqueCnt2) {
        long long l = 1, r = 1e18, ans;
        while(l < r){

            long long mid = (l+r)/2;
            long long c1 = mid - mid/divisor1, c2 = mid - mid/divisor2;
            long long lcmv = lcm((long long)divisor1, (long long)divisor2);
            long long tot_c = mid - mid/lcmv;
            if(c1 >= uniqueCnt1 && c2 >= uniqueCnt2 && tot_c >= (uniqueCnt1+uniqueCnt2)){
                ans = mid;
                r = mid;
            }
            else
                l = mid+1;
        }
        return ans;
    }
};