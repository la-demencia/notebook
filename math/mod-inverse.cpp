//Finding the modular inverse for every number modulo mod
const long long mod;
const int N;
int inv[N];
void findinv(){
	inv[1] = 1;
	for(int i=2; i<mod; ++i)
		inv[i] = (mod - (mod/i) * inv[mod%i] % mod) % mod;
}

//Finding the modular inverse using Exteneded Euclidean algorithm
/*
 * As coprimality is a condition needed so that an inverse exists, 
 * we have something like a*x + m*y = 1, taking mod m both sides
 *  a*x congruent 1 mod m, we conclude that
 * the modular inverse of a is x
 */
int x, y;
int g = gcdExtended(a, m, x, y);
if (g != 1) {
    cout << "No solution!";
}
else {
    x = (x % m + m) % m;
    cout << x << endl;
}
/*Note:
	if mod is prime then the modular inverse of n is n**(m-2) (Fermat's little theorem),
	to calculate it fast we can use fast pow
*/ 
//Taken from https://cp-algorithms.com/algebra/module-inverse.html
