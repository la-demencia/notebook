ull fibonacci(ull n){
    if(n == 0) return 0;
    if(n == 1) return 1;
    Matrix<ull> I(false, 1, 2), M(false, 2, 2); 
    I.m = {{0, 1}};
    M.m = {{0, 1}, {1, 1}};
    M = fpow(M, n - 1);
    return (I * M).m[0][1];
}
