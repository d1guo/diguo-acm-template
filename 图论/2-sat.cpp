//要开2倍大小, 分别代表成立和不成立
//x->y，则x朝y连边
const int GN = 2 * ;
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
//传n进去，不用乘2
bool two_set(int n)
{
    rep(i, 1, 2 * n)
    {
        if (!dfn[i]) tarjan(i);
    }
    rep(i, 1, n)
    {
        if (scc[i] == scc[i + n]) return 0;
    }
    return 1;
}