#include <cstdio>

const int N = 1100;
int w, b;
bool vis[N][N];
double f[N][N];
double Fn(int w, int b) {
  if (vis[w][b]) return f[w][b];
  vis[w][b] = true;
  if (w == 0) return f[w][b] = 0.0;
  if (b <= 1) return f[w][b] = 1.0 * w / (w + b);
  f[w][b] = 1.0 * w / (w + b);
  if (b >= 2) f[w][b] += Fn(w - 1, b - 2) * b / (w + b) * (b - 1) / (w + b - 1) * w / (w + b - 2);  
  if (b >= 3) f[w][b] += Fn(w, b - 3) * b / (w + b) * (b - 1) / (w + b - 1) * (b - 2) / (w + b - 2);
  return f[w][b];
}

int main() {
  scanf("%d%d", &w, &b);
  printf("%.15lf", Fn(w, b));
  return 0;
}
