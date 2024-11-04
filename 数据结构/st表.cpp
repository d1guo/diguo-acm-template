const int LGN = ;
int lg2[LGN + 1];
//don't forget init value of log2 and calculate function
void lginit()
{
    rep(i, 2, LGN) lg2[i] = lg2[i / 2] + 1;
}
struct MAXST
{
    vector<vector<ll>> st;
    ll cal(ll x, ll y)
    {
        ll ret = ;
        return ret;
    }
    void init(vector<int> a, int n)
    {
        st.resize(n + 1);
        rep(i, 0, n) st[i].resize(31), st[i][0] = a[i];
        rep(i, 1, 30) for (int j = 1; j + (1 << i) - 1 <= n; ++j)
        st[j][i] = cal(st[j][i - 1], st[j + (1 << (i - 1))][i - 1]);
    }
    void init(vector<ll> a, int n)
    {
        st.resize(n + 1);
        rep(i, 0, n) st[i].resize(31), st[i][0] = a[i];
        rep(i, 1, 30) for (int j = 1; j + (1 << i) - 1 <= n; ++j)
        st[j][i] = cal(st[j][i - 1], st[j + (1 << (i - 1))][i - 1]);
    }
    void init(int *a, int n)
    {
        st.resize(n + 1);
        rep(i, 0, n) st[i].resize(31), st[i][0] = a[i];
        rep(i, 1, 30) for (int j = 1; j + (1 << i) - 1 <= n; ++j)
        st[j][i] = cal(st[j][i - 1], st[j + (1 << (i - 1))][i - 1]);
    }
     void init(ll *a, int n)
    {
        st.resize(n + 1);
        rep(i, 0, n) st[i].resize(31), st[i][0] = a[i];
        rep(i, 1, 30) for (int j = 1; j + (1 << i) - 1 <= n; ++j)
        st[j][i] = cal(st[j][i - 1], st[j + (1 << (i - 1))][i - 1]);
    }
    ll query(int l, int r)
    {
        int s = lg2[r - l + 1];
        return cal(st[l][s], st[r - (1 << s) + 1][s]);
    }
};