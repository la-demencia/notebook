ll ans = 1;

for(int j = 0; primes[j]*primes[j] <= n; ++j) {
	if(n%primes[j] == 0){
	  ll cnt = 0;
	  while(n%primes[j] == 0) n/=primes[j], cnt++;
	  ans*= ((ll)pow((double)primes[j], cnt + 1.0) - 1) / (primes[j]-1);
	}
}

if(n > 1) {
	ans*= ((ll)pow((double)n, 2.0) - 1) / (n-1);
}
