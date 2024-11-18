struct edge
{
    int v, rev;
    ll c, flow;
    bool fwd;
};

ll max_flow(int s, int t, vector<vector<edge>> &e) {}

//先正常有源汇可行流
//然后删去真实汇点->源点的那条边, 同时统计那条边过去了多少流量, 这是可行流的流量
//接着, 对原网络不动, 再对真实源点->汇点跑一次最大流, 目的是"榨干"残余网络
//两答案相加即为最大流量
//为什么这回不考虑下界网络？因为下界网络实际的影响都已经由虚拟源点统计好了

void solve()
{
	int n = read(), m = read();
    vector<int> need(m + 1);
    rep(i, 1, m) need[i] = read();
    vector e(n + m + 5, vector<edge>());
    ll ans = 0;
    //p, q是真实, s, t是虚拟
    int p = n + m + 1, q = n + m + 2;
    int s = n + m + 3, t = n + m + 4;
    auto addedge = [&](int u, int v, ll c)
    {
        e[u].pb({v, (int)e[v].size(), c, 0, true});
        e[v].pb({u, (int)e[u].size() - 1, 0, 0, false});
    };
    vector<int> extra(n + m + 5);
    auto add = [&](int u, int v, int l, int r)
    {
        extra[u] -= l, extra[v] += l;
        addedge(u, v, r - l);
    };
    vector<int> c(n + 1), d(n + 1);
    rep(i, 1, n)
    {
        c[i] = read(), d[i] = read();
        add(p, i, 0, d[i]);
        rep(j, 1, c[i])
        {
            int t = read() + 1, l = read(), r = read();
            add(i, n + t, l, r);
        }
    }
    rep(i, 1, m) add(n + i, q, need[i], INF);
    int flowsum = 0;
    rep(i, 1, n + m + 2)
    {
        if (extra[i] > 0) addedge(s, i, extra[i]), flowsum += extra[i];
        else if (extra[i] < 0) addedge(i, t, -extra[i]);
    } 
    add(q, p, 0, INF);
    if (max_flow(s, t, e) != flowsum) return cout << -1 << '\n', void();
    //删去真实汇点->源点的那条边, 同时统计那条边过去了多少流量, 这是可行流的流量
    e[p].pop_back(), e[q].pop_back();
    //真实源点->汇点的流量, "榨干"过程
    //如果是最小流, 则由q源点向p源点跑最大流, 相当于是把不用的流退回去
    //答案即为 ans -= max_flow(q, p, e);
    ans += max_flow(p, q, e);
    cout << ans << '\n';
}
