int kmp[200001];
string s, S
//S为模板串， s为要匹配的字符串
void solve()
{
    cin >> S >> s;
    int N = S.length(), n = s.length();
    s = '?' + s, S = '?' + S;
    //此处j的含义是已经匹配的字符个数,i的含义是大串的下标
    //下标从1开始
    for (int i = 2, j = 0; i <= N; ++i)
    {
    	while (j && S[i] != S[j + 1]) j = kmp[j];
    	if (S[i] == S[j + 1]) ++j;
    	kmp[i] = j;
    }
    for (int i = 1, j = 0; i <= n; ++i)
    {
    	while (j && s[i] != S[j + 1]) j = kmp[j];
    	if (s[i] == S[j + 1]) ++j;
    	if (j == N)  j = kmp[j]; //说明匹配成功，开头idx为i - m + 1
    }
}