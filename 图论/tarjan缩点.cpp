const int GN = ;
vector<int> e[GN + 1];
int dfn[GN + 1], scc[GN + 1], ins[GN + 1], tot, low[GN + 1], scctot;
stack<int> stk;
void init()
{
    rep(i, 1, GN) dfn[i] = scc[i] = ins[i] = low[i] = 0;
    tot = scctot = 0;
}
void tarjan(int u)
{
    low[u] = dfn[u] = ++tot;
    stk.push(u);
    ins[u] = 1;
    for (auto x: e[u])
    {
        if (!dfn[x])
        {
            tarjan(x);
            low[u] = min(low[u], low[x]);
        }
        else if (ins[x]) low[u] = min(low[u], dfn[x]);
    }
    if (low[u] == dfn[u])
    {
        ++scctot;
        int v;
        do
        {
            v = stk.top();
            stk.pop();
            ins[v] = 0;
            scc[v] = scctot;
        } while (u != v);
    }
}
缩点: 
rep(i, 1, n)
{
    if (!dfn[i]) tarjan(i);
}