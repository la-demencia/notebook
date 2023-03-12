//To solve the ecuaton of the form a*x + b*y = gcd(a, b);
//Complexity logarithmic
int gcdExtended(int a, int b, int& x, int& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int g = gcdExtended(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return g;
}

pair<int,int> diophantine(int a, int b, int c){
  int x,y;
  int gcd = gcdExtended(a, b, x, y);
  assert(c%g==0); // There's no solution
  x *= c/g;
  y *= c/g;
  if( a < 0 ) x=-x;
  if( b < 0 ) y=-y;
  return {x,y};
}
