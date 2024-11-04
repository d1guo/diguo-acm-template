rep(k, 1, n)
    rep(i, 1, n)
        rep(j, 1, n)
      f[i][j] = min(f[i][j], f[i][k] + f[k][j]);