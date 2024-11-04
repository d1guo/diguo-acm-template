vector<int> f(n + 1);
vector<int> lst(26);
rep(i, 1, n)
{
    if (!lst[s[i] - 'a']) f[i] = f[i - 1] * 2 + 1;
    else f[i] = 2 * f[i - 1] - f[lst[s[i] - 'a'] - 1];
    lst[s[i] - 'a'] = i;
}