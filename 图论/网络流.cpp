const int GN = ;
cnt初始为1
int cnt = 1;
int head[GN + 5], nxt[GN + 5], to[GN + 5], val[GN + 5];
int dep[GN + 5], cur[GN + 5];
int n;
void addedge(int u, int v, int w)
{
    nxt[++cnt] = head[u];
    head[u] = cnt;
    to[cnt] = v;
    val[cnt] = w;
}
bool bfs(int s, int t)
{
    rep(i, 0, n + 1) dep[i] = INF, cur[i] = head[i];
    queue<int> q;
    dep[s] = 1;
    q.push(s);
    while (!q.empty())
    {
        int tp = q.front();
        q.pop();
        for (int i = head[tp]; i; i = nxt[i])
        {
            int u = to[i], w = val[i];
            if (dep[u] == INF && w)
            {
                dep[u] = dep[tp] + 1;
                q.push(u);
            }
        }
    }
    return (dep[t] != INF);
}
int dfs(int x, int flow, int t)
{
    if (x == t) return flow;
    int rmn = flow;
    for (int i = cur[x]; i && rmn; i = nxt[i])
    {
        cur[x] = i;
        int u = to[i], w = val[i];
        if (!w || dep[u] != dep[x] + 1) continue;
        int c = dfs(u, min(w, rmn), t);
        val[i] -= c;
        val[i ^ 1] += c;
        rmn -= c;
    }
    return flow - rmn;
}
ll dinic(int s, int t)
{
	ll ans = 0;
	while (bfs(s, t)) ans += 1ll * dfs(s, INF, t);
	return ans;
}
加边时候别忘连反向边
u = read(), v = read();
addedge(u, v, 1);
addedge(v, u, 0);
超级源点/汇点
记得判断边的时候要看是不是连接超级源点/超级汇点的边，是的话就无视
rep(i, 1, m)
{
    addedge(0, i, 1);
    addedge(i, 0, 0);
}
rep(i, m + 1, n)
{
    addedge(i, n + 1, 1);
    addedge(n + 1, i, 0);
}
