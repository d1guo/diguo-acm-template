void solve()
{
    int n = read(), m = read();
    vector e(n + 1, vector<pii>());
    rep(i, 1, n - 1)
    {
        int u = read(), v = read(), w = read();
        e[u].pb({v, w});
        e[v].pb({u, w});
    }
    vector<pii> q;
    rep(i, 1, m)
    {
        q.pb({i, read()});
    }
    vector<bool> ans(m + 1);
    vector<bool> vis(n + 1);
    vector<bool> has(1e7 + 1);
    vector<int> v, cl;
    function<void(int, int, int)> dfs = [&](int u, int fa, int now)
    {
        v.pb(now);
        for (auto [z, w]: q)
        {
            if (now == w) ans[z] = 1;
            if (w - now > 0 && w - now <= 1e7 && has[w - now]) ans[z] = 1;
        }
        for (auto [x, y]: e[u])
        {
            if (x == fa || vis[x]) continue;
            if (now + y <= 1e7)
                dfs(x, u, now + y);
        }
    };
    vector<int> sz(n + 1);
    vector<int> st;
    vector<int> weight(n + 1);
    function<int(int, int)> getson = [&](int u, int fa)
    {
        st.pb(u);
        sz[u] = 1;
        weight[u] = 0;
        for (auto [x, y]: e[u])
        {
            if (x == fa || vis[x]) continue;
            getson(x, u);
            sz[u] += sz[x];
            weight[u] = max(weight[u], sz[x]);
        }
        if (fa == 0)
        {
            int ret = u;
            for (auto x: st)
            {
                weight[x] = max(weight[x], sz[u] - sz[x]);
                if (weight[ret] > weight[x]) ret = x;
            }
            st.clear();
            return ret;
        }
        return 0;
    };
    function<void(int)> get = [&](int u)
    {
        vis[u] = 1;
        for (auto [x, y]: e[u])
        {
            if (vis[x]) continue;
            dfs(x, 0, y);
            for (auto z: v)
            {
                has[z] = 1;
                cl.pb(z);
            }
            v.clear();
        }
        for (auto x: cl) has[x] = 0;
        cl.clear();
        for (auto [x, y]: e[u])
        {
            if (vis[x]) continue;
            get(getson(x, 0));
        }
    };
    get(getson(1, 0));
    rep(i, 1, m)
        if (ans[i]) cout << "AYE\n";
        else cout << "NAY\n";
}