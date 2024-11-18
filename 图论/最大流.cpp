/*
v表示出边, rev表示反向边为e[v][rev]
c表示是网络流的最大流量, flow表示当前
fwd表示是是否是正向边, 便于统计
*/
struct edge
{
    int v, rev;
    ll c, flow;
    bool fwd;
};

/*
如果WA了，检查：
是否清空时候没清0, INF是否错设为LNF
*/
ll max_flow(int s, int t, vector<vector<edge>> &e)
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
                auto &[v, rev, c, flow, fwd] = e[u][i];
                if (dep[v] == INF && flow < c)
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
            auto &[v, rev, c, flow, fwd] = e[u][i];
            if (flow >= c || dep[v] != dep[u] + 1) continue;
            cur[u] = i;
            ll f = dfs(v, min(now, c - flow));
            e[u][i].flow += f;
            e[v][rev].flow -= f;
            now -= f;
        }
        return flow - now;
    };
    ll ans = 0;
    while (bfs()) ans += dfs(s, LNF);
    return ans;
}

//母式化加边
auto addedge = [&](int u, int v, ll c)
{
    e[u].pb({v, (int)e[v].size(), c, 0, true});
    e[v].pb({u, (int)e[u].size() - 1, 0, 0, false});
};
