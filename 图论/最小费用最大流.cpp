struct edge
{
    int v, rev;
    ll c, w, flow;
    bool fwd;
};

// 返回pair<ll, ll>: [最大流, 最大费用]
pll max_flow(int s, int t, vector<vector<edge> > &e)
{
    int n = e.size();
    vector<ll> dis(n + 1);
    vector<int> cur(n + 1);
    vector<bool> book(n + 1);
    ll cost = 0, ans = 0;
    function<bool()> spfa = [&]() -> bool
    {
        queue<int> q;
        rep(i, 0, n) dis[i] = LNF, cur[i] = 0;
        q.push(s);
        dis[s] = 0;
        book[s] = 1;
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            book[u] = 0;
            int m = e[u].size();
            rep(i, 0, m - 1)
            {
                auto &[v, rev, c, w, flow, fwd] = e[u][i];
                if (dis[v] > dis[u] + w && c > flow)
                {
                    dis[v] = dis[u] + w;
                    if (!book[v]) { q.push(v); book[v] = 1; }
                }
            }
        }
        return dis[t] != LNF;
    };
    function<ll(int, ll)> dfs = [&](int u, ll flow) -> ll
    {
        if (u == t) return flow;
        ll now = flow;
        book[u] = 1;
        int m = e[u].size();
        for (int i = cur[u]; i < m && now; ++i)
        {
            cur[u] = i;
            auto &[v, rev, c, w, edge_flow, fwd] = e[u][i];
            if (c <= edge_flow || book[v] || dis[v] != dis[u] + w) continue;
            ll f = dfs(v, min(now, c - edge_flow));
            if (f > 0)
            {
                e[u][i].flow += f;
                e[v][rev].flow -= f;
                now -= f;
                cost += w * f;
            }
        }
        book[u] = 0;
        return flow - now;
    };
    while (spfa()) ans += dfs(s, LNF);
    return {ans, cost};
};

// 加边, c表示流量, w表示费用
auto addedge = [&](int u, int v, ll c, ll w)
{
    e[u].pb({v, (int)e[v].size(), c, w, 0, true});
    e[v].pb({u, (int)e[u].size() - 1, 0, -w, 0, false});
};
