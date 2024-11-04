int low[MAXN], dfn[MAXN], tot;
bool isbridge[MAXN];
vector<int> e[MAXN];
int cnt_bridge;
int lst[MAXN];
如果isbridge[i]为真
说明lst[i]和i间的边为桥
void tarjan(int u, int fa)
{
    lst[u] = fa;
    low[u] = dfn[u] = ++tot;
    for (auto x: e[u])
    {
        if (!dfn[x])
        {
            tarjan(v, u);
            low[u] = min(low[u], low[v]);
            if (low[v] > dfn[u])
            {
                isbridge[v] = true;
                ++cnt_bridge;
            }
        }
        else if (dfn[v] < dfn[u] && v != fa)
            low[u] = min(low[u], dfn[v]);
    }
}