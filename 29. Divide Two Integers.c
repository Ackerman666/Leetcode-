int divide(int dividend, int divisor) {

    long long dividend_ll = dividend, divisor_ll = divisor;
    int trans = ((dividend_ll < 0) ^ (divisor_ll < 0)) ? -1 : 1;
    dividend_ll = labs(dividend_ll), divisor_ll = labs(divisor_ll);

    long long ans = 0;

    while(dividend_ll >= divisor_ll){
        // At least one divisor can be subtracted
        long long t = 1, temp = divisor_ll;

        // Find out how many divisors can be subtracted at once
        while(dividend_ll > (temp << 1)){
            t <<= 1;
            temp <<= 1;
        }

        // Subtract t*divisor from dividend
        ans += t;
        dividend_ll -= temp;

    }

    ans *= trans;

    if(ans > INT_MAX)
        ans = INT_MAX;
    
    else if(ans < INT_MIN)
        ans = INT_MIN;

    return ans;

}
