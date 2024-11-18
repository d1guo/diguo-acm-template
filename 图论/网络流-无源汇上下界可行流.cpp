struct edge
{
    int v, rev, idx;
    ll c, flow;
    bool fwd;
};

//同最大流
ll max_flow(int s, int t, vector<vector<edge>> &e) {}

void solve()
{
	int n = read(), m = read();
    vector e(n + 2, vector<edge>());
    //因为要存idx, 所以加边
    auto addedge = [&](int u, int v, ll c, int idx)
    {
        e[u].pb({v, (int)e[v].size(), idx, c, 0, true});
        e[v].pb({u, (int)e[u].size() - 1, idx, 0, 0, false});
    };
    //extra表示(入边流量-出边流量)
    vector<int> extra(n + 1), ans(m + 1);
    //如果计算x->y的流量, 需要加上x->y的l
    rep(i, 1, m)
    {
        int u = read(), v = read(), l = read(), r = read();
        addedge(u, v, r - l, i);
        extra[u] -= l;
        extra[v] += l;
        ans[i] += l;
    }
    //不要重！不要重！不要重！
    //e大小开够! e大小开够! e大小开够!
    int s = 0, t = n + 1;
    int flowsum = 0;
    //如果入边多, 要源点朝其连边, 反之亦然
    //同时需要记录源点出边/汇点入边中的一个
    rep(i, 1, n)
    {
        if (extra[i] > 0) addedge(s, i, extra[i], 0), flowsum += extra[i];
        else if (extra[i] < 0) addedge(i, t, -extra[i], 0);
    }
    //如果源汇点不是满流, 说明不存在可行流
    if (max_flow(s, t, e) != flowsum) return cout << "NO", void();
    cout << "YES\n";
    //统计总流量
    rep(i, 1, n)
    {
        for (auto &[v, rev, idx, c, flow, fwd]: e[i])
        {
            if (fwd) ans[idx] += flow;
        }
    }
    rep(i, 1, m) cout << ans[i] << '\n';
}
