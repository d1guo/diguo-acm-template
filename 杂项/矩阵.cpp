struct Martix
{
    int n, m;//n:矩阵行数 m:矩阵列数
    int a[201][201];
    void clear()
    {
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j)
                a[i][j] = 0;
        n = m = 0;
    }
    Martix operator+(const Martix& b) const
    {
        Martix tmp;
        tmp.n = n; tmp.m = m;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                tmp.a[i][j] = a[i][j] + b.a[i][j];
        return tmp;
    }
    Martix operator-(const Martix& b) const
    {
        Martix tmp;
        tmp.n = n; tmp.m = m;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                tmp.a[i][j] = a[i][j] - b.a[i][j];
        return tmp;
    }
    Martix operator*(const Martix& b) const
    {
        Martix tmp;
        tmp.clear();
        tmp.n = n; tmp.m = b.m;
        for (int i = 1; i <= tmp.n; i++)
            for (int j = 1; j <= tmp.m; j++) 
                for (int k = 1; k <= m; k++)
                    tmp.a[i][j] += a[i][k] * b.a[k][j];
        return tmp;
    }
    Martix operator^(int x)const
    {
        Martix base, ans;
        base = *this; 
        ans.clear(); ans.m = ans.n = n;
        for (int i = 1; i <= n; i++) ans.a[i][i] = 1;
        if (x == 0) return ans;
        if (x == 1) return base;
        while (x)
        {
            if (x & 1) ans = ans * base;
            base = base * base;
            x >>= 1;
        }
        return ans;
    }
};