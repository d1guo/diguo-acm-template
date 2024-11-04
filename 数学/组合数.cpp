const int factN = ;
const int MOD = ;
mint fact[factN + 1], invfact[factN + 1], inv[factN + 1];
void factinit()
{
    mint::set_mod(MOD);
    inv[1] = 1;
    rep(i, 2, factN) inv[i] = mint(MOD - MOD / i) * inv[MOD % i];
    fact[0] = invfact[0] = 1;
    rep(i, 1, factN) fact[i] = fact[i - 1] * i;
    invfact[factN - 1] = fact[factN - 1].inv();
    per(i, factN - 2, 0) invfact[i] = invfact[i + 1] * (i + 1);  
}

inline mint C(int a, int b)
{
    if (a < 0 || b < 0 || a < b) return 0;
    return fact[a] * invfact[b] * invfact[a - b];
}