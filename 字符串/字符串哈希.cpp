bool isprime(int n)
{
    if (n <= 1) return 0;
    for (int i = 2; i * i <= n; ++i)
        if (n % i == 0) return 0;
    return 1;
}
int findPrime(int n)
{
    while (!isprime(n)) ++n;
    return n;
}
void solve()
{
    string s; cin >> s;
	int n = s.length();
    s = '?' + s;
    vector<ll> ha(n + 1), rha(n + 2), p(n + 1);
    mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
    ll MOD = findPrime(rng() % 900000000 + 100000000);
    rep(i, 1, n) ha[i] = (10LL * ha[i - 1] + s[i] - 'a') % MOD;
    per(i, n, 1) rha[i] = (10LL * rha[i + 1] + s[i] - 'a') % MOD;
    p[0] = 1;
    rep(i, 1, n) p[i] = 10LL * p[i - 1] % MOD;
    auto getha = [&](int l, int r) -> ull
    {
        if (l > r) return 0;
        return (ha[r] - ((ha[l - 1] * p[r - l + 1]) % MOD) + MOD) % MOD;
    };
    auto getrha = [&](int l, int r) -> ull
    {
        return (rha[l] - ((rha[r + 1] * p[r - l + 1]) % MOD) + MOD) % MOD;
    };
}