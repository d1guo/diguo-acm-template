//开盖即食: rep(i, 1, n) if (!dfn[i]) tarjan(i, 1);
//pt为1即为割点
//别忘初始化
vector<int> e[200001];
int dfn[200001], low[200001], tot;
bool pt[200001];
void tarjan(int p, bool root)
{ 
    int son = 0;
    dfn[p] = low[p] = ++tot;
    for (auto x: e[p])
    {
        if (!dfn[x])
        {
            ++son;
            tarjan(x, 0);
            low[p] = min(low[p], low[x]);
            if (!root && low[x] >= dfn[p]) pt[p] = 1;
        }
        else low[p] = min(low[p], dfn[x]);
    }
    if (root && son >= 2) return (void)(pt[p] = 1);
}
