struct edge
{
    int v, rev;
    ll c, w, flow;
    bool fwd;
};

//此为费用流
pll max_flow(int s, int t, vector<vector<edge> > &e) {};

//比起有源上下界可行流, 就是把最大流改为了费用流 
void solve()
{
	int n = read();
    //p, q是真实源/汇点
    //s, t是虚拟源/汇点
    int p = 1, q = n + 1;
    int s = n + 2, t = n + 3;
    ll ans = 0;
    vector e(n + 4, vector<edge>());
    auto addedge = [&](int u, int v, ll c, ll w)
    {
        e[u].pb({v, (int)e[v].size(), c, w, 0, true});
        e[v].pb({u, (int)e[u].size() - 1, 0, -w, 0, false});
    };
    vector<ll> extra(n + 4);
    //上下界
    auto add = [&](int u, int v, ll l, ll r, ll w)
    {
        ans += l * w;
        extra[u] -= l, extra[v] += l;
        addedge(u, v, r - l, w);
    };
    rep(i, 1, n)
    {
        int t = read();
        while (t--)
        {
            int u = read();
            ll w = read();
            add(i, u, 1, LNF, w);
        }
    }
    rep(i, 1, n) add(i, q, 0, LNF, 0);
    add(q, p, 0, LNF, 0);
    ll flowsum = 0;
    rep(i, 1, n + 1)
    {
        if (extra[i] > 0) addedge(s, i, extra[i], 0), flowsum += extra[i];
        else if (extra[i] < 0) addedge(i, t, -extra[i], 0);
    }
    cout << max_flow(s, t, e).second + ans;
}
