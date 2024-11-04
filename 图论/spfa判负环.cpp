int dis[200001], tim[200001];
bool vis[200001];
vector<pii> e[200001];
//first存u, second存w
//传源点和n, 有返回1, 没有返回0
bool SPFA(int s, int n)
{
    rep(i, 0, n) dis[i] = INF, vis[i] = 0, tim[i] = 0;
    queue <int> q;
    q.push(s), vis[s] = 1, dis[s] = 0;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        vis[u] = 0;
        for (auto [x, y]: e[u])
        {
            if (dis[x] > y + dis[u])
            {
                dis[x] = y + dis[u];
                if (!vis[x])
                {
                    if (++tim[x] >= n) return 1;
                    vis[x] = 1;
                    q.push(x);
                }
            }
        }
    }
    return 0;
};