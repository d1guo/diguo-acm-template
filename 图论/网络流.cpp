最大流,同时也是最小割


如果需要记录最终每条边的流量, 需要在edge里加一项bool, 记录是否为正向边
最终, 每条边流量是当前的c

struct edge
{
    int v, rev;
    ll c;
};

要传引用,否则复杂度会加个n
INF和LNF别弄混了
ll max_flow(int s, int t, vector<vector<edge> > &e)
{
    int n = e.size();
    vector<int> dep(n + 1);
    vector<int> cur(n + 1);
    function<bool()> bfs = [&]() -> bool
    {
        queue<int> q;
        rep(i, 0, n) dep[i] = INF, cur[i] = 0;
        q.push(s);
        dep[s] = 1;
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            int m = e[u].size();
            rep(i, 0, m - 1)
            {
                auto [v, rev, c] = e[u][i];
                if (dep[v] == INF && c)
                {
                    dep[v] = dep[u] + 1;
                    q.push(v);
                }
            }
        }
        return dep[t] != INF;
    };
    function<ll(int, ll)> dfs = [&](int u, ll flow) -> ll
    {
        if (u == t) return flow;
        ll now = flow;
        int m = e[u].size();
        for (int i = cur[u]; i < m && now; ++i)
        {
            auto [v, rev, c] = e[u][i];
            if (!c || dep[v] != dep[u] + 1) continue;
            cur[u] = i;
            ll f = dfs(v, min(now, c));
            e[u][i].c -= f;
            e[v][rev].c += f;
            now -= f;
        }
        return flow - now;
    };
    ll ans = 0;
    while (bfs()) ans += dfs(s, LNF);
    return ans;
}

加边函数在solve内写
注意,反向边初始流量为0, 打完检查一遍,别打错了
auto addedge = [&](int u, int v, ll c)
{
    e[u].pb({v, (int)e[v].size(), c});
    e[v].pb({u, (int)e[u].size() - 1, 0});
};
