struct Q
{
    int idx;
    //This is every query
    //complete other information
    //to apply in calculating of answer
    //(get_ans)
};
const int GN = ;
vector<int> e[GN + 1];
int dfn[GN + 1], idfn[GN + 1], sz[GN + 1], son[GN + 1], ans[GN + 1], tot;
vector<Q> query[GN + 1];
void dfs1(int u, int fa)
{
    dfn[u] = ++tot;
    idfn[tot] = u;
    sz[u] = 1;
    for (auto x: e[u])
    {
        if (x == fa) continue;
        dfs1(x, u);
        sz[u] += sz[x];
        if (sz[son[u]] < sz[x]) son[u] = x;
    }
    
}
void add(int u)
{

}
void del(int u)
{

}
void getans(Q u)
{

}
void dfs2(int u, int fa)
{
    for (auto x: e[u])
    {
        if (x == fa || x == son[u]) continue;
        dfs2(x, u);
        for (int i = dfn[x]; i <= dfn[x] + sz[x] - 1; ++i)
            del(idfn[i]);
    }
    if (son[u]) dfs2(son[u], u);
    for (auto x: e[u])
    {
        if (x == fa || x == son[u]) continue;
        for (int i = dfn[x]; i <= dfn[x] + sz[x] - 1; ++i)
            add(idfn[i]);
    }
    add(u);
    for (auto x: query[u])
        ans[x.idx] = getans(x);
}