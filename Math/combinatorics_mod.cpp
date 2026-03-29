#define P 1000000007

long long fastpow(int x, int pow){
	long long val = 1, base = x;
	while(pow){
		if(pow & 1)
			val = (val * base) % P;
		base = (base * base) % P;
		pow >>= 1;
	}
	return val;
}

long long C(int n, int k){
	long long val = 1;
	for(int i=k+1 ; i<=n ; ++i)
		val = (val * i) % P;
	for(int i=1 ; i<=(n-k) ; ++i){
		long long invert = fastpow(i, P-2);
		val = (val * invert) % P;
	}
	return val;
}