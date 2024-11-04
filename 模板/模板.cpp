#include <bits/stdc++.h>
using namespace std;

#define MULTIINPUT 1

#ifdef ONLINE_JUDGE
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#else
#include <dbg.h>
#endif

#define mkp make_pair
#define pii pair<int, int>
#define pil pair<int, long long>
#define pli pair<long long, int>
#define pll pair<long long, long long>
#define ll long long
#define ull unsigned long long
#define pb push_back
#define rep(name, base, limit) for(int name = base; name <= limit; ++name)
#define per(name, base, limit) for(int name = base; name >= limit; --name)
#define lowbit(x) ((x) & -(x))
#define ls(p) ((p) << 1)
#define rs(p) ((p) << 1 | 1)
const int INF = 0x3f3f3f3f;
const long long LNF = 0x3f3f3f3f3f3f3f3f;

inline long long read()
{
    long long x=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
    return x*f;
}

void solve()
{
	
}

//left: mid = l + r, pass: r = mid, else: l = mid + 1
//right: mid = l + r + 1, pass: l = mid, else: r = mid - 1

signed main()
{
    #if MULTIINPUT
    int _t = read();
    while (_t--)
    {
        #endif
        solve();
        #if MULTIINPUT
        if (_t) putchar('\n');
    }
    #endif
    return 0;
}