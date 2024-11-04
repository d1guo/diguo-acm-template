int n = read();
vector e(n + 1, vector<int>());
rep(i, 1, n - 1)
{
    int u = read(), v = read();
    e[u].pb(v), e[v].pb(u);
}
vector<int> f(n + 1);
int d = 0;
function<void(int, int)> dfs = [&](int u, int fa) -> void
{
    for (auto x: e[u])
    {
        if (x == fa) continue;
        dfs(x, u);
        if (d < f[u] + f[x] + 1) d = f[u] + f[x] + 1;
        if (f[u] < f[x] + 1) f[u] = f[x] + 1;
    }
};
dfs(1, 0);
// return d;