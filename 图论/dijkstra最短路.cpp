bool vis[200001];
int dis[200001];
vector<pii> e[200001];
//first为目标, second为距离
struct node
{
    int to, w;
    bool operator < (const node &x) const
    {
        return x.w < w;
    }
};
priority_queue <node> pq;
//下传n和起始点,重置写好了
void dijkstra(int n, int s)
{
    priority_queue <node> pq;
    for (int i = 1; i <= n; i++)
    {
        dis[i] = INF;
        vis[i] = 0;
    }
    pq.push((node){s, 0});
    dis[s] = 0;
    while (!pq.empty())
    {
        node tmp = pq.top();
        pq.pop();
        int u = tmp.to, w = tmp.w;
        if (vis[u])
        {
            continue;
        }
        vis[u] = 1;
        for (auto [x, y]: e[u])
        {
            if (dis[x] > y + w)
            {
                dis[x] = y + w;
                if (!vis[x]) pq.push((node){x, dis[x]});
            }
        }
    }
}