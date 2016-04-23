typedef long long LL;
inline LL mul_mod(LL a, LL b, LL mod){
	return a * b % mod;
}
LL pow_mod(LL a, LL b, LL mod){
	if(b == 0) return 1;
	LL res = pow_mod(mul_mod(a, a, mod), b / 2, mod);
	if(b & 1) res = mul_mod(res, a, mod);
	return res;
}
//����
LL len(LL n){
	LL res = 0;
	while(n > 0){
		n /= 10;
		res++;
	}
	return res;
}


//����len��a�Ƃ�������d��z���鋐�吔��mod�Ŋ������]������߂Ă���B�ċA�E�}�߂��B�񕪗ݏ�@�H
LL calc(LL a, LL d, LL mod, LL len){
	if(d == 0) return 0;
	if(d == 1) return a;
	LL c = calc(a, d / 2, mod, len);
	LL c2 = c * pow_mod(10, (d/2) * len, mod) % mod;
	LL res = (c + c2) % mod;
	if(d % 2 == 1){
		res = res * pow_mod(10, len, mod) % mod;
		res = (res + a) % mod;
	}
	return res;
}