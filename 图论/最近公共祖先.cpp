const int GN = ;
vector<int> e[GN + 1];
int dep[GN + 1], sz[GN + 1], fa[GN + 1], son[GN + 1], top[GN + 1];
void dfs1(int u)
{
    sz[u] = 1, dep[u] = dep[fa[u]] + 1;
    int mx = 0;
    for (auto x: e[u])
    {
        if (x == fa[u]) continue;
        fa[x] = u;
        dfs1(x);
        sz[u] += sz[x];
        if (sz[x] > sz[son[u]]) son[u] = x;
    }
}
void dfs2(int u, int v)
{
    top[u] = v;
    if (son[u]) dfs2(son[u], v);
    for (auto x: e[u])
    {
        if (x == fa[u] || x == son[u]) continue;
        dfs2(x, x);
    }
}
void lcainit(int rt)
{
    dfs1(rt), dfs2(rt, rt);
}
int lca(int x, int y)
{
    while (top[x] != top[y])
    {
        if (dep[top[x]] > dep[top[y]])
            x = fa[top[x]];
        else
            y = fa[top[y]];
    }
    return (dep[x] < dep[y] ? x: y);
}