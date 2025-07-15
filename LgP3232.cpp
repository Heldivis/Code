#include <bits/stdc++.h>
using namespace std;
#define re double
int read() {
  int res = 0;
  bool f = true;
  char ch = getchar();
  for (; ch > '9' || ch < '0'; ch = getchar())
    if (ch == '-') f = false;
  for (; ch <= '9' && ch >= '0'; ch = getchar())
    res = (res << 3) + (res << 1) + (ch ^ 48);
  return f ? res : ~res + 1;
}

const int N = 1060;

int n, m, d[N];
vector<int> g[N];
pair<int, int> edge[N * N];
re p[N][N], v[N], e[N];
re w[N * N];

void Gauss() {
  for (int i = 1; i <= n; i++) {
    int r = i;
    for (int j = i + 1; j <= n; j++)
      if (fabs(p[r][i]) < fabs(p[j][i])) r = j;
    if (r != i) swap(p[i], p[r]);
    re d = p[i][i];
    for (int j = i; j <= n + 1; j++) p[i][j] /= d;
    for (int j = i + 1; j <= n; j++) {
      re d = p[j][i];
      for (int k = i; k <= n + 1; k++) p[j][k] -= d * p[i][k];
    }
  }
  v[n] = p[n][n + 1];
  for (int i = n - 1; i; i--) {
    v[i] = p[i][n + 1];
    for (int j = i + 1; j <= n; j++) v[i] -= p[i][j] * v[j];
  }
}

signed main() {
  n = read(), m = read();
  for (int i = 1; i <= m; i++) {
    int x = read(), y = read();
    d[y]++, g[y].push_back(x);
    d[x]++, g[x].push_back(y);
    edge[i] = {x, y};
  }
  for (int x = 1; x <= n; x++) {
    p[x][x] = 1.0;
    for (int y : g[x])
      if (y != n) p[x][y] = -1.0 / d[y];
  }
  p[1][n + 1] = 1.00;
  Gauss();
  for (int i = 1; i <= m; i++) {
    w[i] = v[edge[i].first] / d[edge[i].first] * (edge[i].first != n) +
           v[edge[i].second] / d[edge[i].second] * (edge[i].second != n);
  }
  sort(w + 1, w + 1 + m, [](re x, re y) { return x > y; });
  re ans = 0.00;
  for (int i = 1; i <= m; i++) ans += i * w[i];
  printf("%.3lf", ans);
  return 0;
}
